#include "platform/window.h"

#include "core/logger.h"
#include "subsystems/input.h"
#include <xcb/xproto.h>
#include <cstring>

#if defined (DPLATFORM_LINUX)

#include <xcb/xcb.h>
#include <xcb/xcb_keysyms.h>

#include <print>

namespace Lord::platform {

struct Kbd_State {
  u8 global_repeat[32];
  u8 repeat_bits[32];

  xcb_keysym_t keysym_table[256];
};

struct Internal_State {
  bool isVSync;
  u32 width;
  u32 height;
  std::string title;

  xcb_connection_t* connection;
  xcb_screen_t* screen;
  xcb_window_t window;
  i32 screen_count;
  xcb_atom_t wm_delete_win;
  xcb_atom_t wm_protocols;

  Kbd_State kbd_state;
};

PlatformWindow::PlatformWindow(const WindowProps& props) {
  m_state.internal_state = CreateScope<Internal_State>();

  auto internal_state = m_state.internal_state.get();
  internal_state->isVSync = false;
  internal_state->width = props.width;
  internal_state->height = props.height;
  internal_state->title = std::move(props.title);
}

PlatformWindow::~PlatformWindow() {
  shutdown();
}

u32 PlatformWindow::getWidth() const {
  return m_state.internal_state->width;
}

u32 PlatformWindow::getHeight() const {
  return m_state.internal_state->height;
}

void PlatformWindow::setVSync(bool enabled) {
  return;
}

bool PlatformWindow::isVSync() const {
  return m_state.internal_state->isVSync;
}

void* PlatformWindow::getNativeWindow() const {
  return nullptr;
}

ErrorOr<void, std::string> PlatformWindow::run() {
  auto internal_state = m_state.internal_state.get();

  DINFO("Platform Window X11 Intializaiting...");
  internal_state->connection = xcb_connect(nullptr, &internal_state->screen_count);
  if (xcb_connection_has_error(internal_state->connection) != 0) 
    return Error("Failed to create xcb connection");

  xcb_key_symbols_t* keysyms = xcb_key_symbols_alloc(internal_state->connection);
  for (u32 keycode = 8; keycode < 256; ++keycode)
    internal_state->kbd_state.keysym_table[keycode] = xcb_key_symbols_get_keysym(keysyms, keycode, 0);
  xcb_key_symbols_free(keysyms);

  const xcb_setup_t* setup = xcb_get_setup(internal_state->connection);
  xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);
  for (i32 i = 0; i < internal_state->screen_count; ++i) {
    xcb_screen_next(&iter);
  }
  internal_state->screen = iter.data;

  DINFO("Informations of screen {}:", internal_state->screen->root);
  DINFO( "width.........: {}", internal_state->screen->width_in_pixels);
  DINFO( "height........: {}", internal_state->screen->height_in_pixels);
  DDEBUG("white pixel...: {}", internal_state->screen->white_pixel);
  DDEBUG("black pixel...: {}", internal_state->screen->black_pixel);

  internal_state->window = xcb_generate_id(internal_state->connection);
  if (internal_state->window == -1) 
    return Error("Failed to generate id for window");

  u32 event_mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
  u32 event_values =  XCB_EVENT_MASK_KEY_PRESS |
                      XCB_EVENT_MASK_KEY_RELEASE |
                      XCB_EVENT_MASK_BUTTON_PRESS |
                      XCB_EVENT_MASK_BUTTON_RELEASE |
                      XCB_EVENT_MASK_ENTER_WINDOW |
                      XCB_EVENT_MASK_LEAVE_WINDOW |
                      XCB_EVENT_MASK_POINTER_MOTION |
                      XCB_EVENT_MASK_BUTTON_1_MOTION | // left 
                      XCB_EVENT_MASK_BUTTON_2_MOTION | // middle
                      XCB_EVENT_MASK_BUTTON_3_MOTION | // right
                      XCB_EVENT_MASK_BUTTON_4_MOTION | // scroll up
                      XCB_EVENT_MASK_BUTTON_5_MOTION | // scroll down
                      XCB_EVENT_MASK_BUTTON_MOTION |
                      XCB_EVENT_MASK_EXPOSURE |
                      XCB_EVENT_MASK_VISIBILITY_CHANGE |
                      XCB_EVENT_MASK_STRUCTURE_NOTIFY |
                      XCB_EVENT_MASK_FOCUS_CHANGE |
                      XCB_EVENT_MASK_PROPERTY_CHANGE;

  u32 value_list[2] = {internal_state->screen->black_pixel, event_values};
  xcb_create_window(internal_state->connection, 
                    XCB_COPY_FROM_PARENT,
                    internal_state->window,
                    internal_state->screen->root,
                    0, 0, 
                    internal_state->width, 
                    internal_state->height, 
                    10, 
                    XCB_WINDOW_CLASS_INPUT_OUTPUT, 
                    internal_state->screen->root_visual, 
                    event_mask, 
                    value_list);

  xcb_map_window(internal_state->connection, internal_state->window);

  xcb_intern_atom_cookie_t utf8_string_cookie = xcb_intern_atom(internal_state->connection, 0, 11, "UTF8_STRING");
  xcb_intern_atom_reply_t* utf8_string_reply = xcb_intern_atom_reply(internal_state->connection, utf8_string_cookie, nullptr);

  xcb_intern_atom_cookie_t net_wm_name_cookie = xcb_intern_atom(internal_state->connection, 0, 12, "_NET_WM_NAME");
  xcb_intern_atom_reply_t* net_wm_name_rely = xcb_intern_atom_reply(internal_state->connection, net_wm_name_cookie, nullptr);

  xcb_change_property(internal_state->connection, 
                      XCB_PROP_MODE_REPLACE, 
                      internal_state->window, 
                      XCB_ATOM_WM_NAME,
                      utf8_string_reply->atom,
                      8,
                      internal_state->title.size(),
                      internal_state->title.c_str());
  xcb_change_property(internal_state->connection, 
                      XCB_PROP_MODE_REPLACE, 
                      internal_state->window, 
                      net_wm_name_rely->atom,
                      utf8_string_reply->atom,
                      8,
                      internal_state->title.size(),
                      internal_state->title.c_str());

  free(utf8_string_reply);
  free(net_wm_name_rely);

  xcb_intern_atom_cookie_t wm_delete_cookie = xcb_intern_atom(internal_state->connection, 0, 16, "WM_DELETE_WINDOW");
  xcb_intern_atom_reply_t* wm_delete_reply = xcb_intern_atom_reply(internal_state->connection, wm_delete_cookie, nullptr);

  xcb_intern_atom_cookie_t wm_protocol_cookie = xcb_intern_atom(internal_state->connection, 0, 12, "WM_PROTOCOLS");
  xcb_intern_atom_reply_t* wm_protocol_reply = xcb_intern_atom_reply(internal_state->connection, wm_protocol_cookie, nullptr);

  xcb_change_property(internal_state->connection, 
                      XCB_PROP_MODE_REPLACE, 
                      internal_state->window, 
                      wm_protocol_reply->atom,
                      XCB_ATOM_ATOM,
                      32,
                      1,
                      &wm_delete_reply->atom);

  internal_state->wm_delete_win = wm_delete_reply->atom;
  internal_state->wm_protocols = wm_protocol_reply->atom;

  free(wm_delete_reply);
  free(wm_protocol_reply);

  xcb_get_keyboard_control_cookie_t wm_kbd_control_cookie = xcb_get_keyboard_control(internal_state->connection);
  xcb_get_keyboard_control_reply_t* wm_kbd_control_reply = xcb_get_keyboard_control_reply(internal_state->connection, wm_kbd_control_cookie, nullptr);

  memcpy(internal_state->kbd_state.global_repeat, wm_kbd_control_reply->auto_repeats, 32);
  memcpy(internal_state->kbd_state.repeat_bits, wm_kbd_control_reply->auto_repeats, 32);

  free(wm_kbd_control_reply);

  xcb_flush(internal_state->connection);
  return {};
}

bool PlatformWindow::pumpMessages() {
  auto internal_state = m_state.internal_state.get();
  if (!internal_state)
    return true;

  bool quit_flag = false;

  xcb_generic_event_t* next_event = nullptr;
  xcb_generic_event_t* event = xcb_poll_for_event(internal_state->connection);

  while (event) {
    const uint8_t type = event->response_type & ~0x80;

    switch (type) {
      case XCB_KEY_RELEASE: {
        auto* e = reinterpret_cast<xcb_key_press_event_t*>(event);

        if (!next_event)
          next_event = xcb_poll_for_event(internal_state->connection);

        bool is_repeat = false;

        if (next_event) {
          uint8_t nt = next_event->response_type & ~0x80;
          if (nt == XCB_KEY_PRESS) {
            auto* nk = reinterpret_cast<xcb_key_press_event_t*>(next_event);

            if (nk->detail == e->detail && nk->time == e->time) {
              is_repeat = true;
            }
          }
        }

        if (is_repeat) {
          xcb_keysym_t ks =
            internal_state->kbd_state.keysym_table[e->detail];

          if (ks <= 0xff)
            subsystem::Input::processKey((Keys)ks, true);
          else 
            YET_TO_IMPLEMENT();

          free(event);
          free(next_event);
          next_event = nullptr;

          event = xcb_poll_for_event(internal_state->connection);
          continue;
        }

        xcb_keysym_t ks =
          internal_state->kbd_state.keysym_table[e->detail];

        if (ks <= 0xff)
          subsystem::Input::processKey((Keys)ks, false);
        else 
          YET_TO_IMPLEMENT();
      } break;

      case XCB_KEY_PRESS: {
        auto* e = reinterpret_cast<xcb_key_press_event_t*>(event);

        xcb_keysym_t ks =
          internal_state->kbd_state.keysym_table[e->detail];

        if (ks <= 0xff)
          subsystem::Input::processKey((Keys)ks, true);
        else 
          YET_TO_IMPLEMENT();
      } break;

      case XCB_BUTTON_PRESS:
      case XCB_BUTTON_RELEASE: {
        xcb_button_press_event_t* mouse_event = reinterpret_cast<xcb_button_press_event_t*>(event);
        bool pressed = event->response_type == XCB_BUTTON_PRESS;

        i8 delta = 0;
        subsystem::MouseButton button = subsystem::MOUSE_BUTTON_MAX;
        switch (mouse_event->detail) {
          case XCB_BUTTON_INDEX_1: {
            button = subsystem::MOUSE_BUTTON_LEFT;
          } break;
          case XCB_BUTTON_INDEX_2: {
            button = subsystem::MOUSE_BUTTON_MIDDLE;
          } break;
          case XCB_BUTTON_INDEX_3: {
            button = subsystem::MOUSE_BUTTON_RIGHT;
          } break;
          case XCB_BUTTON_INDEX_4: {
            delta = 1;
          } break;
          case XCB_BUTTON_INDEX_5: {
            delta = -1;
          } break;
        }

        if (button != subsystem::MOUSE_BUTTON_MAX)
          subsystem::Input::processButton(button, pressed);
        else if (delta != 0) 
            subsystem::Input::processMouseWheel(delta);
      } break;

      case XCB_MOTION_NOTIFY: {
        xcb_motion_notify_event_t* motion_event = reinterpret_cast<xcb_motion_notify_event_t*>(event);
        subsystem::Input::processMouseMove(motion_event->event_x, motion_event->event_y);
      } break;

      case XCB_CLIENT_MESSAGE: {
        auto* cm = reinterpret_cast<xcb_client_message_event_t*>(event);
        if (cm->data.data32[0] == internal_state->wm_delete_win)
          quit_flag = true;
      } break;

    } 

    free(event);

    if (next_event) {
      event = next_event;
      next_event = nullptr;
    } else {
      event = xcb_poll_for_event(internal_state->connection);
    }
  }

  subsystem::Input::inputUpdate();
  return !quit_flag;
}



void PlatformWindow::shutdown() {
  if (!m_state.internal_state) return;
  auto internal_state = m_state.internal_state.get();

  if (internal_state->window) xcb_destroy_window(internal_state->connection, internal_state->window);
  if (internal_state->connection) xcb_disconnect(internal_state->connection);
}

}


#else
# error "Platform is not supported."
#endif

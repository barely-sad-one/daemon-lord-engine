#include "subsystems/input.h"

#include "subsystems/events.h"

namespace Lord::subsystem {

Input::Input()
  : m_allow_repeat(true) { }


void Input::setKeyRepeat(bool enable) {
  auto& self = get();
  self.m_allow_repeat = true;
}

bool Input::isKeyDown(Keys key) {
  auto& self = get();
  return self.m_kbd_state_curr.keys[key];
}

bool Input::isKeyUp(Keys key) {
  auto& self = get();
  return self.m_kbd_state_curr.keys[key] == false;
}

bool Input::wasKeyDown(Keys key) {
  auto& self = get();
  return self.m_kbd_state_prev.keys[key];
}

bool Input::wasKeyUp(Keys key) {
  auto& self = get();
  return self.m_kbd_state_prev.keys[key] == false;
}

void Input::processKey(Keys key, bool pressed) {
  auto& self = get();
  
  bool was_down = self.m_kbd_state_curr.keys[key];
  bool is_repeat = pressed && was_down;
  bool changed = ( was_down != pressed );

  if ((self.m_allow_repeat && is_repeat) || changed) {
    self.m_kbd_state_curr.keys[key] = pressed;

    EventContext context;
    context.data.u16[0] = key;
    context.data.u16[1] = is_repeat ? 1 : 0;
    EventBus::fire(pressed ? EVENT_CODE_KEY_PRESSED : EVENT_CODE_KEY_RELEASED, nullptr, &context);
  }
}


bool Input::isButtonDown(MouseButton button) {
  auto& self = get();
  return self.m_mouse_state_curr.buttons[button];
}

bool Input::isButtonUp(MouseButton button) {
  auto& self = get();
  return self.m_mouse_state_curr.buttons[button] == false;
}

bool Input::wasButtonDown(MouseButton button) {
  auto& self = get();
  return self.m_mouse_state_prev.buttons[button];
}

bool Input::wasButtonUp(MouseButton button) {
  auto& self = get();
  return self.m_mouse_state_prev.buttons[button] == false;
}

bool Input::isButtonDragging(MouseButton button) {
  auto& self = get();
  return self.m_mouse_state_prev.dragging[button];
}

void Input::getCurrMousePosition(i32* x, i32* y) {
  auto& self = get();
  *x = static_cast<i32>(self.m_mouse_state_curr.x);
  *y = static_cast<i32>(self.m_mouse_state_curr.y);
}

void Input::getPrevMousePosition(i32* x, i32* y) {
  auto& self = get();
  *x = static_cast<i32>(self.m_mouse_state_prev.x);
  *y = static_cast<i32>(self.m_mouse_state_prev.y);
}

void Input::processButton(MouseButton button, bool pressed) {
  auto& self = get();
  if (self.m_mouse_state_curr.buttons[button] != pressed) {
    self.m_mouse_state_curr.buttons[button] = pressed;

    EventContext context;
    context.data.u16[0] = button;
    context.data.u16[1] = self.m_mouse_state_curr.x;
    context.data.u16[2] = self.m_mouse_state_curr.y;
    EventBus::fire(pressed ? EVENT_CODE_BUTTON_PRESSED : EVENT_CODE_BUTTON_RELEASED, nullptr, &context);
  }

  if (!pressed) {
    if (self.m_mouse_state_curr.dragging[button]) {
      self.m_mouse_state_curr.dragging[button] = false;
      // DTRACE("Mouse drag ended at: x: {}, y: {}, button: {}", 
      //        self.m_mouse_state_curr.x,
      //        self.m_mouse_state_curr.y,
      //        static_cast<i32>(button));

      EventContext context;
      context.data.u16[0] = button;
      context.data.u16[1] = self.m_mouse_state_curr.x;
      context.data.u16[2] = self.m_mouse_state_curr.y;
      EventBus::fire(EVENT_CODE_MOUSE_DRAG_END, nullptr, &context);
    } else {
      EventContext context;
      context.data.u16[0] = button;
      context.data.u16[1] = self.m_mouse_state_curr.x;
      context.data.u16[2] = self.m_mouse_state_curr.y;
      EventBus::fire(EVENT_CODE_BUTTON_CLICKED, nullptr, &context);
    }
  }
}

void Input::processMouseMove(i16 x, i16 y) {
  auto& self = get();

  if (self.m_mouse_state_curr.x != x || self.m_mouse_state_curr.y != y) {
    self.m_mouse_state_curr.x = x;
    self.m_mouse_state_curr.y = y;

    EventContext context;
    context.data.i16[0] = x;
    context.data.i16[1] = y;
    EventBus::fire(EVENT_CODE_MOUSE_MOVED, nullptr, &context);

    for (u16 i = 0; i < MOUSE_BUTTON_MAX; ++i) {
      if (self.m_mouse_state_curr.buttons[i]) {
        if (!self.m_mouse_state_prev.dragging[i] && !self.m_mouse_state_curr.dragging[i]) {
          self.m_mouse_state_curr.dragging[i] = true;

          EventContext drag_context;
          context.data.i16[0] = self.m_mouse_state_curr.x;
          context.data.i16[1] = self.m_mouse_state_curr.y;
          context.data.i16[2] = static_cast<i16>(i);
          EventBus::fire(EVENT_CODE_MOUSE_DRAG_BEGIN, nullptr, &drag_context);
        } else if (self.m_mouse_state_curr.dragging[i]) {
          EventContext drag_context;
          context.data.i16[0] = self.m_mouse_state_curr.x;
          context.data.i16[1] = self.m_mouse_state_curr.y;
          context.data.i16[2] = static_cast<i16>(i);
          EventBus::fire(EVENT_CODE_MOUSE_DRAGGED, nullptr, &drag_context);
        }
      }
    }
  }
}

void Input::processMouseWheel(i8 z_delta) {
  EventContext context;
  context.data.i8[0] = z_delta;
  EventBus::fire(EVENT_CODE_MOUSE_WHEEL, nullptr, &context);
}

void Input::inputUpdate() {
  auto& self = get();
  self.m_kbd_state_prev = self.m_kbd_state_curr;
  self.m_mouse_state_prev = self.m_mouse_state_curr;
}

}

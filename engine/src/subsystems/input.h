#pragma once

#include "defines.h"

#include "platform/input_types.h"

using namespace Lord::platform;
namespace Lord::subsystem {

enum MouseButton {
  MOUSE_BUTTON_LEFT,
  MOUSE_BUTTON_RIGHT,
  MOUSE_BUTTON_MIDDLE,
  MOUSE_BUTTON_MAX,
};

class DAPI Input {
public:
  static void setKeyRepeat(bool enable);

  static bool isKeyDown(Keys key);
  static bool isKeyUp(Keys key);
  static bool wasKeyDown(Keys key);
  static bool wasKeyUp(Keys key);

  static void processKey(Keys key, bool pressed);

  static bool isButtonDown(MouseButton button);
  static bool isButtonUp(MouseButton button);
  static bool wasButtonDown(MouseButton button);
  static bool wasButtonUp(MouseButton button);
  static bool isButtonDragging(MouseButton button);
  static void getCurrMousePosition(i32* x, i32* y);
  static void getPrevMousePosition(i32* x, i32* y);

  static void processButton(MouseButton button, bool pressed);
  static void processMouseMove(i16 x, i16 y);
  static void processMouseWheel(i8 z_delta);

  static void inputUpdate();

private:
  Input();
  ~Input() = default;

  Input(const Input&) = delete;
  Input& operator=(const Input&) = delete;

  static ALWAYS_INLINE Input& get() {
    static Input instance;
    return instance;
  }

  struct KeyboardState {
    bool keys[256];
  };

  struct MouseState {
    i16 x;
    i16 y;
    bool buttons[MOUSE_BUTTON_MAX];
    bool dragging[MOUSE_BUTTON_MAX];
  };

  KeyboardState m_kbd_state_prev;
  KeyboardState m_kbd_state_curr;
  MouseState    m_mouse_state_prev;
  MouseState    m_mouse_state_curr;

  bool m_allow_repeat;
};


}

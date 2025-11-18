#include "defines.h"
#include <core/window.h>
#include <core/logger.h>
#include <assertions.h>
#include <subsystems/events.h>
#include <core/application.h>
#include <entry.h>

#include <print>

void key_press(void* sender, void* listener, Lord::subsystem::EventContext* context) {
  std::println("Key is pressed: {}, is_repeat: {}", context->data.u16[0], context->data.u16[1]);
}

void key_release(void* sender, void* listener, Lord::subsystem::EventContext* context) {
  std::println("Key is released: {}, is_repeat: {}", context->data.u16[0], context->data.u16[1]);
}

void button_press(void* sender, void* listener, Lord::subsystem::EventContext* context) {
  std::println("Button is pressed: {}:{}:{}", context->data.u16[0], context->data.u16[1], context->data.u16[2]);
}

void button_release(void* sender, void* listener, Lord::subsystem::EventContext* context) {
  std::println("Button is released: {}:{}:{}", context->data.i16[0], context->data.i16[1], context->data.i16[2]);
}

void wheel(void* sender, void* listener, Lord::subsystem::EventContext* context) {
  std::println("Wheel z-delta: {}", context->data.i8[0]);
}

void app_quit(void* sender, void* listener, Lord::subsystem::EventContext* context) {
  std::println("Application Closed!");
}

// int main() {
//   Lord::Scope<Lord::Window> win = Lord::Window::create();
//
//   DFATAL("This is the value of pi: {}", 3.14);
//   DERROR("This is the value of pi: {}", 3.14);
//   DWARN("This is the value of pi: {}", 3.14);
//   DINFO("This is the value of pi: {}", 3.14);
//   DDEBUG("This is the value of pi: {}", 3.14);
//   DTRACE("This is the value of pi: {}", 3.14);
//
//   Lord::subsystem::EventBus::registerEvent<void>(Lord::subsystem::EVENT_CODE_KEY_PRESSED, nullptr, key_press);
//   Lord::subsystem::EventBus::registerEvent<void>(Lord::subsystem::EVENT_CODE_KEY_RELEASED, nullptr, key_release);
//   Lord::subsystem::EventBus::registerEvent<void>(Lord::subsystem::EVENT_CODE_BUTTON_PRESSED, nullptr, button_press);
//   Lord::subsystem::EventBus::registerEvent<void>(Lord::subsystem::EVENT_CODE_BUTTON_RELEASED, nullptr, button_release);
//   Lord::subsystem::EventBus::registerEvent<void>(Lord::subsystem::EVENT_CODE_MOUSE_WHEEL, nullptr, wheel);
//   // Lord::subsystem::EventBus::registerEvent<void>(Lord::subsystem::EVENT_CODE_APPLICATION_QUIT, nullptr, app_quit);
//
//   // auto res = win->run();
//   // if (!res) [[ unlikely ]]  {
//   //   DFATAL(res.error());
//   //   return 1;
//   // }
//   //
//   // bool is_running = true;
//   // while (is_running) {
//   //   is_running = win->pumpMessages();
//   // }
//
//   Lord::Application app;
//   app.create();
//
//   app.run();
// }

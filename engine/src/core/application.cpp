#include "core/application.h"

#include "core/logger.h"

namespace Lord {

struct ApplicationState {
  Scope<Window> window;
  std::string title;

  bool is_running;
  bool is_suspended;
  u32 width;
  u32 height;
  f32 delta;
};

Application::Application() {
  m_config.is_running = false;
  m_config.is_suspended = false;
}

void Application::shutdown() {
}

void Application::create() {
  m_config.window = Window::create();
}

bool Application::run() {
  m_config.is_running = true;
  m_config.is_suspended = true;

  ErrorOr<void, std::string> window_res = m_config.window->run();
  if (!window_res) [[ unlikely ]]  {
    DFATAL("[[WINDOW]] {}", window_res.error());
    return false;
  }

  while (m_config.is_running) {
    m_config.is_running = m_config.window->pumpMessages();
  }

  return true;
}

}

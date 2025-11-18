#pragma once

#include "defines.h"

#include "core/window.h"

namespace Lord {

class EngineTypes;

struct ApplicationConfig {
  Scope<Window> window;
  std::string title;

  bool is_running;
  bool is_suspended;
  u32 width;
  u32 height;
  f32 delta;
};

class DAPI Application {
public:
  Application();
  ~Application() {
    shutdown();
  }

  void create();
  bool run();

private:
  void shutdown();

  ApplicationConfig m_config;
};

}

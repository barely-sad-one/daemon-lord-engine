#pragma once

#include "core/application.h"

namespace Lord {

class EngineTypes {
  ApplicationConfig app_config;

  bool initialize();
  bool update(f32 delta_time);
  bool render(f32 delta_time);
  void onResize(u32 widht, u32 height);

  Ref<void> state;
};

}

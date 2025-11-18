#pragma once

#include "defines.h"
#include "core/window.h"
#include "platform/input_types.h"

namespace Lord::platform {

struct Internal_State;

class DAPI PlatformWindow : public Window {
public:
  struct State {
    Scope<Internal_State> internal_state;
  };

  PlatformWindow(const WindowProps& props);
  virtual ~PlatformWindow();

  u32 getWidth() const override;
  u32 getHeight() const override;

  void setVSync(bool enabled) override;
  bool isVSync() const override;

  void* getNativeWindow() const override;

  [[ nodiscard ]] ErrorOr<void, std::string> run() override;
  bool pumpMessages() override;
  virtual void shutdown() override;

private:
  State m_state;
};

}

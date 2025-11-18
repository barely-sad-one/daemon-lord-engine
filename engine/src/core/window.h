/**
 * @file window.h
 * @brief [TODO:description]
 */

#pragma once

#include "defines.h"

namespace Lord {

struct WindowProps {
  std::string title;
  u32 width;
  u32 height;

  WindowProps(std::string title = "Daemon Lord", u32 width = 1600, u32 height = 900)
  : title(std::move(title)), width(width), height(height) {
  }
};

class DAPI Window {
public:
  virtual ~Window() = default;

  virtual u32 getWidth() const = 0;
  virtual u32 getHeight() const = 0;

  virtual void setVSync(bool enabled) = 0;
  virtual bool isVSync() const = 0;

  virtual void* getNativeWindow() const = 0;

  static Scope<Window> create(const WindowProps& props = WindowProps());

  virtual ErrorOr<void, std::string> run() = 0;
  virtual bool pumpMessages() = 0;
  virtual void shutdown() = 0;
};

}

#include "core/window.h"

#include "platform/window.h"

namespace Lord {

Scope<Window> Window::create(const WindowProps& props) {
#if defined(DPLATFORM_LINUX)
  return CreateScope<platform::PlatformWindow>(props);
#else
  #error "Platform not supported"
#endif
}


}

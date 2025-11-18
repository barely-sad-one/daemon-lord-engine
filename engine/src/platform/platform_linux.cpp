#include "platform/platform.h"

#if defined (DPLATFORM_LINUX)

#include <execinfo.h>
#include <vector>
#include <sstream>
#include <cstdlib>

namespace Lord {

std::optional<std::string> callstack(u32 maxFrames) {
  std::vector<void*> addrList(maxFrames);
  u32 addrLen = backtrace(addrList.data(), maxFrames);
  if (addrLen == 0) {
    return std::nullopt;
  }

  char** symbolList = backtrace_symbols(addrList.data(), addrLen);
  if (!symbolList) {
    return std::nullopt;
  }

  std::ostringstream oss;
  oss << "Call stack (" << addrLen << " frames):\n";
  for (u32 i = 0; i < addrLen; ++i) {
    oss << " " << symbolList[i] << "\n";
  }

  free(symbolList);
  return oss.str();
}
 
};

#else
# error "Platform is not suppored yet"
#endif

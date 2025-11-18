#pragma once

#include "defines.h"

#include <optional>

namespace Lord {

DAPI std::optional<std::string> callstack(u32 maxFrames = 64);

}

#pragma once

#include "defines.h"

namespace Lord {

class Error {
public:
  virtual ~Error() = default;

  virtual std::string_view name() const noexcept = 0;

  virtual std::string message() const = 0;

  friend std::ostream& operator<<(std::ostream& os, const Error& err) {
    return os << err.name() << ": " << err.message() << "\n"
  }
};

}

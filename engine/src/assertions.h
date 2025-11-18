#pragma once

#include "defines.h"

#include "platform/platform.h"
#include <iostream>


#define REPORT_ASSERTION(expression, message, file, line) \
  DFATAL("Assertion Failure: {}, message: {}, (file:line): {}:{}", expression, message, file, line)

#define DASSERT(expr) \
{ \
  if (expr) { \
  } else { \
    REPORT_ASSERTION(#expr, "", __FILE__, __LINE__); \
    auto UNIQUE_VAR(error_stack) = ::Lord::callstack(); \
    if (UNIQUE_VAR(error_stack)) std::cout << ::Lord::callstack().value() << std::endl; \
    DEBUG_BREAK(); \
  } \
}

#define DASSERT_MSG(expr, message) \
{ \
  if (expr) { \
  } else { \
    REPORT_ASSERTION(#expr, message, __FILE__, __LINE__); \
    auto UNIQUE_VAR(error_stack) = ::Lord::callstack(); \
    if (UNIQUE_VAR(error_stack)) std::cout << ::Lord::callstack().value() << std::endl; \
    DEBUG_BREAK(); \
  } \
}

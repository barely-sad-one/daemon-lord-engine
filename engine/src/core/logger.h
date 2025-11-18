/**
 * @file logger.h
 * @brief [TODO:description]
 */

#pragma once

#include "defines.h"

#include "assertions.h"

#include <functional>
#include <format>
#include <print>
#include <atomic>

namespace Lord {

enum LogLevel {
  LOG_LEVEL_FATAL,
  LOG_LEVEL_ERROR,
  LOG_LEVEL_WARN,
  LOG_LEVEL_INFO,
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_TRACE
};

class DAPI Logger {
public:
  using PFN_logger_t = std::function<void(LogLevel, std::string_view)>;

  template <typename... Args>
  static void log(LogLevel level, std::string_view fmt, Args&&... args) {
    auto& self = get();

    std::string_view levelStr;
    switch (level) {
      case LOG_LEVEL_FATAL: levelStr = "[FATAL]"; break;
      case LOG_LEVEL_ERROR: levelStr = "[ERROR]"; break;
      case LOG_LEVEL_WARN : levelStr = "[WARN ]"; break;
      case LOG_LEVEL_INFO : levelStr = "[INFO ]"; break;
      case LOG_LEVEL_DEBUG: levelStr = "[DEBUG]"; break;
      case LOG_LEVEL_TRACE: levelStr = "[TRACE]"; break;
      default:              levelStr = "[UNKNOWN]"; break;
    }

    std::string message = std::vformat(fmt, std::make_format_args(args...));

    auto hook_ptr = self.m_hook.load();
    if (hook_ptr) {
      (*hook_ptr)(level, message);
    } else {
      std::print("{}: {}\n", levelStr, message);
    }
  }

  static ALWAYS_INLINE void setHook(PFN_logger_t hook) {
    auto& self = get();
    self.m_hook.store(CreateRef<PFN_logger_t>(std::move(hook)));
  }

private:
  Logger() = default;
  ~Logger() = default;

  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;

  static ALWAYS_INLINE Logger& get() {
    static Logger instance;
    return instance;
  }

  std::atomic<Ref<PFN_logger_t>> m_hook{nullptr};
};

}

#define DFATAL(...) ::Lord::Logger::log(::Lord::LOG_LEVEL_FATAL, __VA_ARGS__)
#define DERROR(...) ::Lord::Logger::log(::Lord::LOG_LEVEL_ERROR, __VA_ARGS__)
#define DWARN(...) ::Lord::Logger::log(::Lord::LOG_LEVEL_WARN, __VA_ARGS__)
#define DINFO(...) ::Lord::Logger::log(::Lord::LOG_LEVEL_INFO, __VA_ARGS__)
#define DDEBUG(...) ::Lord::Logger::log(::Lord::LOG_LEVEL_DEBUG, __VA_ARGS__)
#define DTRACE(...) ::Lord::Logger::log(::Lord::LOG_LEVEL_TRACE, __VA_ARGS__)

#define YET_TO_IMPLEMENT_PANIC() DASSERT_MSG(false, "Yet to Implement!")
#define YET_TO_IMPLEMENT()       DFATAL("Yet to Implement! (file:line): {}:{}", __FILE__, __LINE__)


/**
 * @file defines.h
 * @brief This file contains global definitions which are used
 * throughout the project
 */

#pragma once

#include <memory>
#include <expected>

#define DAPI __attribute__((visibility("default")))

#define ALWAYS_INLINE __attribute__((always_inline)) inline
#define NEVER_INLINE __attribute__((no_inline))

#define UNIQUE_VAR(name) _unique_##name##__COUNTER__

namespace Lord {

using i8  = signed char;
using i16 = signed short;
using i32 = signed int;
using i64 = signed long long;

static_assert(sizeof(i8)  == 1, "Expected i8 to be 1 byte");
static_assert(sizeof(i16) == 2, "Expected i16 to be 2 byte");
static_assert(sizeof(i32) == 4, "Expected i32 to be 4 byte");
static_assert(sizeof(i64) == 8, "Expected i64 to be 8 byte");

using u8  = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;

static_assert(sizeof(u8)  == 1, "Expected u8 to be 1 byte");
static_assert(sizeof(u16) == 2, "Expected u16 to be 2 byte");
static_assert(sizeof(u32) == 4, "Expected u32 to be 4 byte");
static_assert(sizeof(u64) == 8, "Expected u64 to be 8 byte");

using f32 = float;
using f64 = double;

static_assert(sizeof(f32) == 4, "Expected f32 to be 3 byte");
static_assert(sizeof(f64) == 8, "Expected f64 to be 8 byte");

#define UNREACHABLE() __builtin_unreachable()

#if defined(__has_builtin)
# if __has_builtin(__builtin_debugtrap)
#   define DEBUG_BREAK() __builtin_debugtrap()
# endif
#endif

#if !defined(DEBUG_BREAK)
# define DEBUG_BREAK() __builtin_trap()
#endif

template <typename T>
using Scope = std::unique_ptr<T>;
template <typename T, typename... Args>
constexpr Scope<T> CreateScope(Args&&... args) {
  return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename T>
using Ref = std::shared_ptr<T>;
template <typename T, typename... Args>
constexpr Ref<T> CreateRef(Args&&... args) {
  return std::make_shared<T>(std::forward<Args>(args)...);
}

template <typename T, typename U>
using ErrorOr = std::expected<T, U>;

template <typename T>
using Error = std::unexpected<T>;

#define DPLATFORM_LINUX 1

};

#ifndef MULT_H
#define MULT_H

#include "reduce.h"

#include <utility>

namespace func {

struct {
  template <typename... FS>
  constexpr auto operator()(FS&&... fs) {
    return reduce([](const auto& x, const auto& y) { return x * y; },
                  std::forward<FS>(fs)...);
  }
} mult;
};

#endif  // MULT_H

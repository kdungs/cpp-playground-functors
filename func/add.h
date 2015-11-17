#ifndef ADD_H
#define ADD_H

#include "reduce.h"

#include <utility>

namespace func {

struct {
  template <typename... FS>
  constexpr auto operator()(FS&&... fs) {
    return reduce([](const auto& x, const auto& y) { return x + y; },
                  std::forward<FS>(fs)...);
  }
} add;

};

#endif  // ADD_H

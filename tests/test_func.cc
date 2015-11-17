#include "func/func.h"
#include "mock_particle.h"

#include <cmath>
#include <iostream>

template <typename LHS, typename RHS>
constexpr auto operator|(LHS&& lhs, RHS rhs) {
  // Not very nice to have this defined globally.
  // Also want to lift functions that take values instead of function.
  // So we might want to use the curious inheritance after all.
  return rhs(std::forward<LHS>(lhs));
}

int main() {
  auto particle = Particle{1.0, 2.0, 3.0, {{{0, 0}, {1, 1}, {2, 2}}}};

  auto square = [](const auto& x) { return x * x; };
  auto sqrt = [](const auto& x) { return std::sqrt(x); };

  auto fsquare = func::lift(square);
  auto fsqrt = func::lift(sqrt);

  auto p = func::map(fsquare, px, py, pz) | func::add | fsqrt;
  std::cout << p(particle) << '\n';

  auto pslope = func::chain(track, slope);
  std::cout << pslope(particle) << '\n';
}

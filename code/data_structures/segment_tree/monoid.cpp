// Monoid {{{
template<typename T, typename F>
struct Monoid {
  const T identity;
  const F op;
  constexpr Monoid(T identity, F op) : identity(identity), op(op) {}
  constexpr T operator()(T const& a, T const& b) const { return op(a, b); }
};

namespace Monoids {
  template<typename T> constexpr Monoid Sum(T(), std::plus<T>{});
  template<typename T> constexpr Monoid SumPair(std::pair<T, T>{T(), T()}, [](auto const& a, auto const& b) {
    return std::pair<T, T>{a.first+b.first, a.second+b.second};
  });
  template<typename T> constexpr Monoid Product(T(1), std::multiplies<T>{});
  template<typename T, T INF> constexpr Monoid Max(T(-INF), [](T const& a, T const& b) { return max(a, b); });
  template<typename T, T INF> constexpr Monoid Min(T(+INF), [](T const& a, T const& b) { return min(a, b); });
  template<typename T, T INF> constexpr Monoid MaxIdx(std::pair<T, T>{-INF, T(-1)}, [](auto const& a, auto const& b) {
    if (a.first >= b.first) return a;
    return b;
  });
  template<typename T, T INF> constexpr Monoid MinIdx(std::pair<T, T>{+INF, T(-1)}, [](auto const& a, auto const& b) {
    if (a.first <= b.first) return a;
    return b;
  });
  template<typename T> constexpr Monoid LinearComposition(std::pair<T, T>{T(1), T(0)}, [](auto const& a, auto const& b) {
    // This applies b on a, swap arguments if needed
    return std::pair<T, T>{a.first*b.first, a.second*b.first + b.second};
  });
};
// }}}

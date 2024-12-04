// Lazy Context {{{
template<typename AF, typename T, typename L>
concept LazyApplyFunction = requires(AF apply, T t, L l, int il, int ir) {
  { std::invoke(apply, t, l, il, ir) } -> std::same_as<T>;
};

template<typename T, typename TF, typename L, typename LF, typename AF>
requires LazyApplyFunction<AF, T, L>
struct LazyContext {
  const Monoid<T, TF> data_M;
  const Monoid<L, LF> lazy_M;
  const AF apply;
  constexpr LazyContext(Monoid<T, TF> const& data_M, Monoid<L, LF> const& lazy_M, AF const& apply)
    : data_M(data_M), lazy_M(lazy_M), apply(apply) {}
};

namespace LazyContexts {
  template<typename T> constexpr LazyContext RangeAddQuerySum(Monoids::Sum<T>, Monoids::Sum<T>, [](T d, T l, int il, int ir) { return d+l*(ir-il+1); });
  template<typename T, T INF> constexpr LazyContext RangeAddQueryMax(Monoids::Max<T, INF>, Monoids::Sum<T>, [](T d, T l, int il, int ir) { return d+l; });
  template<typename T, T INF> constexpr LazyContext RangeAddQueryMaxIdx(Monoids::MaxIdx<T, INF>, Monoids::Sum<T>, [](pair<T, T> d, T l, int il, int ir) { return pair{d.first+l, d.second}; });
  template<typename T, T INF> constexpr LazyContext RangeAddQueryMin(Monoids::Min<T, INF>, Monoids::Sum<T>, [](T d, T l, int il, int ir) { return d+l; });
  template<typename T, T INF> constexpr LazyContext RangeAddQueryMinIdx(Monoids::MinIdx<T, INF>, Monoids::Sum<T>, [](pair<T, T> d, T l, int il, int ir) { return pair{d.first+l, d.second}; });
};
//}}}

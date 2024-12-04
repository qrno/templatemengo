// Lazy Segment Tree {{{
template<typename T, typename TF, typename L, typename LF, typename AF>
struct SegmentTreeLazy {
  const int N;
  const LazyContext<T, TF, L, LF, AF> context;

  std::vector<T> data;
  std::vector<L> lazy;

  constexpr int left(int id) const { return 2*id; }
  constexpr int right(int id) const { return 2*id+1; }

  void push(int id, int il, int ir) {
    int len = ir-il+1;
    if (len >= 2) {
      lazy[left(id)] = context.lazy_M(lazy[left(id)], lazy[id]);
      lazy[right(id)] = context.lazy_M(lazy[right(id)], lazy[id]);
    }
    data[id] = context.apply(data[id], lazy[id], il, ir);
    lazy[id] = context.lazy_M.identity;
  }

  void set(int p, T const& val, int id, int il, int ir) {
    push(id, il, ir);
    if (il == ir) {
      data[id] = val;
      return;
    }
    int im = std::midpoint(il, ir);
    if (p <= im) set(p, val, left(id), il, im);
    else set(p, val, right(id), im+1, ir);
    data[id] = context.data_M(data[left(id)], data[right(id)]);
  }

  void update(int l, int r, L x, int id, int il, int ir) {
    push(id, il, ir);
    if (r < il || ir < l) return;
    if (l <= il && ir <= r) {
      lazy[id] = context.lazy_M(lazy[id], x);
      push(id, il, ir);
      return;
    }
    int im = std::midpoint(il, ir);
    update(l, r, x, left(id), il, im);
    update(l, r, x, right(id), im+1, ir);
    data[id] = context.data_M(data[left(id)], data[right(id)]);
  }

  T query(int l, int r, int id, int il, int ir) {
    push(id, il, ir);
    if (r < il || ir < l) return context.data_M.identity;
    if (l <= il && ir <= r) return data[id];
    int im = std::midpoint(il, ir);
    return context.data_M(query(l, r, left(id), il, im), query(l, r, right(id), im+1, ir));
  }

  void build(std::vector<T> const& A, int id, int il, int ir) {
    if (il == ir) {
      data[id] = A[il];
      return;
    }
    int im = std::midpoint(il, ir);
    build(A, left(id), il, im);
    build(A, right(id), im+1, ir);
    data[id] = context.data_M(data[left(id)], data[right(id)]);
  }

public:
  explicit SegmentTreeLazy(int N, LazyContext<T, TF, L, LF, AF> const& LC)
    : N(N), data(4*N, LC.data_M.identity), lazy(4*N, LC.lazy_M.identity), context(LC) {}

  explicit SegmentTreeLazy(std::vector<T> const& A, LazyContext<T, TF, L, LF, AF> const& LC)
    : LazySegmentTree(size(A), LC) {
    build(A, 1, 0, N-1);
  }

  void update(int l, int r, L x) { update(l, r, x, 1, 0, N-1); }

  void set(int p, T const& val) { set(p, val, 1, 0, N-1); }

  [[nodiscard]]
  T query(int l, int r) { return query(l, r, 1, 0, N-1); }

  void debug() {
    std::cout << "Debug: ";
    for (int i = 0; i < N; i++) {
      std::cout << query(i, i) << ' ';
    }
    std::cout << std::endl;
  }
};
//}}}

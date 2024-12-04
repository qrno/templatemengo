// Segment Tree {{{
template<typename T, typename TF>
class SegmentTree {
  const int N;
  const Monoid<T, TF> M;
  std::vector<T> data;

  constexpr int left(int id) const { return 2*id; }
  constexpr int right(int id) const { return 2*id+1; }

public:
  explicit SegmentTree(int N, Monoid<T, TF> const& M) : N(N), data(2*N, M.identity), M(M) {}
  explicit SegmentTree(std::vector<T> const& A, Monoid<T, TF> const& M) : SegmentTree(size(A), M) {
    for (int i = 0; i < N; i++) set(i, A[i]);
  }

  void set(int p, T const& val) {
    for (data[p+=N]=val; p /= 2;)
      data[p] = M(data[left(p)], data[right(p)]);
  }

  T get(int p) const {
    return data[p+N];
  }

  void add(int p, T const& val) {
    set(p, get(p)+val);
  }

  T query(int l, int r) const {
    T rl = M.identity, rr = M.identity;
    for (l += N, r += N+1; l < r; l/=2, r/=2) {
      if (l & 1) rl = M(rl, data[l++]);
      if (r & 1) rr = M(data[--r],rr);
    }
    return M(rl, rr);
  }
};
//}}}

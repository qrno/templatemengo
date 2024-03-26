//{{{ Segment Tree
template<typename T>
class SegmentTree {
  int N;
  vector<T> data;
public:
  explicit SegmentTree(int N) : N(N), data(2*N) {}
  explicit SegmentTree(vector<T> const& A) : N(size(A)) {
    for (int i = 0; i < N; i++) set(i, A[i]);
  }

  void set(int p, T const& val) {
    for (data[p+=N]=val; p /= 2;)
      data[p] = data[2*p]+data[2*p+1];
  }

  T get(int p) const {
    return data[p + N];
  }

  void add(int p, T const& val) {
    set(p, get(p)+val);
  }

  T sum(int l, int r)  const {
    T rl = T(), rr = T();
    for (l+=N, r+=N+1; l<r; l/=2, r/=2) {
      if (l&1) rl = rl+data[l++];
      if (r&1) rr = data[--r]+rr;
    }
    return rl+rr;
  }
};
//}}}

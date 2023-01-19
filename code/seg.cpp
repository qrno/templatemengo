template<typename T>
class SegmentTree {
  int n;
  T neutral;
  V<T> t;
  std::function<T(T,T)> merge;
public:
  SegmentTree(int n, T neutral,
              std::function<T(T,T)> merge) {
    this->n = n;
    this->neutral = neutral;
    this->merge = merge;
    t.assign(2*n, neutral);
  }

  SegmentTree(V<T> &v, T neutral,
              std::function<T(T,T)> merge) {
    this->n = v.size();
    this->neutral = neutral;
    this->merge = merge;
    t.assign(2*n, neutral);
    loop (i, n) t[i+n] = v[i];
    build();
  }

  void build() {
    for (int i=n-1; i>0; i--)
      t[i]=merge(t[2*i],t[2*i+1]);
  }

  T query(int l, int r) {
    T rl = neutral, rr = neutral;
    for (l+=n, r+=n+1; l<r; l/=2, r/=2) {
      if (l&1) rl = merge(rl, t[l++]);
      if (r&1) rr = merge(t[--r], rr);
    }
    return merge(rl, rr);
  }

  void update(int p, T val) {
    for (t[p+=n]=val; p > 1; p /= 2)
      t[p/2] = merge(t[min(p, p^1)], t[max(p, p^1)]);
  }
};


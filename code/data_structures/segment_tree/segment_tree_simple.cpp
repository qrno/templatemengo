//{{{ Segment Tree Simple
template<typename T>
class SegmentTreeSimple {
  int N;
  T neutral;
  vector<T> data;
  function<T(T,T)> merge;
public:
  SegmentTreeSimple(int N, T neutral, function<T(T,T)> merge) {
    this->N = N;
    this->neutral = neutral;
    this->merge = merge;
    data.assign(2*N, neutral);
  }

  SegmentTreeSimple(vector<T> const& A, T neutral, function<T(T,T)> merge) {
    this->N = A.size();
    this->neutral = neutral;
    this->merge = merge;
    data.resize(2*N);
    for (int i = 0; i < N; i++) data[i+N] = A[i];
    for (int i=N-1; i>0; i--)
      data[i]=merge(data[2*i],data[2*i+1]);
  }

  void set(int p, T const& val) {
    for (data[p+=N]=val; p /= 2;)
      data[p] = merge(data[2*p], data[2*p+1]);
  }

  T get(int p) const {
    return data[p + N];
  }

  void add(int p, T const& val) {
    set(p, merge(get(p),val));
  }

  T sum(int l, int r) const {
    T rl = neutral, rr = neutral;
    for (l+=N, r+=N+1; l<r; l/=2, r/=2) {
      if (l&1) rl = merge(rl, data[l++]);
      if (r&1) rr = merge(data[--r], rr);
    }
    return merge(rl, rr);
  }
};
//}}}

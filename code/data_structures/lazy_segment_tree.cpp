// Lazy Segment Tree (Sum) {{{
struct SegmentTreeLazy {
  int N;
  vector<int> L, T;

  explicit SegmentTreeLazy(int N) : N(N) {
    L.resize(4*N);
    T.resize(4*N);
  }

  void push(int id, int il, int ir) {
    T[id] += L[id] * (ir-il+1);
    if (il < ir) {
      L[2*id] += L[id];
      L[2*id+1] += L[id];
    }
    L[id] = 0;
  }

  int update(int l, int r, int x, int id, int il, int ir) {
    push(id, il, ir);
    if (r < il || ir < l) return T[id];
    if (l <= il && ir <= r) {
      L[id] += x;
      push(id, il, ir);
      return T[id];
    }
    int im = midpoint(il, ir);
    return T[id] = update(l, r, x, 2*id, il, im)
                 + update(l, r, x, 2*id+1, im+1, ir);
  }
  void update(int l, int r, int x) { update(l, r, x, 1, 0, N-1); }

  int query(int l, int r, int id, int il, int ir) {
    push(id, il, ir);
    if (r < il || ir < l) return 0;
    if (l <= il && ir <= r) return T[id];

    int im = midpoint(il, ir);
    return query(l, r, 2*id, il, im)
         + query(l, r, 2*id+1, im+1, ir);
  }
  int query(int l, int r) { return query(l, r, 1, 0, N-1); }
};
//}}}

// Lazy Segment Tree (Arithmetic Progression) {{{
using ii = pair<int, int>;
ii operator+(ii a, ii b) { return {a.first + b.first, a.second + b.second}; }

struct SegmentTreeLazyAP {
  int N;
  vector<ii> L;
  vector<int> T;

  explicit SegmentTreeLazyAP(int N) : N(N) {
    L.resize(4*N);
    T.resize(4*N);
  }

  int ap_sum(int base, int step, int len) {
    return (base + base+step*(len-1)) * len / 2;
  }

  void push(int id, int il, int ir) {
    auto [base, step] = L[id];
    int len = ir-il+1;

    T[id] += ap_sum(base, step, len);

    if (len > 1) {
      int im = midpoint(il, ir);
      L[2*id] = L[2*id] + ii{base, step};
      L[2*id+1] = L[2*id+1] + ii{base + (im+1-il)*step, step};
    }

    L[id] = {0, 0};
  }

  int update(int l, int r, ii x, int id, int il, int ir) {
    push(id, il, ir);
    if (r < il || ir < l) return T[id];
    if (l <= il && ir <= r) {
      L[id] = L[id] + ii{x.first + (il-l)*x.second, x.second};
      push(id, il, ir);
      return T[id];
    }
    int im = midpoint(il, ir);
    return T[id] = update(l, r, x, 2*id, il, im)
                 + update(l, r, x, 2*id+1, im+1, ir);
  }
  void update(int l, int r, ii x) { update(l, r, x, 1, 0, N-1); }

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


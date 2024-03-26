// Range Fenwick {{{
struct RangeFenwick {
  FenwickTree FT;
  RangeFenwick(int N) : FT(N+1) {}

  void update(int l, int r, int x) {
    FT.add(l, x);
    FT.add(r+1, -x);
  }

  int query(int idx) {
    return FT.sum(idx);
  }
};
//}}}

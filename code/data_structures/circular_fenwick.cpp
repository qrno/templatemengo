// {{{ Circular Fenwick
struct CircularFenwick {
  int N;
  RangeFenwick RF;

  CircularFenwick(int N) : N(N), RF(N) {}

  void update(int l, int r, int x) {
    if (l <= r) RF.update(l, r, x);
    else {
      RF.update(l, N-1, x);
      RF.update(0, r, x);
    }
  }

  int get(int p) {
    return RF.query(p);
  }
};
//}}}

// LineContainer {{{
// Line = k*x + m, has maximum value for x up to P
struct Line {
  mutable int k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(int x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  static const int INF = LLONG_MAX;
  int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); }
  bool isect(iterator x, iterator y) {
    if (y == end()) return x->p = INF, 0;
    if (x->k == y->k) x->p = x->m > y->m ? INF : -INF;
    else x-> p = fdiv(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(int k, int m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  int query(int x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

struct MinLineContainer {
  LineContainer LC;
  void add(int k, int m) { LC.add(-k, -m); };
  int query(int x) { return -LC.query(x); }
};
//}}}

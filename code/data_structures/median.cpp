struct Median {
  int ss = 0, sb = 0;
  multiset<int> S, B;

  void rebalance() {
    while (sz(S) < sz(B)) S.insert(*begin(B)), ss += *begin(B), sb -= *begin(B), B.erase(begin(B));
    while (sz(S) > sz(B)+1) B.insert(*rbegin(S)), sb += *rbegin(S), ss -= *rbegin(S), S.erase(prev(S.end()));
    while (!empty(S) && !empty(B) && *rbegin(S) > *begin(B)) {
      int a = *rbegin(S), b = *begin(B);
      ss -= a, ss += b;
      sb -= b, sb += a;
      S.erase(prev(end(S)));
      B.erase(begin(B));
      S.insert(b);
      B.insert(a);
    }
  }

  void insert(int x) {
    S.insert(x);
    ss += x;
    rebalance();
  }

  void remove(int x) {
    if (x <= *rbegin(S)) S.erase(S.find(x)), ss -= x;
    else B.erase(B.find(x)), sb -= x;
    rebalance();
  }

  int get() {
    return *rbegin(S);
  }

  int cost() {
    int med = get();
    int cost = med * sz(S) - ss;
    cost += sb - med * sz(B);
    return cost;
  }
};


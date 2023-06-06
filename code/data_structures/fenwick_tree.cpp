struct FenwickTree {
  int n;
  vector<int> bit;

  FenwickTree(int n) : n(n), bit(n) {}

  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r &= r+1, r--)
      ret += bit[r];
    return ret;
  }

  void add(int idx, int delta) {
    for (; idx < n; idx |= idx+1)
      bit[idx] += delta;
  }
};

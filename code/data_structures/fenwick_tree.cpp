//{{{ FenwickTree
struct FenwickTree {
  int N;
  vector<int> data;

  FenwickTree(int N) : N(N), data(N) {}

  void add(int idx, int delta) {
    for (; idx < N; idx |= idx+1)
      data[idx] += delta;
  }

  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r &= r+1, r--)
      ret += data[r];
    return ret;
  }

  int sum(int l, int r) {
    return sum(r) - sum(l-1);
  }
};
//}}}

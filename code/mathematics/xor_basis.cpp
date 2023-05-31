struct Basis {
  vector<int> B;
  int reduce(int x) {
    for (auto b : B) x = min(x, x^b);
    return x;
  }
  void insert(int x) {
    int r = reduce(x);
    if (r) B.push_back(r);
  }
};

struct DSU {
  vector<int> p, s;
  DSU (int n) : p(n, -1), s(n, 1) {};
  int find(int v) {
    if (p[v] == -1) return v;
    return p[v] = find(p[v]);
  }
  void join(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) {
      if (s[a] < s[b]) swap(a, b);
      p[b] = a, s[a] += s[b];
    }
  }
};


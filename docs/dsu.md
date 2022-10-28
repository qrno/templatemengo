# Disjoint Set Union

!!! warning
    The implementation uses indexes 0...n

```cpp title="DSU"
struct DSU {
  vector<int> p, s;
  DSU (int n) { p.assign(n, -1), s.assign(n, 1); }
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
```

## Problems

- [Some problem](google.com) uses a vector of DSUs for...

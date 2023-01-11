# Disjoint Set Union

## Implementation 

!!! warning
    The implementation uses indices [0, n-1]

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

This implementation can be tested on [Library Checker - Unionfind](https://judge.yosupo.jp/problem/unionfind). [[Submission]](https://judge.yosupo.jp/submission/110413)

## Problems

- [Codeforces 25D - Roads Not Only in Berland](https://codeforces.com/contest/25/problem/D)

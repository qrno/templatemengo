# Flow

## Dinitz

```cpp title="Dinitz"
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e9 + 8;

struct Dinitz {
  struct Edge {
    int v, u, cap, flow=0;
    Edge (int v, int u, int cap) : v(v), u(u), cap(cap) {}
  };

  vector<Edge> edges;
  vector<vector<int>> adj;

  int n, s, t;
  Dinitz(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n);
  }

  void add_edge(int v, int u, int cap) {
    edges.emplace_back(v, u, cap);
    adj[v].push_back(edges.size()-1);
    edges.emplace_back(u, v, 0);
    adj[u].push_back(edges.size()-1);
  }

  vector<int> level;
  bool bfs() {
    queue<int> Q;
    level.assign(n, -1);
    level[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
      int v = Q.front(); Q.pop();
      for (auto eid : adj[v]) {
        auto e = edges[eid];
        if (e.cap - e.flow <= 0) continue;
        if (level[e.u] != -1) continue;
        level[e.u] = level[v] + 1;
        Q.push(e.u);
      }
    }
    return level[t] != -1;
  }

  vector<int> ptr;
  int dfs(int v, int f) {
    if (f == 0 || v == t) return f;
    for (int &cid = ptr[v]; cid < adj[v].size(); cid++) {
      int eid = adj[v][cid];
      auto &e = edges[eid];
      if (e.cap - e.flow <= 0) continue;
      if (level[e.u] != level[e.v] + 1) continue;
      int newf = dfs(e.u, min(f, e.cap-e.flow));
      if (newf == 0) continue;
      e.flow += newf;
      edges[eid^1].flow -= newf;
      return newf;
    }
    return 0;
  }

  int flow() {
    int f = 0;
    while (bfs()) {
      ptr.assign(n, 0);
      while (int newf = dfs(s, INF))
        f += newf;
    }
    return f;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int l, r, m;
  cin >> l >> r >> m;

  int s = l+r, t = l+r+1;
  Dinitz d(l+r+2, s, t);

  for (int i = 0; i < l; i++) d.add_edge(s, i, 1);
  for (int i = 0; i < r; i++) d.add_edge(l+i, t, 1);

  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    d.add_edge(a, b+l, 1);
  }

  cout << d.flow() << endl;
  for (auto [v, u, cap, flow] : d.edges) {
    if (v == s || u == t) continue;
    if (flow <= 0) continue;
    cout << v << ' ' << u-l << endl;
  }
}
```

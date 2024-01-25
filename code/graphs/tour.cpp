// Euler Tour {{{
struct Tour {
  int source;
  vector<vector<int>> const& G;

  int TIMER = -1;
  vector<int> pre, pos, dep, who;

  Tour (vector<vector<int>> const& G, int source) : G(G), source(source) {
    int N = size(G);
    pre.assign(N, -1);
    pos.assign(N, -1);
    dep.assign(N, -1);
    who.assign(N, -1);
    dep[source] = 0;
    walk(source);
  }

  void walk(int v) {
    pre[v] = ++TIMER;
    who[pre[v]] = v;
    for (auto u : G[v]) {
      if (pre[u] == -1) {
        dep[u] = dep[v] + 1;
        walk(u);
      }
    }
    pos[v] = TIMER;
  }
};
//}}}

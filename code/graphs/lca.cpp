// Lowest Common Ancestor {{{
struct LCA {
  const int LOG = 22;

  int N;
  vector<vector<int>> const& G;

  int TIMER = -1;
  vector<int> pre, pos, dep;
  vector<vector<int>> parent;

  void dfs(int v, int p) {
    parent[v][0] = p;
    for (int b = 1; b < LOG; b++) {
      parent[v][b] = parent[parent[v][b-1]][b-1];
    }

    pre[v] = ++TIMER;
    for (auto u : G[v]) {
      if (u == p) continue;
      dep[u] = dep[v] + 1;
      dfs(u, v);
    }
    pos[v] = TIMER;
  }

  bool is_ancestor(int anc, int child) {
    return pre[anc] <= pre[child] && pos[child] <= pos[anc];
  }

  int lca(int v, int u) {
    if (is_ancestor(v, u)) return v;
    if (is_ancestor(u, v)) return u;

    for (int b = LOG-1; b >= 0; b--) {
      int nv = parent[v][b];
      if (!is_ancestor(nv, u)) v = nv;
    }
    v = parent[v][0];
    return v;
  }

  int dist(int v, int u) {
    int l = lca(v, u);
    int dist = dep[v] + dep[u] - 2*dep[l];
    return dist;
  }

  LCA (vector<vector<int>> const& G) : G(G), N(size(G)) {
    pre.assign(N, -1);
    pos.assign(N, -1);
    dep.assign(N, 0);
    parent.resize(N, vector<int>(LOG));
    for (int i = 0; i < N; i++) {
      if (pre[i] == -1) {
        dfs(i, i);
      }
    }
  }
};
//}}}


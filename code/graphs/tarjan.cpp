// Tarjan {{{
struct Tarjan {
  int N;
  vector<vector<int>> const& G;
  vector<int> comp;
  vector<vector<int>> comps;

  Tarjan(vector<vector<int>> const& G) : G(G) {
    N = size(G);
    pre.assign(N, -1);
    low.assign(N, -1);
    comp.assign(N, -1);

    for (int i = 0; i < N; i++) {
      if (pre[i] == -1) {
        dfs(i);
      }
    }
  }

  void make_comp(int v) {
    comps.push_back({});
    while (true) {
      int x = S.top();
      S.pop();
      comps.back().push_back(x);
      comp[x] = size(comps)-1;
      if (x == v) break;
    }
  }

  int TIMER = -1;
  vector<int> pre, low;
  vector<bool> used;
  stack<int> S;
  void dfs(int v) {
    S.push(v);
    pre[v] = low[v] = ++TIMER;

    for (auto u : G[v]) {
      if (pre[u] == -1) {
        dfs(u);
        low[v] = min(low[v], low[u]);
      } else if (comp[u] == -1) {
        low[v] = min(low[v], pre[u]);
      }
    }

    if (pre[v] == low[v]) make_comp(v);
  }
};
//}}}

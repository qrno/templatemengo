// Topological Sort {{{
// If v points to u, v comes before u
vector<int> topo(vector<vector<int>> G) {
  int N = size(G);

  vector<int> din(N);
  for (int i = 0; i < N; i++) {
    for (auto u : G[i]) {
      din[u]++;
    }
  }

  queue<int> Q;
  for (int i = 0; i < N; i++) {
    if (din[i] == 0) {
      Q.push(i);
    }
  }

  vector<int> topo;
  while (!empty(Q)) {
    auto v = Q.front();
    Q.pop();

    topo.push_back(v);

    for (auto u : G[v]) {
      if (!--din[u]) {
        Q.push(u);
      }
    }
  }

  return topo;
}
//}}}

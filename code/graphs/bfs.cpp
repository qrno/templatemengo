V<int> bfs(int source) {
  V<int> dist(sz(G), -1);
  queue<int> Q;
  dist[source] = 0;
  Q.push(source);

  while (!Q.empty()) {
    int v = Q.front(); Q.pop();
    for (auto u : G[v]) {
      if (dist[u] == -1) {
        dist[u] = dist[v] + 1;
        Q.push(u);
      }
    }
  }

  return dist;
}


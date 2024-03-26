// Dijkstra {{{
vector<int> dijkstra(vector<vector<pair<int, int>>> const& G, int source) {
  vector<int> dist(size(G), -1);

  min_priority_queue<pair<int, int>> Q;
  dist[source] = 0;
  Q.push({dist[source], source});

  while (!Q.empty()) {
    auto [d, v] = Q.top(); Q.pop();
    if (d > dist[v]) continue;

    for (auto [u, d] : G[v]) {
      if (dist[v] + d  < dist[u] || dist[u] == -1) {
        dist[u] = dist[v] + d;
        Q.push({dist[u], u});
      }
    }
  }

  return dist;
}
//}}}


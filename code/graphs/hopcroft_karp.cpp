// Hopcroft-Karp {{{
struct HopcroftKarp {
  const int NONE_R;
  const int INF = 1e9 + 8;

  int L, R;
  int ans = 0;
  vector<int> ml, mr;
  vector<int> lvl;
  vector<vector<int>> const& G;

  bool bfs() {
    queue<int> Q;
    for (int l = 0; l < size(ml); l++) {
      if (ml[l] == -1) {
        lvl[l] = 0;
        Q.push(l);
      } else {
        lvl[l] = INF;
      }
    }
    lvl[NONE_R] = INF;
    while (!empty(Q)) {
      int l = Q.front();
      Q.pop();
      if (lvl[l] < lvl[NONE_R]) {
        for (auto r : G[l]) {
          if (lvl[mr[r]] == INF) {
            lvl[mr[r]] = lvl[l] + 1;
            Q.push(mr[r]);
          }
        }
      }
    }
    return lvl[NONE_R] != INF;
  }

  bool dfs(int l) {
    if (l == NONE_R) return true;
    for (auto r : G[l]) {
      if (lvl[mr[r]] == lvl[l] + 1) {
        if (dfs(mr[r])) {
          ml[l] = r;
          mr[r] = l;
          return true;
        }
      }
    }
    lvl[l] = INF;
    return false;
  }

  HopcroftKarp(int _L, int _R, vector<vector<int>> const& G) : L(_L), R(_R), NONE_R(_L), G(G) {
    ml.assign(L, -1);
    mr.assign(R, NONE_R);
    lvl.assign(L+1, -1);

    while (bfs()) {
      for (int l = 0; l < L; l++) {
        if (ml[l] == -1) {
          if (dfs(l)) ans++;
        }
      }
    }
  }
};
//}}}

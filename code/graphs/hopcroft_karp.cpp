// Hopcroft-Karp {{{
struct HopcroftKarp {
  const int NONE;
  const int INF = 1e9 + 8;

  int L, R;
  int ans = 0;
  vector<int> ml, mr;
  vector<int> lvl;
  vector<vector<int>> const& G;

  bool bfs() {
    queue<int> Q;
    for (int l = 0; l < size(ml); l++) {
      if (ml[l] == NONE) {
        lvl[l] = 0;
        Q.push(l);
      } else {
        lvl[l] = INF;
      }
    }
    lvl[NONE] = INF;
    while (!empty(Q)) {
      int l = Q.front();
      Q.pop();
      if (lvl[l] < lvl[NONE]) {
        for (auto r : G[l]) {
          if (lvl[mr[r]] == INF) {
            lvl[mr[r]] = lvl[l] + 1;
            Q.push(mr[r]);
          }
        }
      }
    }
    return lvl[NONE] != INF;
  }

  bool dfs(int l) {
    if (l == NONE) return true;
    for (auto r : G[l]) {
      if (lvl[mr[r]] == lvl[l] + 1) {
        if (dfs(mr[r])) {
          ml[l] = r;
          mr[r] = l;
          return true;
        }
      }
    }
    lvl[l] = NONE;
    return false;
  }

  HopcroftKarp(int L, int R, vector<vector<int>> const& G) : L(L), R(R), NONE(L), G(G) {
    ml.assign(L, NONE);
    mr.assign(R, NONE);
    lvl.assign(L+1, -1);

    while (bfs()) {
      for (int l = 0; l < L; l++) {
        if (ml[l] == NONE) {
          if (dfs(l)) ans++;
        }
      }
    }
  }
};
//}}}

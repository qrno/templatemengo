// Disjoint  Sparse Table {{{
const int INF = 1e9 + 8;

vector<int> compute_log(int MAXN) {
  vector<int> LOG(MAXN+1, 0);
  for (int i = 2; i <= MAXN; i++) {
    LOG[i] = LOG[i/2] + 1;
  }
  return LOG;
}

const auto LOG = compute_log(1e6 + 8);

struct DisjointSparseTable {
  vector<vector<int>> ST;
  vector<int> A;

  DisjointSparseTable(vector<int> const& _A) {
    int lg = 1;
    while ((1 << lg) < _A.size()) lg++;
    A = _A;
    A.resize(1 << lg, INF);
    ST.resize(lg+1, vector<int>(1<<lg));
    build(0, (1 << lg)-1, lg-1);
  }

  void build(int l, int r, int level) {
    if (level < 0) return;

    int m = (l+r)/2;

    ST[level][m] = A[m];
    for (int i = m-1; i >= l; i--) {
      ST[level][i] = min(A[i], ST[level][i+1]);
    }

    ST[level][m+1] = A[m+1];
    for (int i = m+2; i <= r; i++) {
      ST[level][i] = min(A[i], ST[level][i-1]);
    }

    build(l, m, level-1);
    build(m+1, r, level-1);
  }

  int query(int l, int r) {
    if (l == r) return A[l];
    int level = LOG[r^l];
    return min(ST[level][l], ST[level][r]);
  }
};
// }}}

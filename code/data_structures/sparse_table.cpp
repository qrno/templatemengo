// Sparse Table (Min) {{{
struct SparseTable {
  int N;
  vector<vector<int>> ST;
  vector<int> LOG;
  SparseTable(vector<int> const& A) : N(size(A)), LOG(size(A)+1) {
    LOG[1] = 0;
    for (int i = 2; i < size(LOG); i++) {
      LOG[i] = LOG[i/2] + 1;
    }

    ST.assign(LOG[N]+1, vector<int>(N));
    ST[0] = A;

    for (int l = 1; l < size(ST); l++) {
      int len = (1 << l);
      for (int i = 0; i+len-1 < N; i++) {
        ST[l][i] = min(ST[l-1][i], ST[l-1][i+len/2]);
      }
    }
  }

  int query(int l, int r) {
    int lg = LOG[r-l+1];
    return min(ST[lg][l], ST[lg][r-(1<<lg)+1]);
  }
};
//}}}

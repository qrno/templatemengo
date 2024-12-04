// Prefix Sum 2d {{{
void partial_sum(vector<vector<int>> &A) {
  for (int i = 0; i < size(A); i++) {
    for (int j = 0; j < size(A.front()); j++) {
      if (i) A[i][j] += A[i-1][j];
      if (j) A[i][j] += A[i][j-1];
      if (i && j) A[i][j] -= A[i-1][j-1];
    }
  }
}

int psum(vector<vector<int>> const& A, int i1, int j1, int i2, int j2) {
  if (i1 > i2 || j1 > j2) return 0;
  int sum = A[i2][j2];
  if (i1) sum -= A[i1-1][j2];
  if (j1) sum -= A[i2][j1-1];
  if (i1 && j1) sum += A[i1-1][j1-1];
  return sum;
}
// }}}

// Matrix Exponentiation {{{
struct Matrix {
  int N;
  vector<vector<mint>> M;
  Matrix (int N) : N(N), M(N, vector<mint>(N)) {}
  Matrix operator*(Matrix const& rhs) {
    Matrix result(N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          result.M[i][j] += M[i][k] * rhs.M[k][j];
        }
      }
    }
    return result;
  }
};

Matrix ident(int N) {
  Matrix M(N);
  for (int i = 0; i < N; i++) M.M[i][i] = 1;
  return M;
}

Matrix pow(Matrix const& M, int e) {
  if (e == 0) return ident(M.N);
  Matrix h = pow(M, e/2);
  h = h * h;
  if (e % 2) h = h * M;
  return h;
}
//}}}

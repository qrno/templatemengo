struct Matrix {
  int N;
  V<V<mint>> M;
  Matrix (int N) : N(N), M(N, V<mint>(N)) {}
  Matrix operator*(Matrix const& rhs) {
    Matrix result(N);
    loop (i, N) loop (j, N) loop (k, N) {
      result.M[i][j] += M[i][k] * rhs.M[k][j];
    }
    return result;
  }
};

Matrix ident(int n) {
  Matrix M(n);
  loop (i, n) M.M[i][i] = 1;
  return M;
}

Matrix pow(Matrix const& M, int e) {
  if (e == 0) return ident(M.N);
  Matrix h = pow(M, e/2);
  h = h * h;
  if (e % 2) h = h * M;
  return h;
}


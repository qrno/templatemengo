// Prefix Sum {{{
int psum(vector<int> const& A, int l, int r) {
  if (r < l) return 0;
  return A[r] - (l ? A[l-1] : 0);
}
// }}}

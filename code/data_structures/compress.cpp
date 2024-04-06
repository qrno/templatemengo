// Compress Values {{{
map<int, int> compress(vector<int> A) {
  sort(begin(A), end(A));
  map<int, int> M;
  for (auto x : A) if (!M.count(x)) M[x] = size(M);
  return M;
}
//}}}

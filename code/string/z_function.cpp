// Z-Function {{{
vector<int> z_function(string const& S) {
  int N = size(S);
  vector<int> z(N);
  int l = 0, r = 0 ;
  for (int i = 1; i < N; i++) {
    if (i < r) z[i] = min(r-i, z[i-l]);
    while (i + z[i] < N && S[z[i]] == S[i+z[i]]) z[i]++;
    if (i + z[i] > r) {
      l = i;
      r = i+z[i];
    }
  }
  return z;
}
//}}}
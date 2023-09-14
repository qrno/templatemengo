vector<int> prefix_function(string const& S) {
  int N = size(S);
  vector<int> pi(N);
  for (int i = 1; i < N; i++) {
    int j = pi[i-1];
    while (j > 0 && S[i] != S[j]) j = pi[j-1];
    if (S[i] == S[j]) j++;
    pi[i] = j;
  }
  return pi;
}

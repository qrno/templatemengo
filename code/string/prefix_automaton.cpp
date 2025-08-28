// Prefix Automaton {{{
const int MALPHA = 26;

vector<vector<int>> prefix_automaton(string const& S) {
  auto pi = prefix_function(S);

  int N = size(S);
  vector<vector<int>> A(N+1, vector<int>(MALPHA));

  for (int i = 0; i <= N; i++) {
    for (int c = 0; c < MALPHA; c++) {
      if (i < size(S) && S[i]-'a' == c) {
        A[i][c] = i+1;
      } else {
        if (i == 0) A[i][c] = 0;
        else A[i][c] = A[pi[i-1]][c];
      }
    }
  }

  return A;
}
//}}}

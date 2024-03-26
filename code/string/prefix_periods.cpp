// Prefix Periods {{{
vector<vector<int>> prefix_periods(string const& S) {
  int N = size(S);
  auto Z = z_function(S);
  Z[0] = N;

  vector<vector<int>> P(N);
  for (int len = 1; 2*len <= N; len++)
    if (Z[0] >= len && Z[len] >= len)
      P[2*len-1].push_back(len);

  for (int i = 0; i < N-1; i++)
    for (auto p : P[i])
      if (Z[i+1] >= p)
        P[i+p].push_back(p);

  return P;
}
//}}}

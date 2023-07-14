vector<int> sort_cyclic_shifts(string const& s) {
  int N = s.size();

  vector<int> p(N);
  iota(begin(p), end(p), 0);
  sort(begin(p), end(p), [&](int x, int y) {
    return s[x] < s[y];
  });

  vector<int> eq(N);
  eq[p[0]] = 0;
  for (int i = 1; i < N; i++)
    eq[p[i]] = eq[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);

  for (int shift = 1; shift < N; shift *= 2) {
    vector<int> cnt(N);
    for (int i = 0; i < N; i++)
      cnt[eq[i]]++;
    partial_sum(begin(cnt), end(cnt), begin(cnt));

    vector<int> tmp(N);
    for (int i = 0; i < N; i++)
      tmp[N - 1 - i] = (p[i] - shift + N) % N;
    for (auto i : tmp)
      p[--cnt[eq[i]]] = i;

    auto key = [&](int x) {
      return pair(eq[x], eq[(x + shift) % N]);
    };

    tmp[p[0]] = 0;
    for (int i = 1; i < N; i++)
      tmp[p[i]] = tmp[p[i - 1]] + (key(p[i]) != key(p[i - 1]));
    swap(tmp, eq);
  }

  return p;
}

vector<int> suffix_array(string s) {
  s += '$';
  return sort_cyclic_shifts(s);
}

vector<int> kasai(string const& s, vector<int> const& p) {
  int N = size(s);
  vector<int> rank(N);
  for (int i = 0; i < N; i++)
    rank[p[i]] = i;

  int k = 0;
  vector<int> lcp(N-1);
  for (int i = 0; i < N; i++) {
    if (rank[i] == N-1) {
      k = 0;
      continue;
    }
    int j = p[rank[i] + 1];
    while (i + k < N && j + k < N && s[i+k] == s[j+k]) k++;
    lcp[rank[i]] = k;
    if (k) k--;
  }

  return lcp;
}


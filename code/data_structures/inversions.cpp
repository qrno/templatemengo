int inversions(vector<int> const& A) {
  ordered_set<pair<int, int>> OS;
  int ans = 0;
  for (int i = 0; i < size(A); i++) {
    ans += OS.size() - OS.order_of_key({A[i], i});
    OS.insert({A[i], i});
  }
  return ans;
}


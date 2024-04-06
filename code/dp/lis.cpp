// Longest Increasing Subsequence {{{
int lis(vector<int> const& A) {
  vector<int> most(size(A)+1, numeric_limits<int>::max());

  int ans = 0;
  for (auto x : A) {
    auto lb = lower_bound(begin(most), end(most), x);
    *lb = x;
    ans = max(ans, (int)(lb - begin(most) + 1));
  }
  return ans;
}
//}}}

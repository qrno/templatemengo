// TODO: Fix this, for now it's just for reference
// CHT Deque {{{
#include <bits/stdc++.h>
using namespace std;

#define int long long

int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); }

using Line = pair<int, int>;
int inter(Line a, Line b) { return cdiv(b.second-a.second, a.first-b.first); }
int eval(Line a, int x) { return x * a.first + a.second; }

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int N, X;
  cin >> N >> X;

  vector<int> S(N), F(N);
  for (auto &x : S) cin >> x;
  for (auto &x : F) cin >> x;

  deque<Line> D;
  D.push_back({X, 0});

  for (int i = 0; i < N; i++) {
    while (size(D) >= 2 && inter(D[0], D[1]) <= S[i]) D.pop_front();
    int val = eval(D[0], S[i]);

    Line l{F[i], val};
    if (end(D)[-1].first == l.first) continue;

    while (size(D) >= 2 && inter(end(D)[-2], end(D)[-1]) >= inter(end(D)[-1], l)) D.pop_back();
    D.push_back(l);
  }

  cout << eval(D.front(), S.back()) << endl;
}
//}}}

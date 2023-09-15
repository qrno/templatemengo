#include <bits/stdc++.h>
using namespace std;

#define int long long

template<class Node>
class Seg {
  int N;
  vector<Node> T;
public:
  explicit Seg(int N) : N(N), T(2*N) {}
  Node query(int l, int r) {
    Node rl, rr;
    for (l+=N, r+=N+1; l<r; l/=2, r/=2) {
      if (l&1) rl = rl+T[l++];
      if (r&1) rr = T[--r]+rr;
    }
    return rl+rr;
  }
  void update(int p, Node const& val) {
    for (T[p+=N]=val; p /= 2;)
      T[p] = T[2*p]+T[2*p+1];
  }
};

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;

  struct Node {
    int x;
    Node() : x(0) {}
    Node(int x) : x(x) {}
    Node operator+(Node const& b) {
      return Node(x + b.x);
    }
  };
  Seg<Node> st(N);

  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    st.update(i, x);
  }

  while (Q--) {
    int op; cin >> op;
    if (op == 1) {
      int p, x; cin >> p >> x; p--;
      st.update(p, x);
    } else {
      int l, r; cin >> l >> r; l--, r--;
      cout << st.query(l, r).x << endl;
    }
  }
}

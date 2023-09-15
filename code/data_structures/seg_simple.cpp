#include <bits/stdc++.h>
using namespace std;

// Template (v1.5.0 - 2023-07-17) (codeforces:cebolinha, atcoder:edu) {{{
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using ii = pair<int, int>;
using iii = array<int, 3>;

#define V vector
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(x) (int) (x).size()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define nemo ><>
#define loop(ii, n) for (int ii = 0; ii < (n); ii++)
#define cond(c, t, f) ((c) ? (t) : (f))
#define mem(a, b) memset((a), (b), sizeof(a))
#define inbounds(x, l, r) ((l) <= (x) && (x) <= (r))
#define L1(res...) [&](auto const& x){ return res; }
#define L2(res...) [&](auto const& x, auto const& y){ return res; }

template<class T, class U> inline void miq(T& a, U b){ if (a > b) a = b; }
template<class T, class U> inline void maq(T& a, U b){ if (a < b) a = b; }

template<class T, class U> auto &operator>>(istream &is, pair<T, U> &p) { return is >> p.ff >> p.ss; }
template<class T, class U> auto &operator<<(ostream &os, pair<T, U> const& p) { return os << '(' << p.first << ' ' << p.second << ')'; }

const auto ES = "", SEP = " ";
template<class T> auto &operator>>(istream& is, vector<T> &c) { for (auto &x : c) is >> x; return is; }
template<class T> auto &operator<<(ostream& os, vector<T> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class T> auto &operator<<(ostream& os, set<T> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class T> auto &operator<<(ostream& os, multiset<T> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class T> auto &operator<<(ostream& os, unordered_set<T> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class T> auto &operator<<(ostream& os, ordered_set<T> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class T> auto &operator<<(ostream& os, deque<T> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class K, class V> auto &operator<<(ostream& os, map<K,V> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class K, class V> auto &operator<<(ostream& os, unordered_map<K,V> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }

template<class... A> void in(A &...a) { ((cin >> a), ...); }
template<class... A> void out(A const&... a) { auto sep = ES; ((cout << sep << a, sep = SEP), ...); cout << '\n'; }
template<class... A> void print(A const&... a) { ((cout << a), ...); }
#define var(x) "[", #x, " ", x, "] "
template<class... A> void db(A const&... a) { ((cout << (a)), ...); cout << endl; }
//}}}

template<typename T>
class SegmentTree {
  int n;
  T neutral;
  V<T> t;
  std::function<T(T,T)> merge;
public:
  SegmentTree(int n, T neutral,
              std::function<T(T,T)> merge) {
    this->n = n;
    this->neutral = neutral;
    this->merge = merge;
    t.assign(2*n, neutral);
  }

  SegmentTree(V<T> &v, T neutral,
              std::function<T(T,T)> merge) {
    this->n = v.size();
    this->neutral = neutral;
    this->merge = merge;
    t.assign(2*n, neutral);
    loop (i, n) t[i+n] = v[i];
    build();
  }

  void build() {
    for (int i=n-1; i>0; i--)
      t[i]=merge(t[2*i],t[2*i+1]);
  }

  T query(int l, int r) {
    T rl = neutral, rr = neutral;
    for (l+=n, r+=n+1; l<r; l/=2, r/=2) {
      if (l&1) rl = merge(rl, t[l++]);
      if (r&1) rr = merge(t[--r], rr);
    }
    return merge(rl, rr);
  }

  void update(int p, T val) {
    for (t[p+=n]=val; p > 1; p /= 2)
      t[p/2] = merge(t[min(p, p^1)], t[max(p, p^1)]);
  }
};

auto main() -> signed {
  fastio;

  int N, Q; in(N, Q);
  V<int> A(N); in(A);
  SegmentTree<int> ST(A, 0, L2(x+y));
  while (Q--) {
    int op; in(op);
    if (op == 1) {
      int p, x; in(p, x); p--;
      ST.update(p, x);
    } else {
      int l, r; in(l, r); l--, r--;
      out(ST.query(l, r));
    }
  }
}


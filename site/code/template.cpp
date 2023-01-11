#include <bits/stdc++.h>
using namespace std;

// Template (v1.3.0 - 2023-01-11) (codeforces:cebolinha, atcoder:edu) {{{

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

template<class T> using V = vector<T>;
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;

#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define nemo ><>
#define loop(ii, n) for (int ii = 0; ii < (n); ii++)
#define cond(c, t, f) ((c) ? (t) : (f))
#define mem(a, b) memset((a), (b), sizeof(a))
#define inbounds(x, l, r) ((l) <= (x) && (x) <= (r))
#define L1(res...) [&](auto x){ return res; }
#define L2(res...) [&](auto x, auto y){ return res; }

template<class T, class U> inline void miq(T& a, U b){if (a > b) a = b;}
template<class T, class U> inline void maq(T& a, U b){if (a < b) a = b;}

template<class T> istream &operator>>(istream &is, vector<T> &v) { for (auto &a : v) is >> a; return is; }
template<class T, class U> ostream &operator<<(ostream &os, pair<T, U> const& p) { os << "(" << p.first << " " << p.second << ")"; return os; }
template<class T> ostream &operator<<(ostream &os, vector<T> const& v) { for (int i = 0; i < v.size(); i++) os << cond(i," ","") << v[i]; return os; }
template<class T, class U> ostream &operator<<(ostream &os, map<T, U> const& m) { bool first = true; for (auto const& [k, v] : m) { if (!first) os << " "; first = false; os << "{" << k << " : " << v << "}"; } return os; }
template<class T> ostream &operator<<(ostream &os, set<T> const& s) { for (auto it = s.begin(); it != s.end(); it++) os << cond(it != s.begin()," ","") << *it; return os; }

template<class... A> void in(A &...a) { ((cin >> a), ...); }
template<class... A> void out(A const&... a) { ((cout << a << " "), ...); cout << endl; }
template<class... A> void print(A const&... a) { ((cout << a), ...); }
#define var(x) "[", #x, " ", x, "] "
template<class... A> void db(A const&... a) { ((cout << (a)), ...); cout << endl; }
//}}}

auto main() -> signed {
  fastio;

}

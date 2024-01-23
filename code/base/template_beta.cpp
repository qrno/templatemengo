#include <bits/stdc++.h>
using namespace std;

// Template (v2.0.0 beta - 2024-01-01) (codeforces:cebolinha, atcoder:edu) {{{
#define tcT template<class T
#define tcTU tcT, class U
#define tcA template<class...A

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
tcT> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long

#define V vector
tcT> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using str = string;
using ii = pair<int, int>;
using iii = array<int, 3>;

#define all(C) begin(C), end(C)
#define rall(C) rbegin(C), rend(C)
#define allb(C) begin(C), end(C), begin(C)
#define sz(C) ((int)size(C))

#define tp top()
#define ft front()
#define bk back()
#define pb push_back
#define ins insert
#define ff first
#define ss second
#define nemo ><>

#define iloop(I,L,R) for (int I = (L); I <= (R); I++)
#define loop(I,N) iloop(I,0,(N)-1)
#define rep(N) loop(_, N)
#define ipool(I,L,R) for (int I = (R); I >= (L); I--)
#define pool(I,N) ipool(I,0,(N)-1)
#define tloop int __T; cin >> __T; while (__T--)
#define each(X,C) for(auto &X : (C))
#define eachc(X,C) for(auto const& X : (C))
#define apply(C,L) each(x,C) L;

#define cond(C, T, F) ((C) ? (T) : (F))
#define mem(C, X) memset((C), (X), sizeof(C))
#define ibi(X, L, R) ((L) <= (X) && (X) <= (R))
#define ib(X, N) ((0) <= (X) && (X) <= (N-1))
#define L1(X...) [&](auto const& x){ return X; }
#define L2(X...) [&](auto const& x, auto const& y){ return X; }

tcTU> inline bool chmax(T &a, U const& b) { return (a < b ? a = b, 1 : 0); }
tcTU> inline bool chmin(T &a, U const& b) { return (a > b ? a = b, 1 : 0); }

int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); }
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); }

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

tcTU> auto &operator>>(istream &is, pair<T, U> &p) { return is >> p.ff >> p.ss; }
tcTU> auto &operator<<(ostream &os, pair<T, U> const& p) { return os << '{' << p.first << ' ' << p.second << '}'; }
tcT> auto &operator>>(istream& is, vector<T> &C) { for (auto &x : C) is >> x; return is; }

tcT> struct is_container : std::false_type {};
#define __ADDC(C) tcA> struct is_container<C<A...>> : std::true_type {};
__ADDC(vector); __ADDC(set); __ADDC(multiset); __ADDC(unordered_set); __ADDC(map); __ADDC(unordered_map);

const auto __ES = "", __SEP = " ";
tcT> enable_if<is_container<T>::value, ostream>::type &operator<<(ostream& os, T const &C) { auto sep = __ES; each(x, C) os << sep << x, sep = __SEP; return os; }
tcT> auto &operator<<(ostream& os, ordered_set<T> const &C) { auto sep = __ES; each(x, C) os << sep << x, sep = __SEP; return os; }

tcA> void in(A &...a) { ((cin >> a), ...); }
tcA> void out(A const&... a) { auto sep = __ES; ((cout << sep << a, sep = __SEP), ...); cout << '\n'; }
tcA> void print(A const&... a) { ((cout << a), ...); }
#define var(x) "[", #x, " ", x, "] "
#ifdef LOCAL
tcA> void db(A const&... a) { ((cout << (a)), ...); cout << endl; }
#else
tcA> void db(A const&... a) {}
#endif
//}}}

auto main() -> signed {
  fastio;

}


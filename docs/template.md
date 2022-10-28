# Template

## Base Template

A small collection of abbreviations and macros that are used very frequently.

There is also a `#define int long long` in the beginning of the file. This usually doubles the memory usage of integers, but that rarely causes problems. The benefits of not getting overflow errors make it worth it.

There are also two very useful functions `miq` and `maq`.
`miq(a, b)` makes `a` the minimum between `a` and `b`, whereas `maq(a, b)` makes a the maximum between `a` and `b`.

!!! warning "Loop bounds"
    `loop(i, n)` loops through (0 ≤ i < n) `xloop(i, l, r)` loops through (l ≤ i ≤ r).

```cpp title="Base template"
#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename T> using V = vector<T>;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;

#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(v) (int)v.size()
#define loop(ii, n) for (int ii = 0; ii < (n); ++ii)
#define xloop(ii, l, r) for (int ii = (l); ii <= (r); ++ii) // (1)!
#define cond(c, t, f) ((c) ? (t) : (f))
#define mem(a, b) memset(a, (b), sizeof(a))
#define inbounds(x, l, r) ((l) <= (x) && (x) <= (r))
#define nemo ><>

#define ff first
#define ss second

#define pb push_back
#define eb emplace_back

template<typename T, typename U> inline void miq(T& a, U& const b){if (a > b) a = b;}
template<typename T, typename U> inline void maq(T& a, U& const b){if (a < b) a = b;}

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
signed main() { fastio
}
```

## Better I/O

These three functions can be used to make `cin` and `cout` a little more ergonomic.

!!! warning "Space at the end of out"
    Out produces a space at the end of the line, before `endl`.
    Some online judges may complain about that.
    Happens a lot on sites like Beecrowd, UVa, and Codeforces Gyms.

```cpp title="Better I/O"
template <typename... A> void in(A &...a) {
  ((cin >> a), ...);
}
template <typename... A> void out(A... a) {
  ((cout << a << " "), ...); cout << endl;
}
template <typename... A> void print(A... a) {
  ((cout << a), ...);
}
```

```cpp title="Usage example"
in(x, y, z);
// same as cin >> x >> y >> z
out(x, y, z);
// same as cout << x << " " << y << " " << z << " " << endl;
print(x, y, z);
// same as cout << x << y << z;
```

## Container I/O

Very useful functions that allow you to read and output vectors in a compact way.
Can be used with the "Better I/O" or regular "iostream" functions.

```cpp title="Container I/O"
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &a : v) is >> a;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
  loop(i, sz(v)) os << cond(i," ","") << v[i];
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> v) {
  for (auto it = v.begin(); it != v.end(); it++)
    os << cond(it != v.begin()," ","") << *it;
  return os;
}
```

```cpp title="Usage examples"
V<int> v(n); in(v); out(v);
V<int> v(n); cin >> v; cout << v;
set<int> S{1, 2, 3}; out(s);
```

## Debug macro

Prints a variable's name next to its name.

```cpp title="Debug Macro"
#define var(x) "[", #x, " ", x, "] "
template <typename... A> void db(A... a) {
  ((cout << var(a)), ...); cout << endl;
}
```

```cpp title="Usage example"
int x = 5; db(x);
// [x 5]
V<int> v{1, 2, 3}; db(v);
// [v 1 2 3]
```

## Pragmas

Enables some GCC optimizations which can make some kinds of code run faster.
Reference
[this Codeforces blog by nor](https://codeforces.com/blog/entry/96344)
for details on what pragmas do and when to use them.

```cpp title="Pragmas"
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
```

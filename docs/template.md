# Template

## Full Template

```cpp title="Full template"
--8<-- "template.cpp"
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
in(x, y, z); // cin >> x >> y >> z
out(x, y, z); // cout << x << " " << y << " " << z << " " << endl;
print(x, y, z); // cout << x << y << z;
```

## Container I/O

Very useful functions that allow you to read and output vectors in a compact way.
Can be used with the "Better I/O" or regular "iostream" functions.

```cpp title="Container I/O"
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &a : v) is >> a;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> v) {
  loop(i, sz(v)) os << cond(i," ","") << v[i];
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
int x = 5; db(x); // [x 5]
V<int> v{1, 2, 3}; db(v); // [v 1 2 3]
```

## Pragmas

Enables some GCC optimizations which can make some kinds of code run faster.
Reference
[this Codeforces blog by nor](https://codeforces.com/blog/entry/96344) for details on what pragmas do and when to use them.

```cpp title="Pragmas"
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
```

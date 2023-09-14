#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using T = ld;

const ld EPS = 1e-6;
const ld PI = acos(-1);

bool eq(T a, T b) { return abs(a-b) <= EPS; }

struct Point {
  T x, y;
  Point (T x=0, T y=0) : x(x), y(y) {}

  Point operator+(Point const& o) const { return { x + o.x, y + o.y}; }
  Point operator-(Point const& o) const { return { x - o.x, y - o.y}; }
  Point operator*(T t) const { return {x * t, y * t}; }
  Point operator/(T t) const { return {x / t, y / t}; }

  T operator*(Point const& o) const { return x * o.x + y * o.y; }
  T operator^(Point const& o) const { return x * o.y - y * o.x; }

  bool operator<(Point const& o) const {
    if (eq(x, o.x)) return y < o.y;
    return x < o.x;
  }
  bool operator==(Point const& o) const {
    return eq(x, o.x) && eq(y, o.y);
  }

  friend auto& operator<<(auto& os, Point const& p) {
    return os << "(" << p.x << ' ' << p.y << ")";
  }
};

enum Direction {
  Left  = -1,
  Coll  =  0,
  Right = +1,
};

// Which side of AB> is x?
Direction side(Point const& a, Point const& b, Point const& x) {
  auto t = (b-a) ^ (x-a);
  return static_cast<Direction>((t > EPS) - (t < -EPS));
}

ld norm(Point const& a) { return sqrt(a * a); }
T norm2(Point const& a) { return a * a; }

bool null(Point const& a) {
  return eq(a.x, 0) && eq(a.y, 0);
}

ld to_deg(ld rad) { return PI * rad / 180.0; }
ld to_rad(ld deg) { return 180.0 * deg / PI; }

Point rotccw(Point a, ld ang) {
  return {a.x * cos(ang) - a.y * sin(ang),
          a.y * cos(ang) + a.x * sin(ang)};
}

Point rot90cw (Point const& a) { return { a.y, -a.x}; }
Point rot90ccw(Point const& a) { return {-a.y,  a.x}; }

ld proj(Point const& a, Point const& b) {
  return a * b / norm(b);
}

ld angle(Point const& a, Point const& b) {

}

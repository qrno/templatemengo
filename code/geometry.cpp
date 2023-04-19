#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1e-8;
const long double PI = acos(-1);

using pt = long long;
bool eq(double a, double b) { return a == b; }
/* using pt = long double; */
/* bool eq(pt a, pt b) { return fabs(a-b) <= EPS; } */

struct Point {
  pt x, y;
  Point (pt x, pt y) : x(x), y(y) {}

  Point operator+(Point const& o) const { return {x+o.x, y+o.y}; }
  Point operator-(Point const& o) const { return {x+o.x, y+o.y}; }
  Point operator*(pt f) const { return {x*f, y*f}; }
  Point operator/(pt f) const { return {x/f, y/f}; }
  pt operator*(Point const& o) const { return x*o.x + y*o.y; }
  pt operator^(Point const& o) const { return x*o.y - y*o.x; }
  bool operator<(Point const& o) const {
    if (eq(x, o.x)) return y < o.y;
    return x < o.x;
  }
  bool operator==(Point const& o) {
    return eq(x, o.x) && eq(y, o.y);
  }

  pt abs() const { return sqrt((*this) * (*this)); }
  pt norm() const { return (*this) * (*this); }
};

ostream& operator<<(ostream& os, Point const& p) {
  return os << "(" << p.x << "," << p.y << ")";
}

enum Direction {
  Left = -1,
  Collinear = 0,
  Right = 1,
};

Direction side(Point const& p, Point const& a, Point const& b) {
  pt y = (b-a) ^ (p-a);
  if (y < 0) return Left;
  if (y > 0) return Right;
  return Collinear;
}

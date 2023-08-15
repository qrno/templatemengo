#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1e-8;

using pt = long long;
bool eq(double a, double b) { return a == b; }
/* using pt = long double; */
/* bool eq(pt a, pt b) { return fabs(a-b) <= EPS; } */

struct Point {
  pt x, y;
  Point () : x(0), y(0) {}
  Point (pt x, pt y) : x(x), y(y) {}

  Point operator+(Point o) const { return {x+o.x, y+o.y}; }
  Point operator-(Point o) const { return {x-o.x, y-o.y}; }
  Point operator*(pt f) const { return {x*f, y*f}; }
  Point operator/(pt f) const { return {x/f, y/f}; }
  pt operator*(Point o) const { return x*o.x + y*o.y; }
  pt operator^(Point o) const { return x*o.y - y*o.x; }
  bool operator<(Point o) const {
    if (eq(x, o.x)) return y < o.y;
    return x < o.x;
  }
  bool operator==(Point o) {
    return eq(x, o.x) && eq(y, o.y);
  }

  pt abs() const { return sqrt((*this) * (*this)); }
  pt norm() const { return (*this) * (*this); }
};

ostream& operator<<(ostream& os, Point p) {
  return os << "(" << p.x << "," << p.y << ")";
}

enum Side {
  Left = -1,
  Collinear = 0,
  Right = 1,
};

Side side(Point p, Point a, Point b) {
  pt y = (b-a) ^ (p-a);
  if (y > 0) return Left;
  if (y < 0) return Right;
  return Collinear;
}

#include <bits/stdc++.h>
using namespace std;
//{{{ Geometry Base
const long double EPS = 1e-9;

template<typename T>
bool eq(T const& a, T const& b) {
  return abs(a-b) <= EPS;
}

template<typename T>
struct Point {
  T x, y;
  Point () : x(0), y(0) {}
  Point (T x, T y) : x(x), y(y) {}

  Point operator+(Point const& o) const { return { x+o.x, y+o.y }; }
  Point operator-(Point const& o) const { return { x-o.x, y-o.y }; }
  Point operator*(T const& t) const { return { x*t, y*t }; }
  Point operator/(T const& t) const { return { x/t, y/t }; }
  T operator*(Point const& o) const { return x*o.x + y*o.y; }
  T operator^(Point const& o) const { return x*o.y - y*o.x; }

  bool operator<(Point const& o) const {
    if (!eq(x, o.x)) return x < o.x;
    if (!eq(y, o.y)) return y < o.y;
    return 0;
  }

  bool operator==(Point const& o) const {
    return eq(x, o.x) && eq(y, o.y);
  }

  friend ostream& operator<<(ostream& os, Point const& p) {
    return os << p.x << ' ' << p.y;
  }

  friend istream& operator>>(istream& is, Point &p) {
    return is >> p.x >> p.y;
  }
};

template<typename T>
T norm(Point<T> const& a) {
  return sqrtl(a * a);
}

template<typename T>
T norm2(Point<T> const& a) {
  return a * a;
}

template<typename T>
Point<T> unit(Point<T> const& a) {
  return a / norm(a);
}

template<typename T>
Point<T> proj(Point<T> const& p, Point<T> const& a, Point<T> const& b) {
  T len = (p-a) * (b-a) / norm(b-a);
  return a + unit(b-a) * len;
}

template<typename T>
Point<T> reflection(Point<T> const& p, Point<T> const& a, Point<T> const& b) {
  return p + 2*(proj(p, a, b)-p);
}

template<typename T>
T sarea(Point<T> const& a, Point<T> const& b, Point<T> const& c) {
  return ((b-a)^(c-b))/2;
}

template<typename T>
int side(Point<T> const& p, Point<T> const& a, Point<T> const& b) {
  T x = (b-a) ^ (p-a);
  return (x > EPS) - (x < -EPS);
}

template<typename T>
Point<T> rot(Point<T> const& p, long double a) {
  return Point{p.x * cos(a) - p.y * sin(a),
               p.y * cos(a) + p.x * sin(a)};
}

template<typename T>
Point<T> rot90cw(Point<T> const& a) {
  return Point{a.y, -a.x};
}

template<typename T>
Point<T> rot90ccw(Point<T> const& a) {
  return Point{-a.y, a.x};
}

// Everything is untested
template<typename T>
struct Line  {
  Point<T> p1, p2;
  T a, b, c;

  Line (Point<T> const& p1, Point<T> const& p2) : p1(p1), p2(p2),
    a(p1.y - p2.y),
    b(p2.x - p1.x),
    c(p1^p2) {}

  T eval(Point<T> const& p) const {
    return a * p.x + b * p.y + c;
  }

  bool inside(Point<T> const& p) const {
    return eq(eval(p), T());
  }

  bool inside_seg(Point<T> const& p) const {
    return eq(((p1-p) ^ (p2-p)), T())
           && ((p1-p) * (p2-p)) <= EPS;
  }
};

// Unlikely to work with integral T
template<typename T>
vector<Point<T>> inter_line(Line<T> const& l1, Line<T> const& l2) {
  auto det = l1.a*l2.b - l1.b*l2.a;
  if (eq(det, T())) return {};
  auto x = (l1.b*l2.c - l1.c*l2.b)/det;
  auto y = (l1.c*l2.a - l1.a*l2.c)/det;
  return {{x,y}};
}

// Segments with point overlap
template<typename T>
vector<Point<T>> inter_seg(Line<T> const& l1, Line<T> const& l2) {
  auto ans = inter_line(l1, l2);
  if (ans.empty()) return {};
  if (!l1.inside_seg(ans.front())) return {};
  if (!l2.inside_seg(ans.front())) return {};
  return ans;
}

template<typename T>
bool seg_has_inter(Line<T> const& l1, Line<T> const& l2) {
  if (side(l2.p1, l1.p1, l1.p2) * side(l2.p2, l1.p1, l1.p2) < 0
   && side(l1.p1, l2.p1, l2.p2) * side(l1.p2, l2.p1, l2.p2) < 0) return true;
  if (l1.inside_seg(l2.p1)) return true;
  if (l1.inside_seg(l2.p2)) return true;
  if (l2.inside_seg(l1.p1)) return true;
  if (l2.inside_seg(l1.p2)) return true;
  return false;
}

template<typename T>
T point_line_dist(Point<T> const& p, Line<T> const& l) {
  return 2 * abs(sarea(p, l.p1, l.p2)) / norm(l.p1-l.p2);
}

template<typename T>
T point_seg_dist(Point<T> const& p, Line<T> const& l) {
  if ((l.p2-l.p1)*(p-l.p1) < 0) return norm(l.p1-p);
  if ((l.p1-l.p2)*(p-l.p2) < 0) return norm(l.p2-p);
  return point_line_dist(p, l);
}

template<typename T>
T seg_dist(Line<T> const& l1, Line<T> const& l2) {
  if (seg_has_inter(l1, l2)) return T();
  return min({point_seg_dist(l1.p1, l2),
              point_seg_dist(l1.p2, l2),
              point_seg_dist(l2.p1, l1),
              point_seg_dist(l2.p2, l1)});
}

template<typename T>
struct Circle {
  Point<T> c;
  T r;
  Circle (Point<T> const& c,  T r) : c(c), r(r) {}
  bool inside(Point<T> const& a) const {
    return norm(a-c) <= r + EPS;
  }
};

template<typename T>
vector<Point<T>> inter_circle(Circle<T> const& c1, Circle<T> const& c2) {
  if (c1.c == c2.c) return {};
  Point vec = c2.c - c1.c;
  T d2 = vec * vec;
  T sum = c1.r + c2.r;
  T dif = c1.r - c2.r;
  T p = (d2 + c1.r * c1.r - c2.r * c2.r) / (2 * d2);
  T h2 = c1.r * c1.r - p * p * d2;
  if (sum * sum < d2 || dif * dif > d2) return {};
  Point mid = c1.c + vec*p;
  Point per = Point(-vec.y, vec.x) * sqrt(max(T(), h2) / d2);
  if (per == Point<T>()) return {mid};
  return {mid + per, mid - per};
}

template<typename T>
bool inside(Point<T> const& p, Point<T> const& a, Point<T> const& b, Point<T> const& c) {
  int x = side(p, a, b);
  int y = side(p, b, c);
  int z = side(p, c, a);
  return !((x == 1 or y == 1 or z == 1) and (x==-1 or y == -1 or z == -1));
}

template<typename T>
bool inside(Point<T> const& p, vector<Point<T>> const& poly) {
  int bl = 2, br = (int)size(poly) - 1;
  while (bl < br) {
    /* int bm = midpoint(bl, br); */
    int bm = (bl+br)/2;
    if (side(p, poly[0], poly[bm]) == 1) bl = bm+1;
    else br = bm;
  }

  return inside(p, poly[0], poly[br-1], poly[br]);
}

template<typename T>
using Poly = vector<Point<T>>;

template<typename T>
T area(Poly<T> const& P) {
  int N = size(P);
  T total{};
  for (int i = 0; i < N; i++) {
    total += P[i].x * P[(i+1)%N].y;
    total -= P[i].y * P[(i+1)%N].x;
  }
  return abs(total/2);
}
//}}}

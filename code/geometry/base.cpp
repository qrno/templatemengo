#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

}

//{{{ Geometry Base
const long double EPS = 1e-9;

template<typename T>
T sq(T x) { return x*x; }

template<typename T>
bool eq(T const& a, T const& b) {
  return abs(a-b) <= EPS;
}

template<>
bool eq<int>(int const& a, int const& b) {
  return a == b;
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

  bool operator!=(Point const& o) const {
    return !(*this == o);
  }

  friend ostream& operator<<(ostream& os, Point const& p) {
    return os << p.x << ' ' << p.y;
  }

  friend istream& operator>>(istream& is, Point &p) {
    return is >> p.x >> p.y;
  }
};

template<typename T>
long double norm(Point<T> const& a) {
  return sqrtl(a * a);
}

template<typename T>
long double norm(Point<T> const& a, Point<T> const& b) {
  return norm(a-b);
}

template<typename T>
T norm2(Point<T> const& a) {
  return a * a;
}

template<typename T>
T norm2(Point<T> const& a, Point<T> const& b) {
  return norm2(a-b);
}

template<typename T>
Point<T> unit(Point<T> const& a) {
  return a / norm(a);
}

template<typename T>
T proj_len(Point<T> const& p, Point<T> const& a, Point<T> const& b) {
  T len = (p-a) * (b-a) / norm(b-a);
  return len;
}

template<typename T>
Point<T> proj(Point<T> const& p, Point<T> const& a, Point<T> const& b) {
  return a + unit(b-a) * proj_len(p, a, b);
}

template<typename T>
Point<T> reflection(Point<T> const& p, Point<T> const& a, Point<T> const& b) {
  return p + 2*(proj(p, a, b)-p);
}

template<typename T>
T sarea(Point<T> const& a, Point<T> const& b, Point<T> const& c) {
  return ((b-a)^(c-b))/2;
}

// left = +1
// collinear = 0
// right = -1
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

template<typename T>
Point<T> transp(Point<T> const& a) {
  return Point{a.y, a.x};
}

// Everything is untested
template<typename T>
struct Line  {
  Point<T> p1, p2;
  T a, b, c;

  Line () {}

  Line (Point<T> const& p1, Point<T> const& p2) : p1(p1), p2(p2),
    a(p1.y - p2.y),
    b(p2.x - p1.x),
    c(p1^p2) {}

  Line (T a, T b, T c) : a(a), b(b), c(c) {
    if (b == 0) {
      p1 = Point<T>(1, -c/a);
      p2 = Point<T>(0, -c/a);
    } else {
      p1 = Point<T>(1, (-c-a*1)/b);
      p2 = Point<T>(0, -c/b);
    }
  }

  bool operator<(Line const& o) const {
    if (p1 != o.p1) return p1 < o.p1;
    if (p2 != o.p2) return p2 < o.p2;
    return 0;
  }

  T eval(Point<T> const& p) const {
    return a * p.x + b * p.y + c;
  }

  T eval(T const& x) const {
    return (-c-a*x)/b;
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
// WARN: Doesn't work with a line that is a single point
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
vector<Point<T>> inter_seg_proper(Line<T> const& l1, Line<T> const& l2) {
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
vector<Point<T>> inter_seg(Line<T> const& l1, Line<T> const& l2) {
  if (!seg_has_inter(l1, l2)) return {};

  vector<Point<T>> ps;
  if (l1.inside_seg(l2.p1)) ps.push_back(l2.p1);
  if (l1.inside_seg(l2.p2)) ps.push_back(l2.p2);
  if (l2.inside_seg(l1.p1)) ps.push_back(l1.p1);
  if (l2.inside_seg(l1.p2)) ps.push_back(l1.p2);
  sort(begin(ps), end(ps));
  ps.erase(unique(begin(ps), end(ps)), end(ps));

  if (size(ps) == 1) return {ps.front()};
  else if (size(ps) > 1) return {ps.front(), ps.back()};

  return {inter_seg_proper(l1, l2).front()};
}

template<typename T>
T point_line_dist(Point<T> const& p, Line<T> const& l) {
  if (l.p1 == l.p2) return norm(l.p1-p);
  return 2 * abs(sarea(p, l.p1, l.p2)) / norm(l.p1-l.p2);
}

template<typename T>
T point_seg_dist(Point<T> const& p, Line<T> const& l) {
  if (l.p1 == l.p2) return norm(l.p1-p);
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

// TODO: Convert inside(pt, pt, pt, pt) and inside_convex(pt, poly) to use "Where" enum (?)

template<typename T>
bool inside(Point<T> const& p, Point<T> const& a, Point<T> const& b, Point<T> const& c) {
  int x = side(p, a, b);
  int y = side(p, b, c);
  int z = side(p, c, a);
  return !((x == 1 or y == 1 or z == 1) and (x==-1 or y == -1 or z == -1));
}

template<typename T>
using Poly = vector<Point<T>>;

template<typename T>
bool inside_convex(Point<T> const& p, Poly<T> const& poly) {
  int bl = 2, br = (int)size(poly) - 1;
  while (bl < br) {
    /* int bm = midpoint(bl, br); */
    int bm = (bl+br)/2;
    if (side(p, poly[0], poly[bm]) == 1) bl = bm+1;
    else br = bm;
  }

  return inside(p, poly[0], poly[br-1], poly[br]);
}

enum Where {
  Inside = 1,
  Outside = -1,
  Boundary = 0,
};

template<typename T>
Where inside_simple(Point<T> const& p, Poly<T> const& A) {
  int N = size(A);
  int w = 0;
  for (int i = 0; i < N; i++) {
    if (p == A[i]) return Boundary;
    int j = (i+1)%N;
    if (A[i].y == p.y && A[j].y == p.y) {
      if (min(A[i].x, A[j].x) <= p.x && p.x <= max(A[i].x, A[j].x))
        return Boundary;
    } else {
      bool ibelow = A[i].y < p.y;
      bool jbelow = A[j].y < p.y;
      if (ibelow != jbelow) {
        auto o = side(p, A[i], A[j]);
        if (o == 0) return Boundary;
        if (ibelow == (o > 0)) w += (ibelow ? +1 : -1);
      }
    }
  }

  return (w ? Inside : Outside);
}

template<typename T>
long double sarea(Poly<T> const& P) {
  int N = size(P);
  long double total = 0;
  for (int i = 0; i < N; i++) {
    total += P[i].x * P[(i+1)%N].y;
    total -= P[i].y * P[(i+1)%N].x;
  }
  return total/2;
}

template<typename T>
long double area(Poly<T> const& P) {
  return abs(sarea(P));
}

template<typename T>
bool clockwise(Poly<T> const& P) {
  return sarea(P) < 0;
}

template<typename T>
Poly<T> convex_hull(Poly<T> P) {
  sort(begin(P), end(P));

  vector<Point<T>> L, U;
  for (auto p : P) {
    while (size(L) >= 2 && side(p, end(L)[-2], end(L)[-1]) != 1) L.pop_back();
    L.push_back(p);
  }
  reverse(begin(P), end(P));
  for (auto p : P) {
    while (size(U) >= 2 && side(p, end(U)[-2], end(U)[-1]) != 1) U.pop_back();
    U.push_back(p);
  }
  L.pop_back();
  L.insert(end(L), begin(U), end(U)-1);
  return L;
}

template<typename T>
T polygon_cut_length(Poly<T> const& A, Line<T> const& l) {
  int N = size(A);
  auto a = l.p1, b = l.p2;

  T ans{};
  for (int i = 0; i < N; i++) {
    int j = (i+1)%N;

    int si = side(A[i], a, b);
    int sj = side(A[j], a, b);

    if (si == 0 && sj == 0) {
      if ((b-a)*(A[j]-A[i]) > 0) {
        ans += proj_len(A[j], a, b);
        ans -= proj_len(A[i], a, b);
      }
    } else if (si <= 0 && sj > 0) {
      auto it = inter_line(l, {A[i], A[j]}).front();
      ans -= proj_len(it, a, b);
    } else if (si > 0 && sj <= 0) {
      auto it = inter_line(l, {A[i], A[j]}).front();
      ans += proj_len(it, a, b);
    }
  }

  return abs(ans);
}


template<typename T>
pair<Point<T>, Point<T>> closest_pair(vector<Point<T>> P) {
  const long double CP_INF = 1e18;

  pair<long double, pair<Point<T>, Point<T>>> best;
  best.first = CP_INF;

  set<Point<T>> S;
  sort(begin(P), end(P));

  int il = 0;
  for (int ir = 0; ir < size(P); ir++) {
    if (ir && P[ir] == P[ir-1]) return {P[ir], P[ir-1]};
    while (P[ir].x-P[il].x >= best.first) {
      S.erase(transp(P[il]));
      il++;
    }
    for (auto it = S.upper_bound({P[ir].y-best.first, CP_INF});
        it != end(S) && it->x < P[ir].y+best.first;
        it++) {
      auto p = transp(*it);
      best = min(best, {norm(P[ir], p), pair{P[ir], p}});
    }
    S.insert(transp(P[ir]));
  }
  return best.second;
}
//}}}


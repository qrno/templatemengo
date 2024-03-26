// Color Update {{{
template<class T = long long>
struct ColorUpdate {
  struct Range {
    int l, r;
    T x;

    Range(int l) : l(l) {}
    Range(int l, int r, T x) : l(l), r(r), x(x) {}
    bool operator<(const Range& o) const { return l < o.l; }
  };

  set<Range> ranges;
  vector<Range> update(int l, int r, T x) {
    if (l > r) return {};

    auto it = ranges.lower_bound(l);
    if (it != begin(ranges)) {
      it--;
      if (it->r >= l) {
        auto cur = *it;
        ranges.erase(it);
        ranges.insert(Range(cur.l, l-1, cur.x));
        ranges.insert(Range(l, cur.r, cur.x));
      }
    }
    it = ranges.lower_bound(r+1);
    if (it != begin(ranges)) {
      it--;
      if (it->r > r) {
        auto cur = *it;
        ranges.erase(it);
        ranges.insert(Range(cur.l, r, cur.x));
        ranges.insert(Range(r+1, cur.r, cur.x));
      }
    }

    vector<Range> ans;
    for (auto it = ranges.lower_bound(l); it != end(ranges) && it->l <= r; it++) {
      ans.push_back(*it);
    }
    ranges.erase(ranges.lower_bound(l), ranges.lower_bound(r+1));
    ranges.insert(Range(l, r, x));
    return ans;
  }
};
//}}}

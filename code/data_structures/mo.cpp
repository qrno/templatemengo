// Mo's Algorithm {{{
const int BLK = 400;
struct MoQuery {
  int l, r, idx;
  bool operator<(MoQuery const& o) const {
    if (l/BLK != o.l/BLK) return l < o.l;
    if (l/BLK % 2 == 0) return r < o.r;
    else return r > o.r;
  }
};
//}}}


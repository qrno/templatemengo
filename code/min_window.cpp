struct MinWindow {
  int W;
  deque<pair<int, int>> Q;

public:
  explicit MinWindow(int W) : W(W) {}

  void push(int idx, int x) {
    while (Q.front().ff < idx-W+1) Q.pop_front();
    while (!Q.empty() && Q.back().ss >= x) Q.pop_back();
    Q.pb({idx, x});
  }

  int get() const { return Q.front().ss; }
};


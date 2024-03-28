// Minimum Treap {{{
template<typename T>
struct Node {
  T X;
  int P, S;
  int mini;
  Node *L, *R;
  Node (T x) : X(x), mini(x), P(rng()), S(1), L(nullptr), R(nullptr) {}

  void update() {
    S = 1 + gsize(L) + gsize(R);
    mini = min({X, gmin(L), gmin(R)});
  }
};

template<typename T>
int gsize(Node<T>* t) { return t ? t->S : 0; }

template<typename T>
int gmin(Node<T>* t) { return t ? t->mini : 1e9; }

template<typename T>
pair<Node<T>*, Node<T>*> split(Node<T> *t, int cnt) {
  if (!t) return {nullptr, nullptr};

  if (gsize(t->L) < cnt) {
    auto [l, r] = split(t->R, cnt-gsize(t->L)-1);
    t->R = l;
    t->update();
    return {t, r};
  } else {
    auto [l, r] = split(t->L, cnt);
    t->L = r;
    t->update();
    return {l, t};
  }
}

template<typename T>
tuple<Node<T>*, Node<T>*, Node<T>*> split(Node<T>* t, int l, int r) {
  auto [L, x] = split(t, l);
  auto [M, R] = split(x, r-l+1);
  return {L, M, R};
}

template<typename T>
Node<T>* merge(Node<T> *l, Node<T> *r) {
  if (!l) return r;
  if (!r) return l;

  if (l->P > r->P) {
    l->R = merge(l->R, r);
    l->update();
    return l;
  } else {
    r->L = merge(l, r->L);
    r->update();
    return r;
  }
}

template<typename T>
Node<T>* merge(Node<T> *l, Node<T> *m, Node<T> *r) {
  return merge(merge(l, m), r);
}

template<typename T>
ostream &operator<<(ostream &os, Node<T>* x) {
  if (!x) return os;
  os << x->L;
  os << x->X;
  os << x->R;
  return os;
}
//}}}

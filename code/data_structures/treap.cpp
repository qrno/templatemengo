// Treap {{{
struct Node {
  int X, P, S;
  Node *L, *R;
  Node (int x) : X(x), P(rng()), S(1), L(nullptr), R(nullptr) {}
};

int size(Node* t) { return t ? t->S : 0; }

pair<Node*, Node*> split(Node *t, int cnt) {
  if (!t) return {nullptr, nullptr};

  if (size(t->L) < cnt) {
    auto [l, r] = split(t->R, cnt-size(t->L)-1);
    t->R = l;
    t->S = 1 + size(t->L) + size(t->R);
    return {t, r};
  } else {
    auto [l, r] = split(t->L, cnt);
    t->L = r;
    t->S = 1 + size(t->L) + size(t->R);
    return {l, t};
  }
}

tuple<Node*, Node*, Node*> split(Node* t, int l, int r) {
  auto [L, x] = split(t, l);
  auto [M, R] = split(x, r-l+1);
  return {L, M, R};
}

Node* merge(Node *l, Node *r) {
  if (!l) return r;
  if (!r) return l;

  if (l->P > r->P) {
    l->R = merge(l->R, r);
    l->S = 1 + size(l->L) + size(l->R);
    return l;
  } else {
    r->L = merge(l, r->L);
    r->S = 1 + size(r->L) + size(r->R);
    return r;
  }
}

Node* merge(Node *l, Node *m, Node *r) {
  return merge(merge(l, m), r);
}

ostream &operator<<(ostream &os, Node* x) {
  if (!x) return os;
  os << x->L;
  os << x->X;
  os << x->R;
  return os;
}
//}}}

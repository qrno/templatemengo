# Treap

## Implementation

```cpp title="Treap"
--8<-- "data_structures/treap.cpp"
```

- [Benq's Presentation](https://docs.google.com/presentation/d/14xgtdDWnIBwmJRAuIdZ8FvLZcX9uRxnNoGOGAQRDIvc/)
- [Algorithms Live! - Episode 30 - Treaps](https://www.youtube.com/watch?v=erKlLEXLKyY)
- [AlgorithmsThread 9: Treaps!](https://www.youtube.com/watch?v=6x0UlIBLRsc)

## Notes

- Binary Search Tree

- Talk about implicit treap from the very start?

- I'll probably want to solve at least:
 - [Cut and Paste](https://cses.fi/problemset/task/2072)
 - [Substring Reversals](https://cses.fi/problemset/task/2073)
 - [Reversals and Sums](https://cses.fi/problemset/task/2074)

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

Node* meld(Node *l, Node *r) {
  if (!l) return r;
  if (!r) return l;

  if (l->P > r->P) {
    l->R = meld(l->R, r);
    l->S = 1 + size(l->L) + size(l->R);
    return l;
  } else {
    r->L = meld(l, r->L);
    r->S = 1 + size(r->L) + size(r->R);
    return r;
  }
}

Node* meld(Node *l, Node *m, Node *r) {
  return meld(meld(l, m), r);
}

ostream &operator<<(ostream &os, Node* x) {
  if (!x) return os;
  os << x->L;
  os << x->X;
  os << x->R;
  return os;
}
//}}}

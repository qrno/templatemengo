# Seg da P1

!!! warning
    Indexado em 0. Também nem testei se funciona.

!!! warning
    Não só copiem, tentem fazer sozinhos e usem só como referência.

```cpp
const int MAXN = 1e5 + 8;

int N;
int T[4*MAXN];
void update(int idx, int x, int id=1, int il=0, int ir=N-1) {
  if (il == ir) { T[id] = x; return; }
  int im = (il+ir)/2;
  if (idx <= im) update(idx, x, 2*id, il, im);
  else update(idx, x, 2*id+1, im+1, ir);
  T[id] = T[2*id] + T[2*id+1];
}
int query(int l, int r, int id=1, int il=0, int ir=N-1) {
  if (r < il || ir < l) return 0;
  if (l <= il && ir <= r) return T[id];
  int im = (il+ir)/2;
  return query(l, r, 2*id, il, im)
       + query(l, r, 2*id+1, im+1, ir);
}
```

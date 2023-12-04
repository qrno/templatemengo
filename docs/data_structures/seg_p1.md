# Seg da P1

!!! warning
    Indexado em 0. Também nem testei se funciona.

!!! warning
    Não só copiem, tentem fazer sozinhos e usem só como referência.

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 8;

int N;
int T[4*MAXN];
int update(int idx, int x, int id=1, int il=0, int ir=N-1) {
  if (idx < il || ir < idx) return 0;
  if (il == ir) return T[id] = x;
  int im = (il+ir)/2;
  return T[id] += update(idx, x, 2*id, il, im)
                + update(idx, x, 2*id+1, im+1, ir);
}
int query(int l, int r, int id=1, int il=0, int ir=N-1) {
  if (r < il || ir < l) return 0;
  if (l <= il && ir <= r) return T[id];
  int im = (il+ir)/2;
  return query(l, r, 2*id, il, im)
       + query(l, r, 2*id+1, im+1, ir);
}

int main() {
}
```

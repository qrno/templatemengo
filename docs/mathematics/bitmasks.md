# Bitmasks

## Iterating through all subsmasks

This technique can be found on this [article](https://cp-algorithms.com/algebra/all-submasks.html).

```cpp title="Iterating through all submasks of m"
// doesn't go through 0
for (int s=m; s; s=(s-1)&m) {}
// goes through 0
for (int s=m;  ; s=(s-1)&m) {
    if (s == 0) break;
}
```

## Number of supermasks

Given a list of masks, count for each possible mask how many masks it is a submask of. This looks a lot like SOS DP?

```cpp title="Number of supermasks"
const int MAXB = 20;
vector<int> amount(1 << MAXB);

for (int b = MAXB-1; b >= 0; b--) {
  for (int j = 0; j < 1 << MAXB; j++) {
    if (j & (1 << b)) {
      amount[j ^ (1 << b)] += amount[j];
    }
  }
}
```

### Problems

 - [(CF1523-B) Love-Hate](https://codeforces.com/contest/1523/problem/D)
 - [(CF449-D) Jzzhu and Numbers](https://codeforces.com/contest/449/problem/D)

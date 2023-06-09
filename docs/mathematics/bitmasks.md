# Bitmasks

## Number of supermasks

Given a list of masks, count for each possible mask how many masks it is a submask of.

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

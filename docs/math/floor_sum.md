# Floor Sum

Returns the sum

$$
\sum_{i=0}^{n-1} \Bigl\lfloor \frac{a\times i + b}{m} \Bigr\rfloor
$$

in $O(\log m)$ complexity.


## Code

My implementation was stolen straight from [AtCoder Library](https://github.com/atcoder/ac-library/blob/master/atcoder/math.hpp).

```cpp title="Floor Sum"
--8<-- "math/floor_sum.cpp"
```

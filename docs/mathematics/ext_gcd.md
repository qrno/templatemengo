# Linear Diophantine Equations

If you want to understand everything, read this [[cp-algorithms] - Linear Diophantine Equations](Algorithms for Competitive Programming
Linear Diophantine Equations).
I think this code is much better.
It's possible to do it iteratively, but that's probably unnecessary.

## Extended GCD

Given two integers $a$ and $b$,
returns their gcd and two coefficients $x$ and $y$ such that
$ax + by = g$.

## Linear Diophantine Equations

Given three integers $a$, $b$, $c$, returns whether it is possible to get
$x$ and $y$ such that $ax + by = c$, as well as $x$ and $y$ if possible.

```cpp title="Extended GCD"
--8<-- "mathematics/ext_gcd.cpp"
```


# Theory

!!! warning "Counter-clockwise"
    In any context, consider angles are measured in **counter-clockwise** manner.

## Dot Product

### Math

- $(a, b) \cdot (x, y) = ax + by$

- $a \cdot b = \lvert a\rvert \lvert b\rvert \cos(\theta)$

### Properties

1. Can be used for checking acuteness or perpendicularity. Zero means perpendicular. Positive means acute, negative means obtuse.
2. Squared length of a vector: $a\cdot a = {\lvert a \rvert}^2$
3. Length of projection of $a$ onto $b$: $\dfrac{a \cdot b}{\lvert b\rvert}$
4. Angle between vectors: $\arccos\left(\dfrac{a\cdot b}{\lvert a\rvert \lvert b \rvert}\right)$

### Extra

The set of points which have a certain dot product with a given vector is forms a line.

## Cross Product

### Math

- $(a, b) \times (x, y) = ay - bx$

- $a \times b = \lvert a \rvert\lvert b \rvert\sin(\theta)$

### Properties

1. Can be used to check for left, right or collinearity.
If $a \times b$ is zero, the vectors are collienar.
Positive means $b$ is to the left of $a$.
Negative means $b$ is to the right of $a$.

2. Represents the area of the parallelogram with sides $a$ and $b$.
Is pretty much the determinant.

3. $a\times b = -b\times a$

4. $(a + b)\times c = a\times c + b\times c$

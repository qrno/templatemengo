# Flow

## Dinitz

This is based on the implementation on [cp-algorithms](https://cp-algorithms.com/graph/dinic.html#implementation). But in my opinion this one is much more organized.

```cpp title="Dinitz"
--8<-- "dinitz.cpp"
```

## Dinitz Min-Cost

The same as above, but allows you to set a cost per flow unit for each edge.
This is lightly based on the article on [cp-algorithms](https://cp-algorithms.com/graph/min_cost_flow.html).

It uses [SPFA](https://cp-algorithms.com/graph/bellman_ford.html#implementation_1) instead of Bellman-Ford since it is usually much faster.

```cpp title="Dinitz Min-Cost"
--8<-- "dinitz_mincost.cpp"
```

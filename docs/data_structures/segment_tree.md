# Segment Tree

Page needs to be updated!

```cpp title="Segment Tree"
--8<-- "data_structures/segment_tree/segment_tree.cpp"
```

<!-- ## Code -->
<!---->
<!-- Node must have a sum operator, as well as a default constructor which must be the monoid's neutral element. -->
<!---->
<!-- ```cpp title="Segment Tree" -->
<!-- --8<-- "data_structures/segment_tree.cpp" -->
<!-- ``` -->
<!---->
<!-- Tested on [Library Checker - Point Add Range Sum](https://judge.yosupo.jp/problem/point_add_range_sum) -->
<!-- [[Submission]](https://judge.yosupo.jp/submission/162978) -->
<!---->
<!-- ## Code (Simple) -->
<!---->
<!-- This segment tree has a simpler interface in some cases, but I heard that `std::function` has a little bit of overhead. -->
<!-- It runs about 15% slower on Yosupo, probably still faster than a recursive segment tree. -->
<!---->
<!-- If you're doing simple operations on integers it will probably result in shorter code. -->
<!-- On the implementation above, you would need to do this for a _max_ segment tree: -->
<!---->
<!-- ```cpp -->
<!-- struct MaxNode { -->
<!--     int x; -->
<!--     MaxNode() : x(-INF) {} -->
<!--     MaxNode(int x) : x(x) {} -->
<!--     friend MaxNode operator+(MaxNode a, MaxNode b) { -->
<!--         return MaxNode(max(a.x, b.x)); -->
<!--     } -->
<!-- }; -->
<!-- SegmentTree<Node> S(N); -->
<!-- ``` -->
<!---->
<!-- On this one you can do this: -->
<!---->
<!-- ```cpp -->
<!-- SegmentTreeSimple<int> S(N, -INF, [](int x, int y){return max(x, y);}); -->
<!-- ``` -->
<!---->
<!-- ```cpp title="Segment Tree Simple" -->
<!-- --8<-- "data_structures/segment_tree_simple.cpp" -->
<!-- ``` -->
<!---->
<!-- Tested on [Library Checker - Point Add Range Sum](https://judge.yosupo.jp/problem/point_add_range_sum) -->
<!-- [[Submission]](https://judge.yosupo.jp/submission/162979) -->

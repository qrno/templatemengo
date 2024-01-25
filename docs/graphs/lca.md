# Lowest Common Ancestor

Given a tree, offers the following functions (source is smallest vertex in the component):

- `is_ancestor(v, u)` - whether v is an ancestor of u in the tree
- `lca(v, u)` - lowest common ancestor of v and u
- `dist(v, u)` - shortest distance between v and u

If LCA or dist are called with vertices from different components, you'll probably get a runtime error.

## Code

```cpp title="Lowest Common Ancestor"
--8<-- "graphs/lca.cpp"
```
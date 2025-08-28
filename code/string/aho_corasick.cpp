#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

}

// Aho-Corasick {{{
struct AhoCorasick {
  const int MALPHA = 26;

  vector<vector<int>> trie{vector<int>(MALPHA, -1)};
  vector<int> depth{0};
  vector<bool> is_word{0};
  vector<int> suffix_link;
  vector<int> output_link;

  explicit AhoCorasick(vector<string> const& v) {
    for (auto const& s : v) {
      insert(s);
    }
    create_links();
  }

private:
  int add_node(int parent) {
    trie.push_back(vector<int>(MALPHA, -1));
    is_word.push_back(false);
    depth.push_back(depth[parent] + 1);
    return size(trie) - 1;
  }

  void insert(string const& s) {
    int cur = 0;
    for (auto c : s) {
      if (trie[cur][c-'a'] == -1)
        trie[cur][c-'a'] = add_node(cur);
      cur = trie[cur][c-'a'];
    }
    is_word[cur] = true;
  }

  void create_links() {
    suffix_link.assign(size(trie), 0);
    output_link.assign(size(trie), -1);

    queue<int> Q;
    Q.push(0);

    while (!empty(Q)) {
      int v = Q.front();
      Q.pop();

      for (int c = 0; c < MALPHA; c++) {
        int u = trie[v][c];
        if (u == -1) continue;

        if (v == 0) {
          suffix_link[u] = 0;
        } else {
          int cur = suffix_link[v];
          while (trie[cur][c] == -1 && cur != 0) {
            cur = suffix_link[cur];
          }
          if (trie[cur][c] != -1) {
            suffix_link[u] = trie[cur][c];
          }
        }

        Q.push(u);
      }

      int cur = suffix_link[v];
      if (is_word[cur]) {
        output_link[v] = cur;
      } else {
        output_link[v] = output_link[cur];
      }
    }
  }
};
// }}}

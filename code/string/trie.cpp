// Trie {{{
struct Trie {
  const int MALPHA = 26;

  vector<vector<int>> trie{vector<int>(MALPHA, -1)};
  vector<int> word_cnt{0};

  int add_node() {
    trie.push_back(vector<int>(MALPHA, -1));
    word_cnt.push_back(0);
    return size(trie)-1;
  }

  void insert(string const& s) {
    int cur = 0;
    for (auto c : s) {
      if (trie[cur][c-'a'] == -1)
        trie[cur][c-'a'] = add_node();
      cur = trie[cur][c-'a'];
    }
    word_cnt[cur]++;
  }

  int count(string const& s) {
    int cur = 0;
    for (auto c : s) {
      if (trie[cur][c-'a'] == -1)
        return false;
      cur = trie[cur][c-'a'];
    }
    return word_cnt[cur];
  }
};
//}}}
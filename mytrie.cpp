#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
using std::vector;
using std::string;
struct TrieNode;
using TrieNodeptr = std::shared_ptr<TrieNode>;
struct TrieNode {
  std::unordered_map<char, TrieNodeptr> next{};
  int count{0};
  bool isEnd{false};
};

void insert(std::string key, TrieNodeptr root) {
  for (auto c : key) {
    if (!root->next.contains(c)) {
      TrieNodeptr newNode(new TrieNode);
      root->next[c] = newNode;
    }
    root = root->next[c];
    root->count++;
  }
  root->isEnd = true;
}

bool search(std::string key, TrieNodeptr root) {
  auto prefix_count{0};
  for (auto c : key) {
    if (!root->next.contains(c)) {
      return false;
    }
    root = root->next[c];
  }
  prefix_count = root->count;
  std::cout << "Prefix count " << prefix_count << std::endl;
  return root->isEnd;
}


void dfs(TrieNodeptr root, string prefix, vector<string>& results) {
    if (root->isEnd) {
        results.push_back(prefix);
    }

    for (auto& [c, next] : root->next) {
        dfs(next, prefix + c, results);
    }
    return;
}

auto
search_prefix(string prefix, TrieNodeptr root) {
    vector<string> results;
    for (auto c : prefix) {
        if (!root->next.contains(c)) {
            return results;
        }
        root = root->next[c];
    }
    dfs(root, prefix, results);
    return results;
}

int main() {
  {
    TrieNodeptr root(new TrieNode);
    std::string key = "Anubhav";
    insert(key, root);
    assert(search(key, root));
    key = "Monkey";
    insert(key, root);
    assert(search(key, root));
    assert(!search("Monk", root));
    key = "Anubis";
    insert(key, root);
    key = "Anulate";
    insert(key, root);
    key = "And";
    search(key, root);
    auto res = search_prefix("An", root);
    std::for_each(res.begin(), res.end(), [](auto s){ std::cout << s << " ";});
  }
  return 0;
}
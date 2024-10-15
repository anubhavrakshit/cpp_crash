#include <cassert>
#include <iostream>
#include <memory>
#include <unordered_map>

using namespace std;

struct TrieNode {
  unordered_map<char, shared_ptr<TrieNode>> child;
  bool is_end{false};
  ~TrieNode() {
    cout << "Destructed TrieNode" << endl;
  }
};

class Trie {
public:
  Trie() { root_ = make_shared<TrieNode>(); }

  void insert(string word) {
    auto root = root_;
    for (auto c : word) {
      if (root->child.contains(c)) {
        root = root->child[c];
        continue;
      } else {
        auto node = make_shared<TrieNode>();
        root->child[c] = node;
        root = node;
      }
    }
    root->is_end = true;
  }

  bool search(string word) {
    auto root = root_;
    for (auto c : word) {
      if (!root->child.contains(c)) {
        return false;
      }
      root = root->child[c];
    }
    return root->is_end;
  }

  bool startsWith(string prefix) {
    auto root = root_;
    for (auto c : prefix) {
      if (!root->child.contains(c)) {
        return false;
      }
      root = root->child[c];
    }
    return true;
  }
  ~Trie() { cout << "shared ptr use count = " << root_.use_count() << endl; }

private:
  shared_ptr<TrieNode> root_;
};

void test_insert() {
  auto trie = make_unique<Trie>();
  
  // Insert words
  trie->insert("apple");
  trie->insert("banana");
  trie->insert("cherry");

  // Check if the words were inserted correctly
  assert(trie->search("apple"));
  assert(trie->search("banana"));
  assert(trie->search("cherry"));

  // Check for a word that was not inserted
  assert(!trie->search("grape"));

  cout << "All insert tests passed." << endl;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  test_insert();
  return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Trie {
private:
    struct node {
          char key;
          vector<node*> next;
        };
    
        vector<node*> root;
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node* new_node{NULL};
        node* prev_node{NULL};
      
        // add a term char
        word += "$";
        for (auto c: word) {
            // Check if root is empty
            if (root.empty()) {
                new_node = new node;
                new_node->key = c;
                root.push_back(new_node);
                prev_node = new_node;
                continue;
            }  
           
            // find the root node for this
            if (!prev_node) {
                // Check if this key is already present
                bool is_found = false;
                for (auto n: root) {
                    if (n->key == c) {
                        prev_node = n;
                        is_found = true;
                        break;
                    }
                }    

                if (!is_found) {
                    new_node = new node;
                    new_node->key = c;
                    root.push_back(new_node);
                    prev_node = new_node;
                }
            } else {
                // find if we already have the key
                bool is_found = false;
                for (auto n: prev_node->next) {
                    if (n->key == c) {
                        prev_node = n;
                        is_found = true;
                        break;
                    }
                }    
                if (!is_found) {
                    new_node = new node;
                    new_node->key = c;
                    prev_node->next.push_back(new_node);
                    prev_node = new_node;
                }
            }

        }
            
            
        }
    
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
            if (root.empty()) {
                return false;
            }
            cout << "Search = " << word << endl;
            word += "$";
            bool found{false};
            node *prev{NULL};
            for (auto n:root) {
                if (n->key == word[0]) {
                    
                    found = true;
                    prev = n;
                    break;
                }
            }
        
            if (!found) {
                return false;
            }
        
            auto len = word.length();
            for (int i = 1; i < len; i++) {
                bool found{false};
                for (auto n:prev->next) {
                    if (n->key == word[i]) {
                        found = true;
                        prev = n;
                        break;
                    }
                }
                if (!found) {
                    return false;
                }
            }
        
            return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (root.empty()) {
                return false;
        }

        cout << "Prefix = " << prefix << endl;
        bool found{false};
            node *prev{NULL};
            for (auto n:root) {
                if (n->key == prefix[0]) {
                    
                    found = true;
                    prev = n;
                    break;
                }
            }
        
            if (!found) {
                return false;
            }
        
            auto len = prefix.length();
            for (int i = 1; i < len; i++) {
                bool found{false};
                for (auto n:prev->next) {
                    if (n->key == prefix[i]) {
                        found = true;
                        prev = n;
                        break;
                    }
                }
                if (!found) {
                    return false;
                }
            }
        
            return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    Trie t;
    t.insert("apple");
    cout << t.search("apple") << endl;
    cout << t.search("app") << endl;
    cout << t.startsWith("app") << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

bool wordPattern(string pattern, string s) {
  stringstream ss(s);
  vector<string> words;
  string word;
  while (ss >> word) {
    words.push_back(word);
  }

  if (pattern.length() != words.size()) {
    return false;
  }
  size_t idx{0};
  unordered_map<char, string> char_pattern;
  unordered_map<string, char> pattern_char;

  for (auto c : pattern) {
    if (char_pattern.count(c) == 0 and pattern_char.count(words[idx]) == 0) {
      char_pattern[c] = words[idx];
      pattern_char[words[idx]] = c;
    } else {
      if (char_pattern[c] != words[idx] or pattern_char[words[idx]] != c) {
        return false;
      }
    }
    idx++;
  }
  return true;
}

int main() {
    string pattern = "abab";
    string s = "dog cat dog cat";
    assert(wordPattern(pattern, s));
    pattern = "abab";
    s = "dog dog dog dog";
    assert(wordPattern(pattern, s) == false);
    return 0;
}
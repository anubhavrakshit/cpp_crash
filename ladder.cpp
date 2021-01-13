#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    unordered_map<string, set<string>> table;
    int min_trans = INT_MAX;
    bool singleMismatch(string& word1, string& word2, bool built) {
       #if 0 
        if (table.find(word1) != table.end()) {
            auto singlematches = table[word1];
            if (singlematches.find(word2) != singlematches.end()) {
                cout << "Hit true" << endl;
                return true;
            } else {
                if (built) {
                    return false;
                }
            }
        }
        #endif
        if (word1.length() != word2.length()) {
            return false;
        }
        
        int mismatch{0};
        int len = word1.length();
        
        for (int i = 0; i < len; i++) {
            if (word1[i] != word2[i]) {
                mismatch++;
            }
            
            if (mismatch > 1) {
                return false;
            }
        }
        
        if (!mismatch) {
            return false;
        }
        // add to cache
        //table[word1].insert(word2);
        //table[word2].insert(word1);
        cout << word1 << " " << word2 << " " << endl;
        return true;
    }
   #if 0 
    int hlpr(string beginWord, string endWord, vector<string>& wordList, vector<bool> chosen, int count) {
        if (beginWord == endWord) {
            return count + 1;
        }
        
        // No choices left
        if (count >= wordList.size() - 1) {
            return 0;
        }
        
        // Pruning
        if (count > min_trans) {
            return 0;
        }
        
        for (int i = 0; i < wordList.size(); i++) {
            if (!chosen[i] && singleMismatch(wordList[i], beginWord, true)) {
                chosen[i] = true;
            } else {
                continue;
            }
            
            int res = hlpr(wordList[i], endWord, wordList, chosen, count + 1);
            if (res != 0) {
                min_trans = min(res, min_trans);
            }
            chosen[i] = false;
        } 
        
        if (min_trans != INT_MAX) {
            return min_trans;
        }
        
        return 0;
    }
    #endif

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> chosen(wordList.size(), false);
#if 0 
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                singleMismatch(wordList[i], wordList[j], false);
            }
        }
        
        for (int i = 0; i < wordList.size(); i++) {
            singleMismatch(beginWord, wordList[i], false);
        }
        cout << "Cache built" << endl;
        return hlpr(beginWord, endWord, wordList, chosen, 0);
#endif
        // find nbrs
       queue<string> q;
       q.push(beginWord);
       int ladder{1};

       while (!q.empty()) {
            int num_nbrs = q.size();
            for (int i = 0; i < num_nbrs; i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return ladder;
                }
                // find valid nbrs
                for (int j = 0; j < wordList.size(); j++) {
                    if (!chosen[j] && singleMismatch(wordList[j], word, false)) {
                            chosen[j] = true;
                            q.push(wordList[j]);
                    }

                }
            }
            ladder++;            
       }

        return 0;  
    }
};


int main() 
{
    Solution s;
    vector<string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    cout << s.ladderLength("qa", "sq", wordList) << endl;
}
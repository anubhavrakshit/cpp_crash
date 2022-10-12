#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &adjl, map<int, int> &nl, vector<int> &visit, pair<int, int> u) {
    for (auto v : adjl[u.first]) {
        if (!visit[v]) {
            visit[v] = 1;
            dfs(adjl, nl, visit, {v, u.second + 1});
        }
    }
    nl[u.second]++;
}

int main() {
  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, Q;
    cin >> N >> Q; // Num
    vector<vector<int>> adjl(N + 1, vector<int>(0));
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }
    
    for (int i = 0; i < Q; i++) {
        int c;
        cin >> c;
    }

    vector<int> visit(N + 1, 0);
    map<int, int> nl;
    int ans{0};
    pair<int, int>  root {1, 1};
    visit[1] = 1;
    dfs(adjl, nl, visit, root);
    int level{1};
    while (nl[level] != 0) {
     if (ans + nl[level] > Q) {
        break;
     }
     ans += nl[level++];
    }

    cout << "Case #" << testCase << ": ";
    cout << ans;
    cout << endl;
  }
  return 0;
}
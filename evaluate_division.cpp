#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
using edge = pair<string, double>; // Vertex, value
using graph = unordered_map<string, vector<edge>>;

double dfs(string src, string dst, double ans, graph &division,
           set<string> &visit) {
  double ret{-1.0};
  cout << src << " -> " << dst << " weight " << ans << endl;
  if (src == dst) {
    cout << "return weight " << ans << endl;
    return ans;
  }

  visit.insert(src);
  for (auto nbr : division[src]) {
    if (!visit.count(nbr.first)) {
      cout << "Chose " << nbr.first << " weight " << nbr.second << endl;
      ret = dfs(nbr.first, dst, ans * nbr.second, division, visit);
      if (ret != -1.0) {
        break;
      }
    }
  }
  visit.erase(src);
  return ret;
}

vector<double> calcEquation(vector<vector<string>> &equations,
                            vector<double> &values,
                            vector<vector<string>> &queries) {
  vector<double> resp;
  int index{0};
  graph division;
  set<string> seen;
  for (auto &eq : equations) {
    auto num = eq[0];
    auto den = eq[1];
    seen.insert(num);
    seen.insert(den);
    auto val = values[index++];
    edge forw = {den, val};
    edge back = {num, 1.0 / val};
    division[num].push_back(forw);
    division[den].push_back(back);
  }

  for (auto &q : queries) {
    auto num = q[0];
    auto den = q[1];
    if (!seen.count(num) or !seen.count(den)) {
      resp.push_back(-1.0);
      continue;
    }
    set<string> visit;
    double ans{1.0};
    auto ret = dfs(num, den, ans, division, visit);
    resp.push_back(ret);
  }
  return resp;
}
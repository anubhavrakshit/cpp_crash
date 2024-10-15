#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

using eq = pair<string, string>;

double hlpr(map<eq, double> &map_equations, string num, string denom) {
  // We will get something like
  // x/y and we need something like x/a and a/y to solve this
  // So we need to find all the equations with x numerator and y denominators
  // Then check if in any of the combinations denom == numer
  vector<eq> eq_num, eq_denom;
  for (auto [eq, val] : map_equations) {
    if (eq.first == num) {
      eq_num.push_back(eq);
    } else if (eq.second == denom) {
      eq_denom.push_back(eq);
    }
  }
  auto ans{-1.0};
  for (auto &x_num : eq_num) {
    for (auto &y_denom : eq_denom) {
      if (x_num.second == y_denom.first) {
        ans = map_equations[x_num] * map_equations[y_denom];
        break;
      }
    }
  }
  map_equations[{num, denom}] = ans;
  return ans;
}

vector<double> calcEquation(vector<vector<string>> &equations,
                            vector<double> &values,
                            vector<vector<string>> &queries) {
  using eq = pair<string, string>;
  map<eq, double> map_equations;
  set<string> known;
  int index{0};
  for (auto &row : equations) {
    auto x = row[0];
    auto y = row[1];
    map_equations[{x, y}] = values[index];
    map_equations[{y, x}] = 1.0 / values[index];
    known.insert(x);
    known.insert(y);
    index++;
  }
  vector<double> ans;
  for (auto &q : queries) {
    auto x = q[0];
    auto y = q[1];
    if (known.count(x) == 0 or known.count(y) == 0) {
      ans.push_back(-1.0);
      continue;
    }
    if (map_equations.count({x, y})) {
      ans.push_back(map_equations[{x, y}]);
    } else {
      auto ret = hlpr(map_equations, x, y);
      ans.push_back(ret);
    }
  }
  return ans;
}

int main() {
    return 0;
}
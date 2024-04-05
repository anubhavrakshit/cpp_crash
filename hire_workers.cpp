#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
long long totalCost(vector<int> &costs, int k, int candidates) {
  // Hire k workers
  // Chose worker with lowest cost
  size_t l{0}, r{costs.size() - 1};
  size_t total_cost{0};

  class comp {
  public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
      if (a.first == b.first) {
        return a.second > b.second;
      }
      return a.first > b.first;
    };
  };

  priority_queue<pair<int, int>, vector<pair<int, int>>, comp> start_q, end_q;
  while (k--) {
    // Fill first candidates
    size_t start_count{0};
    for (auto first = l; first <= r and start_q.size() < candidates; first++) {
      start_q.push({costs[first], first});
      start_count++;
    }
    l += start_count;

    // Fill last candidates
    size_t end_count{0};
    for (auto last = r; last >= l and end_q.size() < candidates; last--) {
      end_q.push({costs[last], last});
      end_count++;
    }
    r -= end_count;
    assert(!start_q.empty() or !end_q.empty());

    if (end_q.empty()) {
      auto start_min = start_q.top();
      total_cost += start_min.first;
      cout << start_min.first;
      start_q.pop();
      continue;
    }

    if (start_q.empty()) {
      auto end_min = end_q.top();
      cout << end_min.first;
      total_cost += end_min.first;
      end_q.pop();
      continue;
    }

    auto start_min = start_q.top();
    auto end_min = end_q.top();

    if (start_min.first < end_min.first) {
      total_cost += start_min.first;
      cout << start_min.first;
      start_q.pop();
    } else if (start_min.first > end_min.first) {
      total_cost += end_min.first;
      cout << end_min.first;
      end_q.pop();
    } else {
      total_cost += start_min.first;
      cout << start_min.first;
      start_q.pop();
    }
    cout << " , ";
  }
  return total_cost;
}
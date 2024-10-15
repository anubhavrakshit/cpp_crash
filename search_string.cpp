#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <ranges>

using namespace std;

int myhlpr(string array[], int size, string target, int l, int r) {
  if (l > r or r >= size or l < 0) {
    return -1;
  }
  int mid = (l + r) / 2;
  if (array[mid].empty()) {
    auto ret{-1};
    ret = myhlpr(array, size, target, l, mid - 1);
    if (ret == -1) {
      return myhlpr(array, size, target, mid + 1, r);
    }
  } else if (array[mid] == target) {
    return mid;
  } else if (array[mid] < target) {
    return myhlpr(array, size, target, mid + 1, r);
  }
  return myhlpr(array, size, target, l, mid - 1);
}
int searchForString(string array[], int size, string target) {
  // Write your code here
  return myhlpr(array, size, target, 0, size - 1);
}

vector<int> solve() {
  vector<int> ans;
  vector <int> A;
  vector <vector<int>> B(100, vector<int>(4));
  for (auto &q : B) {
    auto l1 = q[0];
    auto r1 = q[1];
    auto l2 = q[2];
    auto r2 = q[3];

    array<int, 100000> table{};
    for_each(A.begin() + l1, A.begin() + r1 + 1,
             [&](const auto n) { table[n]++; });
    for_each(A.begin() + l2, A.begin() + r2 + 1,
             [&](const auto n) { table[n]--; });

    auto ret = all_of(A.begin() + l1, A.begin() + r1 + 1,
                      [&](const auto n) { return table[n] == 0; });
    if (ret) {
      ans.push_back(1);
    } else {
      ans.push_back(0);
    }
  }

  return ans;
}
void bla() {
    string array[] = {"anu", "", "file", "", "game"};
  cout << searchForString(array, 5, "file") << std::endl;
  
  std::list<int> my_list = {1, 2, 3, 4, 5};
  auto tail_itr = my_list.end();
  auto itr = my_list.insert(tail_itr, 90);

  std::cout << std::endl;
  unordered_map<int, std::list<int>::iterator> map;
  
  for (auto n = my_list.begin(); n != my_list.end(); n++) {
    map[*n] = n;
  }
  my_list.erase(map[2]);
  my_list.erase(map[2]);
  for (auto n : my_list) {
    std::cout << n <<  " ";
  }
}
void test_range() {
    std::vector<int> nums = {1, 78, 23, 90, 25, 24, 3, 8, 65, 100};
    auto odds = std::views::filter(nums, [](const auto n){return n % 2 == 1;});
    for (auto n : odds) {
        cout << n << " ";
    }
}
int main() {
  test_range(); 
  return 0;
}
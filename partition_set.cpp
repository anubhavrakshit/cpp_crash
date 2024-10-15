using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
 public:
  bool canPartition(const vector<int> &num) {
    //TODO: Write - Your - Code
    int sum{0};
    for (auto n : num) {
        sum += n;
    }
    if (sum % 2) {
        return false;
    } 
    return hlpr(num, 0, sum / 2);
  }
  private:
   bool hlpr(const vector<int> &num, int index, int sum) {
      if (index >= num.size()) {
          return (sum == 0);
      }
      
      
      auto ret1{false};
      if (sum - num[index] >= 0) {
        ret1 = hlpr(num, index + 1, sum - num[index]);
      }
      if (ret1 == true) {
        return ret1;
      }

      return hlpr(num, index + 1, sum);
    }
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 4};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 1, 3, 4, 7};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{2, 3, 4, 6};
  cout << ps.canPartition(num) << endl;
}

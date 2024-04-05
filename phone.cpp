#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

int repeat_count(string num) {
    if (num.length() <= 1) {
        return num.length();
    }

    if (num[0] == num[1]) {
        string next = num.substr(1);
        return 1 + repeat_count(next);
    }

    return 1;
}

string parse_num(string num) {

    unordered_map<int, string> group, num_name;

    group[2] = "double";
    group[3] = "triple";
    group[4] = "quadruple";
    group[5] = "quintuple";
    group[6] = "sextuple";
    group[7] = "septuple";
    group[8] = "octuple";
    group[9] = "nonuple";
    group[10] = "decuple";

    num_name[1] = "one";
    num_name[2] = "two";
    num_name[3] = "three";
    num_name[4] = "four";
    num_name[5] = "five";
    num_name[6] = "six";
    num_name[7] = "seven";
    num_name[8] = "eight";
    num_name[9] = "nine";
    num_name[0] = "zero";

    string phone_num;
    while (num.length()) {
        int rc = repeat_count(num);
        if (rc > 10) {
            // read seperately
            for (int i = 0; i < rc; i++) {
                phone_num += num_name[num[i] - '0'] + " ";
            }
        } else if (rc >= 2) {
            phone_num += group[rc] + " ";
            phone_num += num_name[num[0] - '0'] + " ";
        } else {
            phone_num += num_name[num[0] - '0'] + " ";
        }
        num = num.substr(rc);
    }

    return phone_num;
}

string read_phone(string phone_num, vector<int> format) {
    vector<string> sub_nums;
    int start = 0;
    for (int i = 0; i < format.size(); i++) {
        int len = format[i];
        sub_nums.push_back(phone_num.substr(start, len));
        start += len;
    }
    string ans;
    for (auto subnum : sub_nums) {
        ans += parse_num(subnum);
    }

    return ans;
}
int main() {
  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    string phone_num, format;
    cin >> phone_num >> format;

    vector<int> width;
    stringstream ss(format);
    for (int i; ss >> i; ) {
        width.push_back(i);
        if (ss.peek() == '-') {
            ss.ignore();
        }
    }

    cout << "Case #" << testCase << ": ";
    string ans = read_phone(phone_num, width);
    cout << ans;
    cout << endl;
  }
  return 0;
}

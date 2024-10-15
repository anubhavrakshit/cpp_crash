#include <iostream>
#include <string>
#include <map>

using namespace std;

string get_expression(string A, int &pos) {
  string parse;
  cout << "Call:" << pos << endl;
  while (pos < A.length()) {
    cout << pos << endl;
    if (A[pos] == ')') {
      cout << "ret: " << parse << endl;
      break;
    } else if (A[pos] == '(') {
      pos++;
      string tmp = get_expression(A, pos);
      if (!parse.empty()) {
        bool is_neg{false};
        if (parse.back() == '-') {
          is_neg = true;
        }
        cout << "before pop back " << parse << " pos " << pos << endl;
        if (tmp.front() == '-' or tmp.front() == '+') {
          parse.pop_back();
        }
        if (is_neg) {
          for (auto &c : tmp) {
            if (c == '+') {
              c = '-';
            } else if (c == '-') {
              c = '+';
            }
          }
        }
      }
      parse += tmp;
      cout << " ext: " << parse << endl;
    } else {
      parse += A[pos];
      cout << parse << endl;
    }
    pos++;
  }

  return parse;
}

int main() {
  string test = "-(a-(-z-(b-(c+t)-x)+l)-q)";
  int pos{0};
  string p_A, p_B;
  p_A = get_expression(test, pos);
  map<string, int> m_A;
  string tmp;
  for (auto c : p_A) {
    if (c == '+' or c == '-') {
      tmp += c;
    } else {
      tmp += c;
      m_A[tmp]++;
      tmp.clear();
    }
    
  }

  for (auto [k, v] : m_A) {
        cout << k << " : " << v << endl;
  }
#if 0
  pos = 0;
  test = "-a+l-b-(z-(c+t)-x-q)";
  cout << get_expression(test, pos) << endl;
#endif
  return 0;
}
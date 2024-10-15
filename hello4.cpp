#include <iostream>
using namespace std;

int main() {
  int fib_prev{0}, fib{1};
  cout << fib_prev << " " << fib << " ";
  for (int i = 2; i <= 10; i++) {
    auto fib_cur = fib + fib_prev;
    cout << fib_cur << " ";
    fib_prev = fib;
    fib = fib_cur;
  }
  return 0;
} 
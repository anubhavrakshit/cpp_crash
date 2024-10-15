#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

const int MAX{100};
mutex mut;

void print_even(int* initial_count) {
  while (1) {
    unique_lock<mutex> lck(mut);
    if (*initial_count > MAX) {
      break;
    }
    if (*initial_count % 2 == 0) {
      cout << *initial_count << endl;
      (*initial_count)++;
    }
  }
}

void print_odd(int* initial_count) {
  while (1) {
    unique_lock<mutex> lck(mut);
    if (*initial_count > MAX) {
      break;
    }

    if (*initial_count % 2) {
      cout << *initial_count << endl;
      (*initial_count)++;
    }
  }
}

int main() {
  int initial_count = 1;
  thread th1(print_even, &initial_count), th2(print_odd, &initial_count);
  th1.join();
  th2.join();
  return 0;
}
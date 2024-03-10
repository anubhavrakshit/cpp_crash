#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class MyQueue {
public:
  MyQueue() {}

  void push(int x) {
    if (tmp.empty()) {
      main.push(x);
    } else {
      while (!tmp.empty()) {
        main.push(tmp.top());
        tmp.pop();
      }
      main.push(x);
    }
  }

  int pop() {
    while (!main.empty()) {
      tmp.push(main.top());
      main.pop();
    }
    auto ret = tmp.top();
    tmp.pop();
    return ret;
  }

  int peek() {
    while (!main.empty()) {
      tmp.push(main.top());
      main.pop();
    }
    auto ret = tmp.top();
    return ret;
  }

  bool empty() { return main.empty() and tmp.empty(); }

private:
  stack<int> main;
  stack<int> tmp;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    MyQueue q1;
    q1.push(10);
    q1.push(20);
    assert(q1.peek() == 10);
    assert(q1.pop() == 10);
    assert(q1.pop() == 20);
    assert(q1.empty());
    return 0;
}
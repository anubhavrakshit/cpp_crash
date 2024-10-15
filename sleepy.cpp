#include <chrono>
#include <iostream>
#include <ranges>
#include <thread>
#include <string>
class Sleepy {
public:
  Sleepy(int &i) : i_{i} {};
  void operator()(int k) {
    for (auto j = 0; j < k; j++) {
      std::cout << j << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      i_ += k;
    }
    std::cout << std::this_thread::get_id() << std::endl;
  }

private:
  int &i_;
};

void recurse(std::byte* addr) {
  std::byte data[1024];
  std::cout <<  addr - data << std::endl;
  recurse(addr);
}
int main() {
  int myVar{100};
  auto th = std::thread(Sleepy(myVar), 5);
  th.join();
  std::cout << myVar << std::endl;
  auto vec = std::vector{1, 2, 3, 4, 5, 4, 3, 2, 1};
  auto v = vec | std::views::drop_while([](auto i) { return i < 5; }) |
           std::views::take(4);
  for (auto i : v) {
    std::cout << i << " ";
  } // Prints 5 4 3
  std::cout << "\n";
  auto s = std::string{"aqm,nqe,jks,opl"};
  auto sep = std::ranges::views::split(s, ',');
  std::byte b;
  recurse(&b);
  return 0;
}
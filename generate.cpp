#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> test_vec(100);
    auto func = []() {return rand() % 100;};
    std::ranges::generate(test_vec, func);
    std::ranges::for_each(test_vec, [](auto& n){std::cout << n << ' ';});
    std::cout << "\n";
    std::ranges::sort(test_vec);
    std::ranges::for_each(test_vec, [](auto& n){std::cout << n << ' ';});
    std::cout << "\n";
    return 0;
}
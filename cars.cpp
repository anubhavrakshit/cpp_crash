// This example demonstrates how C++ can minimize
// heap allocations by:
// 1) Creating objects on the stack
// 2) Allocate multiple objects in one heap allocation
//
#include <cassert>
#include <gtest/gtest.h>
#include <vector>

class Car {
public:
  Car(int doors) : doors_(doors) {}

private:
  int doors_{};
};
auto some_func() {
  auto num_doors = 2;
  auto car1 = Car{num_doors};
  auto car2 = Car{num_doors};
}

auto car_list() {
  auto n = 4;
  auto cars = std::vector<Car>{};
  cars.reserve(n);
  for (auto i = 0; i < n; ++i) {
    cars.push_back(Car{2});
  }
}

TEST(HeapAllocations, Cars) {
  some_func();
  car_list();
}

class Button {
    Button() = default;
    // Copy constructor
    Button(const Button&) = default;
    auto operator=(const Button&) -> Button& = default;
    // Move constructor
    Button(Button&&) noexcept = default;
    auto operator=(Button&&) noexcept -> Button& = default;
    // Destructor
    ~Button() = default;
};

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
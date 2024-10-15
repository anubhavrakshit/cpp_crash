#include <iostream>
#include <string>
#include <cassert>
#include <memory>

template <typename T, size_t S>
class FixedArray {
    public:
    T data[S];
    FixedArray() {
        for (size_t i = 0; i < S; i++) {
            data[i] = T{};
        }
    }
    FixedArray(std::initializer_list<T> il) {
        size_t i = 0;
        for (auto it = il.begin(); it != il.end(); it++) {
            data[i++] = *it;
        }
    }
    T& operator[](size_t index) {
        if (index >= S) {
          throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    const T& operator[](size_t index) const {
        return data[index];
    }
    using iterator = T*;
    iterator begin() {
        return &data[0];
    }
    iterator end() {
        return &data[S];
    }
    
    ~FixedArray() {
        std::cerr << "FixedArray destructor" << std::endl;
    }
};
template <typename T, size_t S>
std::ostream &operator<<(std::ostream &os, const FixedArray<T, S> &fa) {
  for (size_t i = 0; i < S; i++) {
    os << fa.data[i] << " ";
  }
  return os;
}

int main() {
  FixedArray<int, 5> fa = {1, 2, 3, 4, 5};
  std::cout << fa << std::endl;
  std::cout << std::endl;
  FixedArray<int, 5> fa2{1, 2, 3, 4, 5};
  for (auto& i : fa2) {
    std::cout << i << " ";
  }

  FixedArray<std::string, 6> fa3{"Anubhav", "Rakshit", "Class", "4", "5", "6"};
  for (const auto &i : fa3) {
    std::cout << i << " ";
  }
  FixedArray<std::pair<int, int>, 6> fa4{{1, 2}, {3, 4}, {5, 6}};
    return 0;
}
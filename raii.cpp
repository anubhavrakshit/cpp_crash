#include <iostream>
#include <fstream>
#include <string>
#include <atomic>

template <typename T, typename Comparator>
int largest(const T* array, size_t size, Comparator comp) {
    int index{};
    for (size_t i{}; i < size; i++) {
        if (comp(array[i], array[index])) {
            index = i;
        }
    }
    return index;
}
template <typename ConcreteClass>
struct GenericPrint : ConcreteClass {
    void print(std::string& str) {
        ConcreteClass::print(str);
    }
}
int main() {
    int array[]{1, 2, 3, 4, 5};
    std::string array2[]{"one", "two", "three", "four", "five"};
    std::cout << largest(array, 5, std::greater<int>()) << std::endl;
    std::cout << largest(array2, 5, std::greater<std::string>()) << std::endl;
    return 0;
}
#include <iostream>
#include <memory>

class userVector {
    int* data{nullptr};
    size_t size{0};

    public:
    userVector() {
        std::cout << "userVector created" << std::endl;
    }
    userVector(size_t size) : size{size}, data{new int[size]} {
        std::cout << "userVector created" << std::endl;
    }
    userVector(const userVector& other) : size{other.size}, data{new int[other.size]} {
        std::cout << "userVector copied" << std::endl;
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    ~userVector() {
        std::cout << "userVector destroyed" << std::endl;
        delete[] data;
    }
    userVector& operator=(const userVector& other) {
        std::cout << "userVector assigned" << std::endl;
        if (this == &other) {
            return *this;
        }
        delete[] data;
        size = other.size;
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }
    userVector(std::initializer_list<int> il) {
        std::cout << "userVector initializer_list assigned" << std::endl;
        size = il.size();
        data = new int[size];
        size_t i = 0;
        for (const auto& elem : il) {
            data[i++] = elem;
        }
    }
    bool setData(int index, int value) {
        if (index >= size) {
            return false;
        }
        data[index] = value;
        return true;
    } 
};

int main() {
   
    userVector v4{1, 2, 3, 4, 5};
    return 0;
}
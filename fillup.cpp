#include <iostream>
#include <numeric>
#include <array>
#include <string>
#include <vector>

auto my_func(int a, int b) -> int {
    return a + b;
}
struct MyStruct {
    void operator() (int i) {
        std::cout <<"ms: "<< i << " ";
    }
};


struct Animal {
    virtual void speak() = 0;
    virtual ~Animal() {
        std::cout << "Animal destroyed" << std::endl;
    };
};

struct Dog : Animal {
    void speak() override {
        std::cout << "Woof!" << std::endl;
    }
    ~Dog() {
        std::cout << "Dog destroyed" << std::endl;
    }
};

struct Cat : Animal {
    void speak() override {
        std::cout << "Meow!" << std::endl;
    }
    ~Cat() {
        std::cout << "Cat destroyed" << std::endl;
    }
};

struct Cow : Animal {
    void speak() override {
        std::cout << "Moo!" << std::endl;
    }
    ~Cow() {
        std::cout << "Cow destroyed" << std::endl;
    }
};  

int main() {
    #if 0
    auto my_array = std::array<int, 1000>{}; // initialize all elements to 0
    std::iota(my_array.begin(), my_array.end(), 0); // fill with 0, 1, 2, ..., 999
    for (const auto& elem : my_array) {
        std::cout << elem << " ";
    }
    auto print_elem = [](const auto& elem) {
        std::cout << elem << " ";
    };
    std::for_each(my_array.begin(), my_array.end(), print_elem);
    auto my_array2 = std::array<int, 4>{};
    std::for_each(my_array2.begin(), my_array2.end(), print_elem);

    MyStruct my_struct;
    std::for_each(my_array.begin(), my_array.end(), my_struct);
    const auto& concat = std::string("Hello") + "World";
    #endif

    std::vector<Animal*> animals;
    auto dog = new Dog;
    auto cat = new Cat;
    auto cow = new Cow;
    animals.push_back(dog);
    animals.push_back(cat);
    animals.push_back(cow);
    
    for (auto animal : animals) {
        animal->speak();
    }
    delete dog;
    delete cat;
    delete cow; 
    return 0;
}



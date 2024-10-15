#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>

class Utility {
    public:
    Utility() {
        std::cout << "Utility constructor" << std::endl;
    }
    ~Utility() {
        std::cout << "Utility destructor" << std::endl;
    }
    void doSomething() { std::cout << "Doing something" << std::endl; }
};

class UtilityUser {
    std::unique_ptr<Utility> utility;
    public:
    UtilityUser() : utility{std::make_unique<Utility>()} {
        std::cout << "UtilityUser constructor" << std::endl;
    }
    ~UtilityUser() {
        std::cout << "UtilityUser destructor" << std::endl;
    }
    void useUtility() {
        utility->doSomething();
    }
};

int main() {
    UtilityUser uu;
    uu.useUtility();
    using grid = std::vector<std::vector<int>>;
    std::unique_ptr<grid> g;
    if (!g) {
        std::cout << "g is empty" << std::endl;
    }
    g  = std::make_unique<grid>(3, std::vector<int>(3, 10));
    if (g) {
        std::cout << "g is not empty" << std::endl;
    }
    for (auto row : *g) {
        for (auto col : row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
    std::unique_ptr<grid> g2 = std::move(g);
    if (!g) {
        std::cout << "Now g is empty" << std::endl;
    }
    return 0;
}
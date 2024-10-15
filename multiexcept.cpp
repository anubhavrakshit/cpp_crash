#include <iostream>
#include <stdexcept>

struct BuggyStruct {
    BuggyStruct() {
        std::cout << "BuggyStruct constructor" << std::endl;
    }
    ~BuggyStruct() {
        //throw std::runtime_error("BuggyStruct descructor throws exception");
    }
};


int main() {
    try {
        BuggyStruct bs;
        throw std::runtime_error("main throws exception");
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}

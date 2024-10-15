#include <iostream>
#include <string>
#include <fstream>
#include <type_traits>
#include <vector>

template <typename CustomOutput>
class Output : private CustomOutput {
    public:
    void printCustom(const std::string& str) {
        print(str);
    }
    private:
        using CustomOutput::print;
};

class WriteToCout {
    protected:
    void print(const std::string& str) {
        std::cout << str << std::endl;
    }
};

class WriteToFile {
    protected:
    void print(const std::string& str) {
        // write to file
        std::ofstream file("output.txt");
        file << str << std::endl;
    }
};

class BaseClass {
    public:
    virtual std::string getName() = 0;
};

class DerivedClass : public BaseClass {
    public:
    DerivedClass() {
        std::cout << "DerivedClass created" << std::endl;
    }
    DerivedClass(const DerivedClass& other) {
        std::cout << "DerivedClass copied" << std::endl;
    }
    DerivedClass& operator=(const DerivedClass& other) {
        std::cout << "DerivedClass assigned" << std::endl;
        return *this;
    }
    DerivedClass(DerivedClass&& other) {
        std::cout << "DerivedClass moved" << std::endl;
    }
    DerivedClass& operator=(DerivedClass&& other) {
        std::cout << "DerivedClass moved assigned" << std::endl;
        return *this;
    }
    ~DerivedClass() {
        std::cout << "DerivedClass destroyed" << std::endl;
    }
    std::string getName() override {
        return "DerivedClass";
    }
};

class DerivedClass2 : public BaseClass {
    public:
    std::string getName() override {
        return "DerivedClass2";
    }
};

int main() {
    Output<WriteToCout> out;
    out.printCustom("Hello, World!");
    Output<WriteToFile> out2;
    out2.printCustom("Hello, World!");
    using std::cout;
    int num{5};
    cout << "is_rvalue_reference<int&&>: " << std::is_rvalue_reference<int>::value << std::endl;
    DerivedClass d1;
    DerivedClass2 d2;
    std::vector<BaseClass*> collection;
    collection.push_back(&d1);
    collection.push_back(&d2);
    for (auto* elem : collection) {
        cout << elem->getName() << std::endl;
    }
    std::vector<DerivedClass> collection2;
    collection2.push_back(std::move(d1));
    return 0;
}
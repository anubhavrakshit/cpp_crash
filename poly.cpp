#include <variant>
#include <iostream>

using namespace std;

struct aio_engine {
    void print() const{
        cout << "AIO Engine" << endl;
    }
};

struct vector_engine {
    void print() const{
        cout << "Vector Pread/Pwrite Engine" << endl;
    }
};


int main() {
    variant<aio_engine, vector_engine> io_engine;
    io_engine = vector_engine{};
    auto do_print = [](const auto& obj) {obj.print();};
    visit(do_print, io_engine);
    return 0;
}
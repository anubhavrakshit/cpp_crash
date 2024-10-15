#include <iostream>
#include <string>
#include <chrono>

using namespace std;
auto now = std::chrono::system_clock::now();
void getElapsedTime() {
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - now;
    std::cerr << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

template <typename ConcreteMsg>
class MessageSrv {
    public:
    void WriteMessage() {
        getElapsedTime();
        static_cast<ConcreteMsg*>(this)->WriteMessageImpl();
    }
    void WriteMessageImpl() {
        cout << "iDefault WriteMessageImpl" << endl;
    }
};

class ErrorMsg : public MessageSrv<ErrorMsg> {
    public:
    void WriteMessageImpl() {
        cout << "ErrorMsg WriteMessageImpl" << endl;
        getElapsedTime();
    }
};

class InfoMsg : public MessageSrv<InfoMsg> {
    public:
    void WriteMessageImpl() {
        cout << "InfoMsg WriteMessageImpl" << endl;
        getElapsedTime();
    }
};


template <typename T>
void WriteMessage(T& msg) {
    msg.WriteMessageImpl();
}

template <typename T>
class Person {
    public:
    void Interface() {
        static_cast<T*>(this)->print();
    }
    void print() {
        cout << "Name: " << name_ << endl;
    }
};

class Student : public Person<Student> {
    public:
    Student(string name) : name_{name} {}
    void print() {
        cout << "Student Name: " << name_ << endl;
    }
    private:
    string name_;
};

int main() {
    class InfoMsg info;
    class ErrorMsg error;

    WriteMessage(info);
    WriteMessage(error);
    return 0;
}
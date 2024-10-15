#include <iostream>
#include <string>

class BaseLogger {
    public:
    virtual void log(const std::string& message) = 0;
    virtual void doSomething() {
        std::cout << "BaseLogger: Doing something" << std::endl;
    }
    virtual void lastLogMessage() = 0;
    virtual ~BaseLogger() = default;
};

class ConsoleLogger : public BaseLogger {
    public:
    void log(const std::string& message) override {
        lastMessage = message;
        std::cout << "ConsoleLogger: " << message << std::endl;
    }
    void lastLogMessage() override {
        std::cout << "ConsoleLogger: Last log message" << lastMessage << std::endl;
    }
    void doSomething() override {
        std::cout << "ConsoleLogger: Doing something" << std::endl;
    }
    private:
        std::string lastMessage;
};

class FileLogger : public BaseLogger {
    public:
    void log(const std::string& message) override {
        lastMessage = message;
        std::cout << "FileLogger: " << message << std::endl;
    }
    void lastLogMessage() override {
        std::cout << "FileLogger: Last log message" << lastMessage << std::endl;
    }
    void doSomething() override {
        std::cout << "FileLogger: Doing something" << std::endl;
    }
    private:
        std::string lastMessage;
};

void Foo(BaseLogger& logger) {
    logger.doSomething();
    logger.lastLogMessage();
}

void Foo(BaseLogger* logger) {
    logger->doSomething();
    logger->lastLogMessage();
}
int main() {
    ConsoleLogger cl;
    cl.log("Hello");
    FileLogger fl;
    fl.log("World");
    Foo(cl);
    Foo(fl);
    Foo(&cl);
    Foo(&fl);
    return 0;
}
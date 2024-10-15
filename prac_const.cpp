#include <iostream>
#include <string>
#include <utility>
#include <array>

using namespace std;

class SampleClass {
public:
  SampleClass() : state_{true}, name_{"Empty"} {}
  SampleClass(const SampleClass &other) = default;
  SampleClass &operator=(const SampleClass &other) = default;
  SampleClass(SampleClass &&other)
      : name_{std::move(other.name_)}, count_{other.count_},
        state_{other.state_} {
    other.state_ = false;
    other.count_ = 0;
  }
  SampleClass &operator=(SampleClass &&other) {
    if (&other == this) {
      return *this;
    }

    other.state_ = false;
    other.count_ = 0;
    return *this;
  }
  ~SampleClass() { std::cout << "Destruct SampleClass" << std::endl; }
  const std::string &print() { return name_; }
  int setName(const std::string &name) {
    name_ = name;
    return 0;
  }
  int &garbage() {
    int a{100};
    cout << "Address is " << &a << endl;
    return a;
  }

private:
  std::string name_;
  int count_{0};
  bool state_{false};
};

template <typename T, int h> T add(T a, T b) { return a + b + h; }

template <typename T> class tempClass {
public:
  tempClass(T a) : myid_{a} {}
  ~tempClass(){std::cout << "tempClass destruct" << endl;}

private:
  T myid_{};
};

class SampleClass2 {
public:
  SampleClass2(size_t n) : myid_{n} {
    array_int = new int[myid_]{1, 2, 3, 4, 5};
  }
  ~SampleClass2() { std::cout << "Destruct SampleClass2" << std::endl;
    if (array_int != nullptr) {
      delete[] array_int;
    }
  }
  SampleClass2(const SampleClass2 &other) = default;
  SampleClass2 &operator=(const SampleClass2 &other) = default;
  SampleClass2(SampleClass2 &&other) = default;
  SampleClass2 &operator=(SampleClass2 &&other) = default;
  private:
  int* array_int{nullptr};
  size_t myid_{0};
};

int main() {
  SampleClass s1;
  cout << "Now s1 is " << s1.print() << endl;
  s1.setName("Monkey");
  cout << "Now s1 is " << s1.print() << endl;
  auto s2 = std::move(s1);
  cout << "Now s2 is " << s2.print() << endl;
  cout << "Now s1 is " << s1.print() << endl;

  cout << add<int, 3>(100, 340) << endl;
  std::array<int, 5> arr{1, 2, 3, 4, 5};
  for (auto &a : arr) {
    cout << a << endl;
  }
  auto my_name = std::string{"Monkey"};
  cout << my_name << endl;
  auto my_arr = new int[5]{1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    cout << my_arr[i] << endl;
  }
  delete[] my_arr;
  try {
    tempClass<int> t1{100};
    throw std::bad_alloc();
  } catch (const std::exception &e) {
    cout << e.what() << endl;
  }
  cout << "End of program" << endl;
  return 0;
}
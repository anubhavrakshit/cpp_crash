#include <iostream>

using namespace std;

enum class Operation {
    Plus,
    Subtract,
    Divide,
    Multiply,
    Powerof,
};

struct Calculator {
    Operation priv_op;
    Calculator() {
        priv_op = Operation::Divide;
    }
    Calculator (Operation op) {
        priv_op = op;
    }

    int calculate(int a, int b) {
        int ret {0};
        switch (priv_op) {
        case Operation::Plus: {
            cout << "Plus\n";
            ret = a + b;
            break;
        }
        case Operation::Subtract: {
            cout << "Sub\n";
            ret = a - b;
            break;
        }
        case Operation::Divide: {
            cout << "Divide\n";
            ret = a/b;
            break;
        }
        case Operation::Multiply: {
            cout << "Mul\n";
            ret = a * b;
            break;
        }

        default:
            cout << "What is this?\n";
        }

        return ret;
    }
};

int main()
{
    //Calculator calc = {Operation::Plus};
    Calculator calc;
    cout << "Calc ret = " << calc.calculate(10, 30) << endl;
    return 0;
}

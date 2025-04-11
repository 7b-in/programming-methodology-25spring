#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    if ((a >= -b + std::numeric_limits<int>::max()) && (b>=0)) {
        throw std::overflow_error("Integer overflow on addition");
    }

    else if ((a <= -b + std::numeric_limits<int>::min()) && (b < 0)) {
        throw std::overflow_error("Integer overflow on addition");
    }

    else {
        return a + b;
    }
}

int Calculator::sub(int a, int b) {
    if ((a >= b + std::numeric_limits<int>::max()) && (b < 0)) {
        throw std::overflow_error("Integer overflow on subtraction");
    }

    else if ((a <= b + std::numeric_limits<int>::min()) && (b >= 0)) {
        throw std::overflow_error("Integer overflow on subtraction");
    }

    else {
        return a - b;
    }
}

int Calculator::mul(int a, int b) {
    if ((a!=0) && (b!=0)) {
        if (a >= (std::numeric_limits<int>::max() / b)) {
            throw std::overflow_error("Integer overflow on multiplication");
        }

        else if (a <= (std::numeric_limits<int>::min() / b)) {
            throw std::overflow_error("Integer overflow on multiplication");
        }
    }

    return a*b;
}

int Calculator::div(int a, int b) {
    if (b==0) {
        throw std::invalid_argument("Division by zero");
    }

    else if ((a == std::numeric_limits<int>::min()) && (b==-1)) {
        throw std::overflow_error("Intger overflow on division");
    }

    else {
        return a / b;
    }
}
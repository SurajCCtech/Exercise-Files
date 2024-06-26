#include <iostream>

class num {
    int value {};
public:
    num(int x = 0) : value{x} {}
    int getvalue() const { return value; }
    void setvalue(int x) { value = x; }
    operator int () { return value; }
    num& operator++ ();
    num operator++ (int);
    num& operator-- ();
    num operator-- (int);
};


// pre-increment
num& num::operator++ () {
    std::cout << "pre-increment: ";
    value += 1;
    return *this;
}

// post-increment
num num::operator++ (int) {
    std::cout << "post-increment: ";
    auto temp = *this;
    value += 1;
    return temp;
}

// pre-decrement
num& num::operator-- () {
    std::cout << "pre-decrement: ";
    value -= 1;
    return *this;
}

// post-decrement
num num::operator-- (int) {
    std::cout << "post-decrement: ";
    auto temp = *this;
    value -= 1;
    return temp;
}


int main() {
    num n(42);
    std::cout << "value is: "<< n << std::endl;
    std::cout << "value is: "<< n++ << std::endl;
    std::cout << "value is: "<< n << std::endl;

    return 0;
}
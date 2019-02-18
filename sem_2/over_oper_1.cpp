#include <iostream>

struct B {
    int b;
    
    B(int b) : b(b) {}

};

struct A {
    int a;

    A(int a) : a(a) {}
    A(const B &b) : a(b.b) {}

    int operator + () const {
        std::cout << "A::operator +()" << std::endl;
        return this->a;
    }
};

int operator - (const A &a) {
    return 1;
}



int main() {
    //int b = 0;
    A a(1);
    +a;
}

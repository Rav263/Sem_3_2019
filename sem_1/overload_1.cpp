#include <iostream>

void f() {
    std::cout << "f()" << std::endl;
}

void f(int z) {
    std::cout << "f(int) " << z << std::endl;
}

void f(double z) {
    std::cout << "f(double) " << z << std::endl;
}

int main() {
    int z = 12;
    double d = 1.12;

    f();
    f(z);
    f(d);


    char c{};
    f(c);

    long l{};
    f(l);
}

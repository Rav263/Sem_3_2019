#include <iostream>

void f(int a, int b) {
    std::cout << "f(int, int)" << std::endl;
}

void f(double a, double b) {
    std::cout << "f(double, double)" << std::endl;
}

void f(const char *a, double b) {
    std::cout << "f(const char *, double)" << std::endl; 
}

struct A {
    A(int z) {
        std::cout << "A::A(int)" << std::endl;
    }
    explicit A(double z) {
        std::cout << "A::A(double)" << std::endl;
    }

    operator const char *() const {
        std::cout << "operator const char *" << std::endl;
        return "OK";
    }

};

void f(const A &a) {
    std::cout << "f(const A&)" << std::endl;
}



int main() {

    f(1, 2);
    f(1.2, 2.0);
    short z = 1;

    f(z, 1);
    f(nullptr, 1.3);

    f(10);
    f(z);

    f(1.4);
    f(A(1.5));
    f(A(1.2), 10);

    return 0;
}

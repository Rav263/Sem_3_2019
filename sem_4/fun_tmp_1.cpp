#include <iostream>

template<typename C>
void swap(C &a, C &b) {
    std::cout << "C &" << std::endl;
    auto tmp{a};
    a = b;
    b = tmp;
}

template<typename C>
void swap(C *a, C *b) {
    std::cout << "C *" << std::endl;
    auto tmp = *a;
    *a = *b;
    *b = tmp;
}

template<>
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    std::cout << "special" << std::endl;
}

int main() {
    int a = 100;
    int b = 101;

    swap<int>(a, b);
    std::cout << a << " " << b << std::endl;

    double c = 1.1, d = 2.4;

    swap(c, d);
    std::cout << c << " " << d << std::endl;

    double *pc = &c, *pd =  &d;
    std::cout << (void *) pc << " " << (void *) pd << std::endl;
    swap<double *>(pc, pd);

    std::cout << (void *) pc << " " << (void *) pd << std::endl;
    std::cout << c << " " << d << std::endl;
}

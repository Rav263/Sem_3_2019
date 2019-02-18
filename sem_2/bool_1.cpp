#include <iostream>

struct A {
    explicit operator bool () const
    {
        std::cout << "operator bool" << std::endl;
        return true;
    }
};


int main() {
    A a;

    //int z = a;

    //std::cout << z << std::endl;
    while(a) {
     
    }
}

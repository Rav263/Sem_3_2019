#include <iostream>
#include <iomanip>

int main() {
    double z;

    while(std::cin >> z) {
        std::cout << "z: " << std::setprecision(10) << std::setw(10) << std::setfill('x') << z << std::endl;
    }
}

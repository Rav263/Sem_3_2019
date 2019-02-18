#include <iostream>

int main() {
    char c;
    int n = 0;

    std::cin >> std::noskipws;

    while (std::cin >> c) {
        std::cout << c;

        std::cout << (n + '0') << std::endl;
        n = (n + 1) % 10;

    }

}

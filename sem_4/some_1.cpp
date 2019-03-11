#include <iostream>


auto f(int s) {
    std::cout << s << std::endl;
    return double(s);
}

auto g(int s) -> double {
    std::cout << s << std::endl;

    return s;
}

/*
auto h(auto a, auto b) {
    return a + b;
}*/


int main() {
    auto x = 10;
    std::cout << g(x) << std::endl;
  //  std::cout << h(100, 200) << std::endl;
}


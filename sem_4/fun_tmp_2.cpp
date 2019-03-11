#include <iostream>
#include <vector>
#include <functional>

template<typename T>
auto sum_1(const T &v, typename T::value_type s = {}) {
    for (const auto &x : v) {
        s += x;
    }
    return s;
}

template<typename T, typename F>
auto sum_2(const T &v, F f, typename T::value_type s = {}) {
    for (const auto &x : v) {
        f(s, x);
    }
    return s;
}


void func(int &s, int x) {
    s += x;
}


class Z 
{
public:
    void operator()(int &s, int x) {s += x;}
};

template<typename T>
class S
{
public:
    void operator()(T &s, T x) { s += x;}
};

int main() {
    std::vector<int> v1 {1, 2, 3, 4, 5, 6};

    std::cout << sum_1(v1) << std::endl;
    std::cout << sum_2(v1, func, 10) << std::endl;
    std::cout << sum_2(v1, Z{}, 15) << std::endl;
    std::cout << sum_2(v1, S<int>(), 20) << std::endl;
    std::cout << sum_2(v1, [](auto &s, auto x) {s += x;}, 25) << std::endl;
    std::cout << sum_2(v1, [](int &s, int x) {s += x;}, 30) << std::endl;
    std::cout << sum_2(v1, std::function<void (int &, int)>(func), 35) << std::endl;
}

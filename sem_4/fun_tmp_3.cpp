#include <iostream>
#include <vector>
#include <functional>

template<typename T>
auto sum_1(T beg, T end, typename T::value_type s = {}) {
    for (; beg != end; beg++) {
        s += *beg;
    }
    return s;
}


int main() {
    std::vector<int> v1 {1, 2, 3, 4, 5, 6};

    std::cout << sum_1(v1.begin(), v1.end()) << std::endl;
}

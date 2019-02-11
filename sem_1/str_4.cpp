#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>

struct String {
    size_t size{0};
    char *str = nullptr;

    String() = default; //Указание компилятору генерировать конструктор по умолчанию

    String(const char *str) {
        if (str) {
            String::size = strlen(str);
            String::str = new char[String::size + 1];
            memcpy(String::str, str, String::size + 1); // не тру
            // std::copy -- тру
        }
    }

    String(const String &s) : size{s.size}, str{s.str}
    {
        if (str) {
            str = new char[size + 1];
            memcpy(str, s.str, size + 1);
        }
    }

    ~String() { // Деструктор
        std::cout << "del  " << str << std::endl;
        delete[] str; // ВАЖНО
    }

    /*String &operator =(const String &s) { ТРУ ПРИСВАИВАНИЕ
        if (this == &s) return *this;
        delete[] str;
        
        str = s.str;
        size = s.size;

        if (str) {
            str = new char[size + 1];
            memcpy(str, s.str, size + 1);
        }

        return *this;
    }*/

    void swap(String &s) {
        std::swap(s.size, this->size);
        std::swap(s.str, this->str);
    }

    String &operator =(String s) { // Магия copy and swap
        swap(s);

        return *this;
    }
    
    size_t get_size() const {
        return size;
    }
    
    const char *c_str() const{
        return str;
    }
};

void f(String str) {
    std::cout << str.str << std::endl;
}


String s2 = String("bbbbb");

int main() {
    String s1("aaaaa");
    std::cout << s1.str << std::endl;

    std::cout << s2.str << std::endl;

    String s3{"ccccc"};
    std::cout << s3.str << std::endl;

    f(s3);
}


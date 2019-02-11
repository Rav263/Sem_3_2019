#include <string.h>
#include <iostream>

struct String {
    size_t size;
    char *str;

    String() {
        String::size = 0;
        str = nullptr;
        std::cout << "String()" << std::endl;
    }
};


void init_string(String *s1, const char *str) {
    s1->str = strdup(str);
    s1->size = strlen(str);
}


int main() {
    std::cout << "main()" << std::endl;
    String s1;
    std::cout << "after s1" << std::endl;

    String *s2 = new String;


    std::cout << s2->str << std::endl;
    init_string(&s1, "abc");

    free(s1.str);

}

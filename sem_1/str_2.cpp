#include <string.h>
#include <iostream>

struct String {
    size_t size;
    char *str;
};


void init_string(String *s1, const char *str) {
    s1->str = strdup(str);
    s1->size = strlen(str);
}


int main() {
    String s1;
    
    init_string(&s1, "abc");

    free(s1.str);
}

#include <iostream>
#include <stdlib.h>
#include <string.h>

struct String 
{
    size_t size;
    char *str;
};


int main() {
    String s1;

    s1.str = strdup("qwe");
    s1.size = 3;

    free(s1.str);

    return 0;
} 

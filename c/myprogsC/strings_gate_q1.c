#include <stdio.h>

void func1 (char * s1, char *s2) {
        char *tmp;
        tmp = s1;
        s1 = s2;
        s2 = tmp;
}

void func2 (char **s1, char **s2) {
        char *tmp;
        tmp = *s1;
        *s1 = *s2;
        *s2 = tmp;
}

int main () {
        char *str1 = "Hi", *str2 = "Bye";
        func1(str1, str2);
        printf("%s %s", str1, str2);
        func2(&str1, &str2);
        printf("%s %s", str1, str2);
}

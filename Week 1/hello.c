#include <stdio.h>

int main(void)
{
    char name[40];
    printf("Enter your name: ");
    fgets(name, 40, stdin);
    printf("Hello, %s", name);
}
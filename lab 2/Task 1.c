#include <stdio.h>

int main()
{
    char l;
    while ((l = getchar()) != EOF) { //Считываем символ
        if (l != ' ' && l != '\t') putchar(l); //Выводим этот символ, если он не пробел и не табуляция
    }
    return 0;
}
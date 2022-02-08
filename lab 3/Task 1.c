#include <stdio.h>

int main() // Оно почему-то не проходит 4-ый тест. Я отредактирую эту программу ближе к сроку её сдачи. Если этого не произошло, то я забыл, прошу напомнить.
{
    char l, lbegin, lend;
    int flag = 0;

    while ((l = getchar()) != EOF) {
        if (l == '-') flag = 1;
        else if (flag == 0) lbegin = l;
        else {
            lend = l;
            break;
        }
    }
    if (lbegin > lend) {
        while (lbegin != lend) {
            int letter = lbegin;
            putchar(letter);
            lbegin--;
        }
        putchar(lend);
    }
    else {
        while (lbegin != lend) {
            int letter = lbegin;
            putchar(letter);
            lbegin++;
        }
        putchar(lend);
    }
    return 0;
}
#include <stdio.h>

int main()
{
    char l1; // Текущий символ.
    char l2 = getchar(); // Предыдущий символ.
    int count = 0; // Количество подряд идущих симолов.
    while ((l1 = getchar()) != EOF) {
            if (count >= 2 && l1 != l2) { // Подряд шли 3 или более символов. Выводим их.
                for (int i = 0; i <= count; i++) { 
                    putchar(l2);
                }
                printf("\n");
                l2 = l1;
                count = 0;
            }
            else if (l1 != l2) { // Подряд шло менее 3 символов. Обнуляем счетчик.
                count = 0;
                l2 = l1;
            }
            else if (l1 == l2) count++; // Символы повторятся, считаем их.
    }
	
    if (count >= 2 && l1 != l2) { // Проверяем для последнего введенного символа (он не помещается в цикл).
        for (int i = 0; i <= count; i++) {
            putchar(l2);
        }
        printf("\n");
        l2 = l1;
        count = 0;
    }
    return 0;
}
#include <stdio.h>

char * remove_char(char string1[], char string2[]) {
	int i = 0;
	char l;

	while ((l = string2[i]) != '\0') { // Проходимся по элементам второй строки.
		int j = 0;
		while (string1[j] != '\0') { // Проходимся по элементам первой строки.
			if (string1[j] == l) { // Если они равны, то сдвигаем все элементы первой строки, начианая со следующего на -1.
				int k = j;
				while (string1[k] != '\0') {
					string1[k] = string1[k + 1];
					k++;
				}
				j--;
			}
			j++;
		}
		i++;
	}

	return string1; // Возвращаем полученную строку.
}

int main() {
	char l, str1[9001], str2[9001];
	int i = 0;
	while ((l = getchar()) != '\n') { // Считываем первую строку.
		str1[i] = l;
		i++;
	}
	str1[i] = '\0';
	i = 0;
	while ((l = getchar()) != EOF) { // Считываем вторую строку.
		str2[i] = l;
		i++;
	}
	str2[i] = '\0';

	char* str = remove_char(str1, str2);
	
	i = 0;
	
	while (str[i] != '\0') { // Выводим полученную строку.
		putchar(str[i]);
		i++;
	}
	return 0;
}
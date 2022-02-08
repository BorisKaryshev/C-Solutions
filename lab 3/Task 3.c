#include <stdio.h> 

void draw_horizontal_gistagramm(int count[]) { // Выводим горизонтальную гистограмму по полученным данным.
	for (int i = 0; i < 10; i++) {
		printf("%d", i);
		printf(": ");
		for (int j = 0; j < count[i]; j++) {
			printf("#");
		}
		putchar('\n');
	}
}

void draw_vertical_gistogramm(int count[]) { // Выводим вертикальную гистограмму по полученным данным.
	int max = 0;
	for (int i = 0; i < 10; i++) if (count[i] > max) max = count[i];
	for (int i = max; i > 0; i--) {
		for (int j = 0; j < 10; j++) {
			if (count[j] == i) {
				printf("# ");
				count[j]--;
			}
			else printf("  ");
		}
		putchar('\n');
	}
	printf("0 1 2 3 4 5 6 7 8 9");
}

int main() { // Данная программа решена криво, тут можно обойтись без запоминания введенной строки.
	char l, string[9001]; 
	int length = 0;
	while ((l = getchar()) != EOF) { // Считываем символы.
		if (l == '0' || l == '1' || l == '2' || l == '3' || l == '4' || l == '5' || l == '6' || l == '7' || l == '8' || l == '9') {
			string[length] = l;
			length++;
		}
	}
	string[length] = '\0';
	
	int number;
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < length; i++) { // Cчитаем количество цифр.
		number = string[i] - 48;
		count[number]++;
	}
	putchar('\n');
	draw_horizontal_gistagramm(count);
	putchar('\n');
	draw_vertical_gistogramm(count);

	return 0;
}
#include <stdio.h>

int convert_number(int input[], int length) {
	int number = 0;
	int sixteen = 1;
	for (int i = 1; i <= length; i++) {
		number += input[length-i] * sixteen;
		sixteen *= 16;
	}

	return  number;
}

int main() {
		char l = ' ';
		int length = 0;
		int positive = 1;
		int input[1001];
		while ((l = getchar()) != '\n') {
			if (l >= 'A' && l <= 'F') l = l - 'A' + 'a';
			if (l >= 'a' && l <= 'f') input[length] = l - 87;
			else input[length] = l - 48;

			length++;
		}

		int number = convert_number(input, length);
		
		printf("%d", number);

	return 0;
}
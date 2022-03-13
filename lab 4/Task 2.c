#include <stdio.h>

int read_hexadecimal_number() {
	char l = ' ';
	char input[1001];
	for (int i = 0; i < 1001; i++) input[i] = '0';
	int length = 0;

	while (l = getchar()) {
		if (l == EOF || l == '\n') break;
		if (l >= 'a' && l <= 'f') {
			input[length] = l - 'a' + 10;
			length++;
		}
		else if (l >= 'A' && l <= 'F') {
			input[length] = l -'A' + 10;
			length++;
		}
		else if (l >= '0' && l <= '9') {
			input[length] = l - '0';
			length++;
		}
	}

	int decimal_number = 0;
	int basement = 1;

	length--;
	for (int i = length; i >= 0; i--) {
		decimal_number += input[i] * basement;
		basement *= 16;
	}

	return decimal_number;
}

int main() {

	int x = read_hexadecimal_number();
	
	int count = 0;
	while (x > 0) {
        count+=x&1;
        x = x >> 2;
	}
	printf("%d ", count);
}
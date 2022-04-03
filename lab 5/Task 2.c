#include <stdio.h>
#include <stdlib.h>

int isInString(char x, char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == x)
			return 1;
	}
	return 0;
}

char* ReadString() {
	char x;
	int i = 0;
	char* s = NULL;
	while ((x = getchar()) != '\n' && x != EOF) {
		s = (char*)realloc(s, (i + 1) * sizeof(char));
		s[i++] = x;
	}
	s = (char*)realloc(s, (i + 1) * sizeof(char));
	s[i] = '\0';

	return s;
}

int main() {
	char* first_string = ReadString();
	char* second_string = ReadString();
	int x;

	for (int i = 0; first_string[i] != '\0'; i++) {
		if (isInString(first_string[i], second_string)) {
			printf("%d", i);
			return 0;
		}
	}

	puts("-1");
	return 0;
}
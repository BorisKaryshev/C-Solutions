#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 100

static double stack[STACK_SIZE];
static int top = -1;

void push(double n) {
    if (top + 1 < STACK_SIZE) {
        stack[++top] = n;
    } else {
        printf("error: stack is full\n");
        exit(111);
    }
}

double pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("error: stack is empty\n");
        exit(222);
    }
}

#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop (char []);

int main() {
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER :
                push (atof (s));
                break;
            case '+' :
                push (pop() + pop());
                break;
            case '*' :
                push (pop() * pop());
                break;
            case '-' :
                op2 = pop();
                push (pop() - op2);
                break;
            case '/' :
                op2 = pop();
                if (op2 != 0.0)
                    push (pop() / op2);
                else {
                    printf("error: zero divisor\n");
                    return 0;
                }
                break;
            case '^':
                push(pow(pop(), pop()));
                break;
            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'c':
                push(cos(pop()));
                break;
            case '\n' :
                op2 = pop();
                if (roundf(op2) != op2)
                    printf("%.6f", op2);
                else
                    printf("%d", (int) op2);
                return 0;
            default :
                printf("error: unknown command %s\n", s);
                return 0;
        }
    }
    return 0;
}

int getop(char* s) {
	int i = 0;
	char c;
	while ((c = getchar()) == ' ' || c == '\t');
	if (isdigit(c)) {
		s[i++] = c;
		while (i < MAXOP && isdigit(c = getchar()) || c == '.')
			s[i++] = c;
		s[i] = '\0';
		return NUMBER;
	}
    else if (c == '\n' || c == EOF)
        return '\n';
	s[i++] = c;
	while (i < MAXOP && (c = getchar()) != ' ' && c != '\n' && c != EOF && c != '\t')
		s[i++] = c;
	if (c == '\n' || c == EOF)
		rewind(stdin);
	s[i] = '\0';
    
	if (!strcmp("+", s))
		return '+';
	else if (!strcmp("-", s))
		return '-';
	else if (!strcmp("*", s))
		return '*';
	else if (!strcmp("/", s))
		return '/';
	else if (!strcmp("^", s))
		return '^';
	else if (!strcmp("%", s))
		return '%';
	else if (!strcmp("sin", s))
		return 's';
	else if (!strcmp("cos", s))
		return 'c';
    
	return 0;
}
#include <stdio.h>

int main() {
	
    for (int i = 1; i <= 10; i++){ 
        printf("\n");
        for (int j = 1; j <= 10; j++) {
            if (j!=1) printf("%4d", i*j);
            else if (i!=10) printf(" %d", i*j);
            else printf("%d", i*j);
        }   
    }
	
	return 0;
}
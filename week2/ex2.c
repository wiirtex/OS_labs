#include <stdio.h>
#include <string.h>

void reversed(char a[], int length) {
	for (int i = length-1; i>= 0; i--) {
		printf("%c", a[i]);
	}
}

int main() 
{
	char s[50];
	scanf("%s", s);
	printf("input - %s\n", s);
	reversed(s, strlen(s));
	printf("\n");
	return 0;

}

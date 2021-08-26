#include <stdio.h>

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("Input: %d, %d\n", a, b);
	swap(&a, &b);
	printf("Output: %d, %d\n", a, b);
}

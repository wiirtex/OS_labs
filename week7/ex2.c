#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	
	if (argc < 2)
	{
		printf("I need N");
		return 0;
	}
	int N = 0;
	for (int i = 0; i < strlen(argv[1]); i++) {
		N = N * 10 + argv[1][i]-'0';
	}
	int* a = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		a[i] = i;
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", a[i]);
	}
	free(a);
	printf("\n");
}

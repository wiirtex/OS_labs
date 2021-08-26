#include <stdio.h>

int main() 
{
	printf("check1\n");
	int n;
	char a[50];
	scanf("%s", a);
        sscanf(a, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = n-i; j > 0; j--)
		{
			printf(" ");
		}	
		for (int j = 0; j <= 2 * i; j++)
		{
			printf("*");
		}
		for (int j = n-i; j > 0; j--)
		{
			printf(" ");
		}
		printf("\n");
	}
	printf("check2\n");
	return 0;
}

#include <stdio.h>
					
int main(int argc, char *argv[] ) 
{
	int n;	
	printf("check1\n");
    sscanf(argv[1], "%d", &n);
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

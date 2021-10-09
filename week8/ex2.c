#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


// I work on a free cloud machine, provided by Oracle fpr my friend. So because it is free, I have very limited memory.
// So I can not allocate very big amounts of memory. But I think, this program provides enough  information for thoughts.

int main()
{
// running this program with vmstat, we can see how the free memory is reducing. Exactly 10MB per iteration.
// in my case si and so fields are almost constant (0). Maybe it is because I don't allocate enough memory.
// After the finishing of the program, we can see, that program frees all allocated memory (without my command)
	char * ptr;
	for (int i = 0; i < 10; i++)
	{
		ptr = (char*)malloc(10 * 1024 * 1024);	
		memset(ptr, 0, 10*1024*1024);
		printf("Running\n");
		sleep(1);
//		free(ptr);
	}
	printf("program finished\n");
}

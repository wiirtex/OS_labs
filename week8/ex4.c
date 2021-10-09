#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
	char * ptr;
	for (int i = 0; i < 10; i++)
	{
		ptr = (char*)malloc(10 * 1024 * 1024);	
		memset(ptr, 0, 10*1024*1024);
		printf("\nRunning\n");
		sleep(1);
		int who;
		struct rusage u;
		int re = getrusage(RUSAGE_SELF, &u);
		printf("Memory usage: %ld\n", u.ru_maxrss);
//		free(ptr);
	}
	printf("program finished\n");
}

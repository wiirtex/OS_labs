
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
  
// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void *myThreadFun(void * vargp)
{
	static int p = 0;
	int *m = (int*)vargp;
    printf("My number: %d\n", p++);
}
   
int main()
{
	const int N = 10;
    pthread_t thread_id;
    printf("Start program\n");
	for (int i = 0; i < N; i++) {
		printf("Creating a process %d\n", i);
	    pthread_create(&thread_id, NULL, myThreadFun, NULL);	
	}
   printf("Finish\n");
    exit(0);
}

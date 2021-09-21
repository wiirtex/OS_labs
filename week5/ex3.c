
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define size 100
#define resSize 1000
int buffer[size];
int length = 0;
pthread_cond_t c;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t p;
int result[resSize];
int cnt = 0;
int initial[resSize];
int num = 0;

void *producer(void *arg) {
	printf("producer starts\n");
	while (num < resSize) {
    	if (length == size) {
			printf("producer starts to sleep\n");
			pthread_cond_wait(&p, &m);	
		}
		buffer[length++] = initial[num++];
		pthread_cond_signal(&c);
	}
	printf("producer finishes\n");
	pthread_cond_signal(&c);
}
  
void* consumer(void *arg) {
printf("consumer starts\n");
	while (cnt < resSize) {
		if (length == 0) {
			printf("consumer starts to sleep\n");
			pthread_cond_wait(&c, &m);
		}
		int value = buffer[length--];
		result[cnt++] = value;
		pthread_cond_signal(&p);
	}
	printf("consumer finishes\n");
}
int main()
{
    pthread_t id1, id2;
	for (int i = 0; i < resSize; i++) {
		initial[i] = i + 1;	
	}
    printf("Start program\n");
		printf("Creating processes\n");
	    pthread_create(&id1, NULL, producer, NULL);	
		pthread_create(&id2, NULL, consumer, NULL);	
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	printf("Processes finished\n");
	for (int i = 0; i < resSize; i++) {
		printf("%d ", result[i]);
	}
	
   printf("\nFinish\n");
    exit(0);
}

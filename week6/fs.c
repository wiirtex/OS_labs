#include <stdio.h>
#include <stdlib.h>


void fcfs(int* a, int* b, int size, int* p)
{
	//sorting arrays
	for (int i = 0; i < size; i++) 
	{	
		for (int j = i + 1; j < size; j++) 
		{
			if (a[i] > a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
				t = b[i];
				b[i] = b[j];
				b[j] = t;
				t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
	int* w = (int*)malloc(sizeof(int) * size);
	int* t = (int*)malloc(sizeof(int) * size);
	int* c = (int*)malloc(sizeof(int) * size);
	float  avg_t = 0, avg_w = 0;
	for (int i = 0; i < size; i++) 
	{
		w[i] = a[0] - a[i];
		for (int j = 0; j < i; j++) 
		{
			w[i] += b[j];
		}
		t[i] = b[i] + w[i];
		c[i] = t[i] + a[i];
		avg_t += t[i];
		avg_w += w[i];
	}
	avg_t /= size * 1.;
	avg_w /= size * 1.;
	printf("process #   wait turna compl\n");
	for (int i = 0; i < size; i++) 
	{
		printf("process %2d %5d %5d %5d\n", p[i], w[i], t[i], c[i]);
	}
	printf("avg_t = %f; avg_w = %f\n", avg_t, avg_w);
}

int main(int argc, char* argv[])
{
	if (argc < 2) {printf("I need a number of processes\n"); return 0;}

	int size = argv[1][0] - '0';

	printf("N = %d\n",  size);
	
	int* a = (int*)malloc(sizeof(int) * size);
	int* b = (int*)malloc(sizeof(int) * size);
	int* p = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		printf("process %d\narr time = ", i + 1);
		scanf("%d", &a[i]);
		printf("bur time = ");
		scanf("%d", &b[i]);
		p[i] = i + 1;
	}

	fcfs(a, b, size, p);
}

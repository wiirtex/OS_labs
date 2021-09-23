#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void rr(int* a, int* b, int* p, int size, int quantum)
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
	int* c = (int*)malloc(sizeof(int) * size);
	int* w = (int*)malloc(sizeof(int) * size);
	int* ti = (int*)malloc(sizeof(int) * size);
	int* r = (int*)malloc(sizeof(int) * size);
	bool* d = (bool*)malloc(sizeof(bool) * size);
	w[0] = 0;
	for (int i = 0; i < size; i++) 
	{
		r[i] = b[i];
	}
	int t = a[0];
	int left = size;
	float avg_w = 0, avg_t = 0;
	while (left > 0)
	{
		for (int i = 0; i < size; i++) 
		{
			if (!d[i])
			{
				if (a[i] < t && r[i] > 0)
				{
					t += quantum;
					r[i] -= quantum;
				}
				else 
				{
					t += r[i];
					w[i] = t - b[i] - a[i];
					r[i] = 0;
					c[i] = t;
					ti[i] = c[i];
					avg_w += w[i];
					avg_t += ti[i];
					d[i] = true;
					left--;
				}
			}
		}
	}
	avg_w /= size;
	avg_t /= size;
        for (int i = 0; i < size; i++)
        {
                printf("process %2d %5d %5d %5d\n", p[i], w[i], ti[i], c[i]);
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

        rr(a, b, p, size, 5);
}



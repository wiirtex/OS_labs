#define _CRT_SECURE_NO_WARNINGS


#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

int find(int* a, int size, int f)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == f)
		{
			return i + 1;
		}
	}
	return -1;
}

void move(int* a, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		a[i + 1] = a[i];
	}
}

void move_back(int* a, int start, int size)
{
	for (int i = start; i < size - 1; i++)
	{
		a[i] = a[i + 1];
	}
}

void delete_(int* a, int n, int size)
{
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] == n)
		{
			move_back(a, i, size - cnt);
			cnt++;
		}
	}
}

void print(int* a, int size)
{
	printf("hello: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int n = 100, mi = 10;
	bool* r_bits = (bool*)calloc(n, sizeof(bool));
	int* pageframes = (int*)calloc(n, sizeof(int));
	int* counters = (int*)calloc(n, sizeof(int));
	int prev_time = 0;
	int* last_modified = (int*)calloc(10000, sizeof(int));
	int* just_added = (int*)calloc(mi, sizeof(int));
	double h = 0, m = 0;
	int places_free = n - 1;
	FILE* pages = fopen("sample.txt", "r");
	fscanf(pages, "%d", pageframes);
	//print(just_added, mi);
	
	FILE* output = fopen("ex3_o.txt", "w");
	while (!feof(pages))
	{
		int page;
		fscanf(pages, "%d", &page);
		int time = prev_time + 1;

		bool success = 0;
		for (int j = 0; j < n; j++)
		{
			if (pageframes[j] == page)
			{
				h++;
				r_bits[j] = true;
				success = 1;
				fprintf(output, "1\n");
				last_modified[j] = time;
				//move(just_added, m);
				//just_added[0] = j;
				break;
			}
		}
		if (!success)
		{
			m++;
			int smallest = (1 << 10) - 1, smallest_index = 0;
			for (int k = 0; k < n; k++)
			{
				if (counters[k] < smallest || (counters[k] == smallest && find(just_added, mi, k) > find(just_added, mi, smallest_index)))
				{
					smallest_index = k;
					smallest = counters[k];
				}
			}
			delete_(just_added, smallest_index, mi);
			move(just_added, mi);
			just_added[0] = smallest_index;
			last_modified[smallest_index] = time;
			r_bits[smallest_index] = true;
			counters[smallest_index] = 0;
			pageframes[smallest_index] = page;
			fprintf(output, "0\n");
		}
		if (time != prev_time)
		{
			for (int j = 0; j < n; j++)
			{
				counters[j] = (counters[j] >> 1) | (r_bits[j] << 7);
				r_bits[j] = 0;
			}
			for (int j = 0; j < mi; j++)
			{
				just_added[j] = 0;
			}
		}
		prev_time = time;
		//print(just_added, mi);
	}
	fprintf(output, "hits: %lf, misses: %lf, hits/misses: %lf", h, m, h / m);
}
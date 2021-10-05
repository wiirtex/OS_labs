#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t getsize(void* ptr)
{
	size_t* t = ptr;
	if (t)
	{
		--t;
		return *t;
	}
	return -1;
}

void* realloc_(void* ptr, int size)
{
	if (ptr == NULL)
	{
		return malloc(size);
	}
	if (size == 0)
	{
		free(ptr);
		return ptr;
	}
	void* a = malloc(size);
	memcpy(a, ptr, getsize(ptr));
	free(ptr);
	return a;
}

int main()
{
	int* a = (int*)malloc(10 * sizeof(int));
	for (int i = 0; i < 10; i++) 
	{
		a[i] = i;
	}
	a = (int*)realloc_(a, 15*sizeof(int));
	for(int i = 0; i < 15; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

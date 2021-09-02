#include <stdio.h>

int* bubble_sort(int* a, int size) 
{
	for (int i = 0; i < size; i++) 
	{
		for (int j = i + 1; j < size; j++)
		{
			if (a[i] > a[j])
			{	
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	return a;
}

int main() {
	int arr[] = {2, 5, 9, 12, 3, 4, 2, 1, 0};
bubble_sort(arr, 9);
	for (int i = 0; i < 9; i++) 
	{
		printf("%d ", arr[i]);
	}
}

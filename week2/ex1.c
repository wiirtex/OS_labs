#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int i;
	float f;
	double d;
	i = INT_MAX;
	f = FLT_MAX;
	d = DBL_MAX;
	printf("INT Maximum = %d, INT Size = %lu\n", i, sizeof i);
	printf("FLOAT Maximum = %f, FLOAT Size = %lu\n", f, sizeof f);
	printf("DOUBLE Maximum = %f, DOUBLE Size = %lu\n", d, sizeof d);
	return 0;
}

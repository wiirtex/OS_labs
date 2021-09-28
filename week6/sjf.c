#include <stdio.h>
#include <stdlib.h>

void swj(int* a, int* b, int* p, int size)
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
                t = b[i];
                b[i] = b[j];
                b[j] = t;
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] == a[j] && b[i] > b[j])
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
    int* d = (int*)malloc(sizeof(int) * size);
    w[0] = 0;
    int t = 0;
    int left = size;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                int best = 0;
                for (int pp = 0; pp < size; pp++)
                {
                    if (a[pp] < t && a[pp] <= c[k - 1] && b[pp] < b[best] && !d[k])
                    {
                        best = pp;
                    }
                }

                {
                    w[k] = a[0] - a[k];
                    for (int ww = 0; ww < k; ww++)
                    {
                        w[k] += b[ww];
                        d[k] = !d[k];
                    }
                }
                t++;
            }
        }

        float avg_w = 0, avg_t = 0;
        for (int i = 0; i < size; i++)
        {
            ti[i] = b[i] + w[i];
            c[i] = ti[i] + a[i];
            avg_w += w[i];
            avg_t += ti[i];
        }
        avg_w /= size;
        avg_t /= size;
        for (int i = 0; i < size; i++)
        {
            printf("process %2d %5d %5d %5d\n", p[i], w[i], ti[i], c[i]);
        }
        printf("avg_t = %f; avg_w = %f\n", avg_t, avg_w);
    }
}

    int main(int argc, char* argv[])
    {
        if (argc < 2)
        {
            printf("I need a number of processes\n"); return 0;
        }

        int size = argv[1][0] - '0';

        printf("N = %d\n", size);

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

        swj(a, b, p, size);
    }


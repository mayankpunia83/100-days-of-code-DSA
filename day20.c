#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

int main()
{
    int n;

    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    long long *prefix = (long long *)malloc((n + 1) * sizeof(long long));
    if (prefix == NULL)
    {
        printf("Memory allocation failed\n");
        free(arr);
        return 1;
    }

    prefix[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    qsort(prefix, n + 1, sizeof(long long), compare);

    long long count = 0;
    long long freq = 1;

    for (int i = 1; i <= n; i++)
    {
        if (prefix[i] == prefix[i - 1])
        {
            freq++;
        }
        else
        {
            count += (freq * (freq - 1)) / 2;
            freq = 1;
        }
    }

    count += (freq * (freq - 1)) / 2;

    printf("%lld\n", count);

    free(arr);
    free(prefix);

    return 0;
}
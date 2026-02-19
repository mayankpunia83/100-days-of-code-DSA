#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int i = 0;
    int j = n - 1;
    int min = 1000000000;
    int a, b;

    while (i < j)
    {
        int sum = arr[i] + arr[j];

        if (abs(sum) < min)
        {
            min = abs(sum);
            a = arr[i];
            b = arr[j];
        }

        if (sum < 0)
            i++;
        else
            j--;
    }

    printf("%d %d", a, b);

    return 0;
}

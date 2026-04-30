#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int canPlaceCows(int stalls[], int n, int k, int dist)
{
    int count = 1;
    int last_pos = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last_pos >= dist)
        {
            count++;
            last_pos = stalls[i];
        }

        if (count == k)
            return 1;
    }

    return 0;
}

int aggressiveCows(int stalls[], int n, int k)
{

    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (canPlaceCows(stalls, n, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stalls[i]);
    }

    int result = aggressiveCows(stalls, n, k);
    printf("%d\n", result);

    return 0;
}
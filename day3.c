// Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>

int main() {
    int n, k, count = 0;

    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    for(int i = 0; i < n; i++) {
        count++;
        if(a[i] == k) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d", count);
            return 0;
        }
    }

    printf("Not Found\n");
    printf("Comparisons = %d", count);

    return 0;
}

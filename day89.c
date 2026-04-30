#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;
        if (sum + arr[i] > maxPages) {
            students++;
            sum = arr[i];
            if (students > m)
                return 0;
        } else {
            sum += arr[i];
        }
    }
    return 1;
}

int allocateBooks(int arr[], int n, int m) {
    int low = 0, high = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("%d", allocateBooks(arr, n, m));
    return 0;
}
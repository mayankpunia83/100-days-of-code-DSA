#include <stdio.h>
int isMirror(int arr[], int n, int i, int j) {
    
    if (i >= n && j >= n) return 1;

    
    if (i >= n || j >= n) return 0;
    if (arr[i] == -1 && arr[j] == -1) return 1;
    if (arr[i] == -1 || arr[j] == -1) return 0;

    
    if (arr[i] != arr[j]) return 0;

    
    return isMirror(arr, n, 2*i + 1, 2*j + 2) &&
           isMirror(arr, n, 2*i + 2, 2*j + 1);
}

int isSymmetric(int arr[], int n) {
    if (n == 0) return 1;
    return isMirror(arr, n, 1, 2);  
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isSymmetric(arr, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
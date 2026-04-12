#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define SIZE 100

int table[SIZE];

void init(int m) {
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;
}

void insert(int key, int m) {
    for (int i = 0; i < m; i++) {
        int index = (key % m + i * i) % m;
        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }
}

int search(int key, int m) {
    for (int i = 0; i < m; i++) {
        int index = (key % m + i * i) % m;
        if (table[index] == EMPTY) return 0;
        if (table[index] == key) return 1;
    }
    return 0;
}

int main() {
    int m, n;
    printf("Enter table size: ");
    scanf("%d", &m);

    printf("Enter number of operations: ");
    scanf("%d", &n);

    init(m);

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        printf("Enter operation (INSERT/SEARCH key): ");
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
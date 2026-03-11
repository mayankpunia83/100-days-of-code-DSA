#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x){
    heap[size] = x;
    int i = size;
    size++;

    while(i != 0 && heap[(i-1)/2] > heap[i]){
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapifyDown(int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i){
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

int extractMin(){
    if(size <= 0)
        return -1;

    int root = heap[0];
    heap[0] = heap[size-1];
    size--;

    heapifyDown(0);

    return root;
}

int peek(){
    if(size <= 0)
        return -1;
    return heap[0];
}

int main(){
    int n;
    scanf("%d", &n);

    while(n--){
        char op[20];
        scanf("%s", op);

        if(strcmp(op, "insert") == 0){
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "extractMin") == 0){
            printf("%d\n", extractMin());
        }
        else if(strcmp(op, "peek") == 0){
            printf("%d\n", peek());
        }
    }

    return 0;
}
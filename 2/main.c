#include <stdio.h>

#define MAX_SIZE 100

int size = 0;

void swap(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void heapify(int array[], int size, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] > array[largest])
        largest = l;
    if (r < size && array[r] > array[largest])
        largest = r;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
}

void insert(int array[], int newNum) {
    if (size >= MAX_SIZE) {
        printf("Queue is full. Cannot insert more elements.\n");
        return;
    }

    array[size] = newNum;
    size++;

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }
    }

    int extractMax(int array[]) {
    if (size <= 0) {
        printf("Queue is empty. Cannot extract.\n");
        return -1; 
    }

    int max = array[0];
    array[0] = array[size - 1];
    size--;
    heapify(array, size, 0);

    return max;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[MAX_SIZE];

    insert(array, 3);
    insert(array, 4);
    insert(array, 9);
    insert(array, 5);
    insert(array, 2);

    printf("Original queue: ");
    printArray(array, size);

    int max = extractMax(array);
    printf("Max priority element extracted: %d\n", max);

    printf("Queue after extraction: ");
    printArray(array, size);

    return 0;
}
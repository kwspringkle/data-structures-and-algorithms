#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int icmp(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    if (*x < *y)
        return -1;
    else
        return 1;
}

int main() {
    int capacity = 10; 
    int size = 0;       
    int *arr1 = malloc(capacity * sizeof(int));

    int num;
    while (scanf("%d", &num) == 1) {
        if (size == capacity) {
            capacity *= 2;
            arr1 = realloc(arr1, capacity * sizeof(int));
        }
        arr1[size++] = num;
    }
    int *arr2 = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i] * arr1[i];
    }

    qsort(arr2, size, sizeof(int), icmp);


    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }

    free(arr1);
    free(arr2);

    return 0;
}

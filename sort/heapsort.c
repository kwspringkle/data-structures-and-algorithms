#include <stdio.h>
#include <stdlib.h>

#define HTOP(i) (((i) - 1) >> 1)
#define HLEFT(i) (((i) << 1) + 1)
#define HRIGHT(i) (((i) << 1) + 2)
#define SWAP(a, b) {double tmp = (a); (a) = (b); (b) = tmp;}

void heap_shift_down(long i, long n, double *arr) {
    long smallest = i;
    long l = HLEFT(i);
    long r = HRIGHT(i);
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        SWAP(arr[i], arr[smallest]);
        heap_shift_down(smallest, n, arr);
    }
}

void build_min_heap(long n, double *arr) {
    for (long i = n / 2 - 1; i >= 0; i--) {
        heap_shift_down(i, n, arr);
    }
}

void build_max_heap(long n, double *arr) { //Tìm ra top k có gtri lớn nhất
    for (long i = n / 2 - 1; i >= 0; i--) {
        heap_shift_down(i, n, arr);
    }
}

void heap_sort(long n, double *arr) {
    build_min_heap(n, arr);
    for (long i = n - 1; i > 0; i--) {
        SWAP(arr[0], arr[i]);
        heap_shift_down(0, i, arr);
    }
}

void printTopK(long k, double *arr, long n) {
    heap_sort(n, arr);
    for (long i = n-1; i >= n-k; i--) {
        printf("%.2lf\n", arr[i]);
    }
}

int main() {
    long k;
    long z;
    scanf("%ld %ld", &k, &z);
    double *arr = (double *)malloc(z * sizeof(double));
    for (long i = 0; i < z; i++) {
        scanf("%lf", &arr[i]);
    }

    printTopK(k, arr, z);

    free(arr);
    return 0;
}

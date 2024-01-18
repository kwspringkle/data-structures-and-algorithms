#include <stdio.h>
#include <string.h>

int main() {
    int m;
    scanf("%d", &m);
    int arr1[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    int n;
    scanf("%d", &n);
    int arr2[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    int first = 0;
    int second = 0;
    int arr3[m + n];
    int index = 0; 

 
    while (first < m && second < n) {
        if (arr1[first] < arr2[second]) {
            arr3[index++] = arr1[first++];
        } else {
            arr3[index++] = arr2[second++];
        }
    }


    while (first < m) {
        arr3[index++] = arr1[first++];
    }

    while (second < n) {
        arr3[index++] = arr2[second++];
    }


    for (int i = 0; i < m + n; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}

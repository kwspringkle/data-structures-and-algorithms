#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Narcissistic number
int check(int x) {
    char str[50];
    sprintf(str, "%d", x);

    int len = strlen(str);
    int sum = 0;

    for (int i = 0; i < len; i++) {
        int digit = str[i] - '0'; 
        sum += pow(digit, len);
    }

    return (sum == x);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (check(arr[i])) {
            printf("%d ", arr[i]);
            flag = 1;
        }
    }

    if (flag == 0) {
        printf("NO");
    }

    return 0;
}

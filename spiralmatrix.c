#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void spiralMatrix(int n){
    int arr[n][n];
    int value = 1;
    int top = 0;
    int bottom = n-1;
    int left= 0;
    int right = n-1;
    while(top <= bottom && left <= right){
        for(int i = left; i <= right; i++){
            arr[top][i] = value++;
        }
        top++;
        for(int i = top; i <= bottom; i++){
            arr[i][right] = value++;
        }
        right--;
        for(int i = right; i >=left; i--){
            arr[bottom][i] = value++;
        }
        bottom --;
        for(int i = bottom; i >= top; i--){
            arr[i][left] = value++;
        }
        left++;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    spiralMatrix(n);

    return 0;
}

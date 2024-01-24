#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double find(int * arr, int n, int k){
    int p1 = 0;
    int p2 = k-1;
    double sum = 0;
    double aver = 0;
    double max = 0;
    //First window
    for(int i = p1; i <= p2; i++){
        sum += arr[i];
    }
    aver = sum / k;
    max = aver;
    
    //Sliding
    while(p2 < n-1){
        sum = sum - arr[p1] + arr[p2+1];
        aver = sum / k;
        if(aver > max){
            max = aver;
        }
        p1++;
        p2++;
    }
    return max;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int k;
    scanf("%d", &k);
    printf("%lf", find(arr, n, k));
}

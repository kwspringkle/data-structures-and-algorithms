//Đếm số lần xuất hiện của từ và sắp xếp
#include <stdio.h>
#include <stdlib.h>

typedef struct words{
    char words[20];
    int count;
}word;

int cmp(const void * a, const void * b){
    word * x = (word *)a;
    word * y = (word *)b;
    if(x->count > y-> count) return -1;
    else if(x-> count == y -> count){
        if(x -> words < y -> words ) return -1;
        else return 1;
    }
    else return 1;
}

int main(){
    int k, n;
    scanf("%d %d", &k, &n);
    word * arr = malloc(n * sizeof(word));
    for(int i = 0; i < n; i++){
        scanf("%s %d", arr[i].words, &arr[i].count);
    }
    qsort(arr, n, sizeof(word), cmp);
    for(int i = 0; i < k; i++){
        printf("%s %d\n", arr[i].words, arr[i].count);
    }
    
}

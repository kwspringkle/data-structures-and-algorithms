#include <stdio.h>


void Hanoitower(int n, char a, char b, char c){
    if(n == 1) {
        printf("Move disk from %c to %c\n", a, c);
    } else{
        Hanoitower(n-1, a, c, b);
        Hanoitower(1, a, b, c);
        Hanoitower(n-1, b, a, c);
    }
}


int main(){
    int n; scanf("%d", &n);
    Hanoitower(n, 'A', 'B', 'C');
}

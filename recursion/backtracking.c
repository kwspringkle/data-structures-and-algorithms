//Thuật toán quay lui



/*Tư tưởng: duyệt hết tất cả các trường hợp có thể xảy ra, nếu sai thì quay lại và lam f
lại
Mã giả

Cấu hình cần tìm: X1, X2, ...., Xn

Try (int i ){
for(j = khả năng 1, j <= khả năng M; j++){
   if(chấp nhận khả năng j){
     X[i] = khả năng j;
     if(i == n) Thong báo cấu hình tìm được
     else {
         Try(i+1);
     }
}
}
*/

//Bài toán sinh xâu nhị phân có độ dài n

#include <stdio.h>
#include <stdlib.h>

int X[100]; int n; int k;
void inkqxaunhiphan(){
	for(int i = 0; i < n; i++){
		printf("%d ", X[i] );
	}
	printf("\n");
}



void Try(int i){
	for(int j = 0; j <= 1; j++){
		X[i-1] = j;
		if(i == n) {
			 inkq();
		}
		else Try(i+1);
	}
}

//Bài toán quay lui sinh tổ hợp chập k của n

void inkqtohopchapk(){
	for(int i = 0; i < k; i++){
		printf("%d ", X[i] );
	}
	printf("\n");
}

void Trysinhtohop(int i){
	for(int j = X[i-1] + 1; j <= n - k + i; j++){
		X[i] = j; 
		if( i == k) {
			inkqtohopchapk();
		} else {
			Try(i+1);
		}
    }
}

//Bài toán sinh xâu hoán vị

int m[100];
void inkqsinhhoanvi(){
	for(int i = 1; i <= n; i++){
		printf("%d", X[i]);
	} 
	printf("\n");
}



void Trysinhhoanvi(int i){
	for(int j = 1; j <= n; j++){
		if(m[j] == 0){
			X[i] = j;
			m[j] = 1;
		}
		if(i == n){ 
		inkqsinhhoanvi();
		} else{
			Trysinhhoanvi(i+1);
		}
		m[j] = 0;
	}
	
}

//Bài toán xếp N quân hậu




int main(){
	
	
}

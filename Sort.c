//Các thuật toán sắp xếp

#include <stdio.h>
#include <stdlib.h>
#define SWAP(a, b) {int tmp = (a); (a) = (b); (b) = tmp;}


//Insertion sort: O(n^2)
void insertionsort(int * a, int size){
	//index đi từ 0 đến N-1
	for(int k = 1; k <= size; k++){
		int last = a[k];
		int j = k;
		while(j > 0 && a[j-1] < last){ // giảm dần, nếu tăg dần thì a[j-1] > last			a[j] = a[j-1];
			j--;
		}
		a[j] = last;
	}
}

//Selectionsort
void selectionsort(int * a, int size){ 
//Thứ tự giảm dần, index từ 0 đến size - 1
	for(int k = 0; k < size; k++ ){
		int max = k;
		for(int j = k + 1; j < size; j++){
			if(a[max] < a[j]) max = j;
		}
		SWAP(a[max], a[k]);
	}
}

void selectionsort2(int * a, int size){ 
//Thứ tự tăng dần, index từ 0 đến size - 1
	for(int k = 0; k < size; k++ ){
		int min = k;
		for(int j = k + 1; j < size; j++){
			if(a[min] > a[j]) min = j;
		}
		SWAP(a[min], a[k]);
	}
}

//Bubblesort
void bubblesort(int * a, int size){
	//Đang sắp xếp tăng dần
	int swapped;
	do{
		swapped = 0;
		for(int i = 0; i < size - 1; i++){
			if(a[i] > a[i+1]){
				SWAP(a[i], a[i+1]);
				swapped = 1;
			}
		}
	} while(swapped == 1);
}

void bubblesort2(int * a, int size){
	//Đang sắp xếp giảm dần, index từ 0 đến size - 1
	int swapped;
	do{
		swapped = 0;
		for(int i = 0; i < size - 1; i++){
			if(a[i] < a[i+1]){
				SWAP(a[i], a[i+1]);
				swapped = 1;
			}
		}
	} while(swapped == 1);
}

//Quicksort
//Khi muốn a đứng trước b trong thứ tự sắp xếp thì trả về số âm
//Khi muốn a đứng sau b trong thứ tự sắp xếp thì trả về số dương
int cmp(const void * a, const void * b){
	int * x = (int*)a;
	int * y = (int*)b; //Ép hai con trỏ void theo kiểu dữ liệu mình cần xếp
	if(*x < *y) return -1;
	else return 1;
}

//Sắp xếp theo trị tuyệt đối tăng dần
int abscmp(const void * a, const void * b){
	int * x = (int*)a;
	int * y = (int*)b; //Ép hai con trỏ void theo kiểu dữ liệu mình cần xếp
	if(abs(*x) < abs(*y)) return -1;
	else return 1;
}

//Sắp xếp theo trị tuyệt đối tăng dần. Nếu trị tuyệt đối bằng nhau thì 
//số dương phải đứng sau
int abs_cmp(const void * a, const void * b){
	int * x = (int*)a;
	int * y = (int*)b; //Ép hai con trỏ void theo kiểu dữ liệu mình cần xếp
	if(abs(*x) != (abs(*y))) return abs(*x) - abs(*y);
	if(*x > 0) return 1;
	return -1;
}

//Tổng các chữ số tăng dần
int sumdigit(int n){
	int res = 0;
	while(n){
		res += n%10;
		n /= 10;
	}
	return res;
}

int icmp(const void * a, const void * b){
	int * x = (int *)a;
	int * y = (int *)b;
	if(sumdigit(*x) != sumdigit(*y)) return sumdigit(*x) - sumdigit(*y);
	return *y - *x;
} //Nếu tổng chữ số bằng nhau thì số có giá trị nhỏ hơn xếp sau








int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), cmp);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}




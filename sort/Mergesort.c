//Merge sort
/*Merge sort dựa trên giải thuật chia để trị, độ phức tạp xấu nhất 
là O(nlogn) --> thuật toán này ổn định mà thời gian chạy khá nhanh

Ý tưởng: chia mảng thành hai nửa rồi kết hợp lại với nhau

mergeSort(a[], l,  r)
if r > l
     1. Tìm chỉ số nằm giữa mảng để chia mảng thành 2 nửa:
             middle m = (l+r)/2
     2. Gọi đệ quy hàm mergeSort cho nửa đầu tiên:  
             mergeSort(a, l, m)
     3. Gọi đệ quy hàm mergeSort cho nửa thứ hai:
             mergeSort(a, m+1, r)
     4. Gộp 2 nửa mảng đã sắp xếp ở (2) và (3):
             merge(a, l, m, r)
             
*/


#include <stdio.h>
#include <stdlib.h>

// Hàm merge để kết hợp hai mảng con của arr[].
// Mảng con thứ nhất là arr[l..m]
// Mảng con thứ hai là arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Tạo các mảng tạm thời
    int L[n1], R[n2];

    // Copy dữ liệu vào mảng tạm thời L[] và R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge các mảng tạm thời vào mảng chính arr[l..r]
    i = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ nhất
    j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    k = l; // Khởi tạo chỉ số bắt đầu của mảng đã được kết hợp
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { //Đổi lại >= nếu muốn sx tăng dần
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[], nếu có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[], nếu có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm sắp xếp mảng arr[l..r] bằng Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Tìm điểm giữa mảng
        int m = l + (r - l) / 2;

        // Gọi đệ quy để sắp xếp hai nửa mảng
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Kết hợp các nửa mảng đã sắp xếp
        merge(arr, l, m, r);
    }
}

// Hàm in mảng
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Hàm main để kiểm thử
int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
    int a_size = sizeof(a) / sizeof(a[0]);
    mergeSort(a, 0, a_size - 1);
    printArray(a, a_size);
    return 0;
}



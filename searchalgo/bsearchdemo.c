#include <stdio.h>

int search(int arr[], int x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == x)
      return mid;
    if (arr[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main(void) {
  int arr[] = {4, 6, 8, 11, 13, 15};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 6;
  int kq = search(arr, x, 0, n - 1);
  if (kq == -1)
    printf("Không tìm thấy");
  else
    printf("Phần tử cần tìm nằm ở vị trí %d", kq);
  return 0;
}

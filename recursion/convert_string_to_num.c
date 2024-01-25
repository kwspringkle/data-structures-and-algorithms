#include <string.h>
#include <stdio.h>

int main(){
    char str[MAX];
    fgets(str, MAX, stdin);

    // Loại bỏ ký tự newline từ chuỗi
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    int n = strlen(str);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != ' ') {
            count++;
        }
    }

    int arr[count];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != ' ') {
            // Sử dụng sscanf để chuyển đổi chuỗi thành số nguyên
            sscanf(&str[i], "%d", &arr[j]);
            j++;
        }
    }
}

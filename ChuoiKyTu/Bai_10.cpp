// Bài tập 10: Nối chuỗi với điều kiện
// Đề bài:
// Viết chương trình nhận vào một danh sách các chuỗi và một ký tự phân cách, sau đó nối tất cả
// các chuỗi không rỗng trong danh sách bằng ký tự phân cách đó.
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char arr[20][100]; // tối đa 20 chuỗi, mỗi chuỗi tối đa 99 ký tự
    char sep;
    char result[2048] = "";
    printf("Nhap so luong chuoi: ");
    scanf("%d", &n);
    getchar(); // Đọc bỏ ký tự '\n' sau số

    for (int i = 0; i < n; i++) {
        printf("Nhap chuoi thu %d: ", i + 1);
        fgets(arr[i], sizeof(arr[i]), stdin);
        arr[i][strcspn(arr[i], "\n")] = 0; // Xóa ký tự xuống dòng
    }

    printf("Nhap ky tu phan cach: ");
    scanf("%c", &sep);

    int first = 1;
    for (int i = 0; i < n; i++) {
        if (strlen(arr[i]) > 0) {
            if (!first)
                strncat(result, &sep, 1);
            strcat(result, arr[i]);
            first = 0;
        }
    }

    printf("Chuoi ket qua: %s\n", result);
    return 0;
}
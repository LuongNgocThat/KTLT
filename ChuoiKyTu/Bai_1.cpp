// Bài tập 1: Đếm ký tự trong chuỗi
// Đề bài:
// Viết chương trình nhập vào một chuỗi ký tự và một ký tự cần đếm, sau đó trả về số lần xuất hiện 
// của ký tự đó trong chuỗi (phân biệt chữ hoa/thường).
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];        // Chuỗi nhập vào
    char c;              // Ký tự cần đếm
    int count = 0;       // Biến đếm

    // Nhập chuỗi
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    
    // Loại bỏ ký tự newline nếu có
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    // Nhập ký tự cần đếm
    printf("Nhap ky tu can dem: ");
    scanf(" %c", &c);  // Dấu cách trước %c để bỏ qua ký tự newline còn lại

    // Duyệt chuỗi và đếm
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            count++;
        }
    }

    // Xuất kết quả
    printf("So lan xuat hien cua '%c' la: %d\n", c, count);

    return 0;
}

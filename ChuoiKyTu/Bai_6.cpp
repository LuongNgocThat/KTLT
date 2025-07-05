// ài tập 6: Tìm chuỗi con
// Đề bài:
// Viết chương trình kiểm tra xem một chuỗi con có tồn tại trong chuỗi chính hay không. Trả về vị
// trí đầu tiên tìm thấy (bắt đầu từ 0) hoặc -1 nếu không tìm thấy.
#include <stdio.h>
#include <string.h>

int findSubstring(const char *str, const char *substr) {
    char *pos = strstr(str, substr);
    if (pos == NULL)
        return -1;
    return (int)(pos - str);
}

int main() {
    char str[256], substr[256];
    printf("Nhap chuoi chinh: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    printf("Nhap chuoi con: ");
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = 0;

    int index = findSubstring(str, substr);
    if (index == -1)
        printf("Khong tim thay chuoi con trong chuoi chinh.\n");
    else
        printf("Chuoi con xuat hien dau tien o vi tri: %d\n", index);

    return 0;
}
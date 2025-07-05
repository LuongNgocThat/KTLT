// Bài tập 7: Thay thế ký tự
// Đề bài:
// Viết chương trình thay thế tất cả các lần xuất hiện của một ký tự cũ bằng một ký tự mới trong 
// chuỗi
#include <stdio.h>
#include <string.h>

int main() {
    char s[256], oldChar, newChar;
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // Xóa ký tự xuống dòng

    printf("Nhap ky tu can thay the: ");
    scanf("%c", &oldChar);
    getchar(); // Đọc bỏ ký tự '\n' còn lại

    printf("Nhap ky tu moi: ");
    scanf("%c", &newChar);

    for (int i = 0; s[i]; i++) {
        if (s[i] == oldChar)
            s[i] = newChar;
    }

    printf("Chuoi sau khi thay the: %s\n", s);
    return 0;
}
// ài tập 4: Chuyển đổi chữ hoa/thường
// Đề bài:
// Viết chương trình chuyển đổi tất cả chữ hoa thành chữ thường và ngược lại trong một chuỗi. Các 
// ký tự khác giữ nguyên
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[256];
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // Xóa ký tự xuống dòng

    for (int i = 0; s[i]; i++) {
        if (islower(s[i]))
            s[i] = toupper(s[i]);
        else if (isupper(s[i]))
            s[i] = tolower(s[i]);
        // Ký tự khác giữ nguyên
    }

    printf("Chuoi sau khi chuyen doi: %s\n", s);
    return 0;
}
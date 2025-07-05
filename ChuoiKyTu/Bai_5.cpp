// Bài tập 5: Loại bỏ khoảng trắng thừa
// Đề bài:
// Viết chương trình loại bỏ tất cả khoảng trắng thừa trong chuỗi, chỉ giữ lại một khoảng trắng giữa 
// các từ và loại bỏ khoảng trắng ở đầu/cuối chuỗi
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeExtraSpaces(char *s) {
    int i = 0, j = 0, len = strlen(s);
    // Bỏ khoảng trắng đầu
    while (isspace(s[i])) i++;
    int space = 0;
    while (s[i]) {
        if (!isspace(s[i])) {
            s[j++] = s[i++];
            space = 0;
        } else {
            if (!space) s[j++] = ' ';
            space = 1;
            i++;
        }
    }
    // Bỏ khoảng trắng cuối
    if (j > 0 && s[j-1] == ' ') j--;
    s[j] = '\0';
}

int main() {
    char s[256];
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // Xóa ký tự xuống dòng

    removeExtraSpaces(s);

    printf("Chuoi sau khi loai bo khoang trang thua: \"%s\"\n", s);
    return 0;
}
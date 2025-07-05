// Bài tập 9: Đảo ngược từng từ
// Đề bài:
// Viết chương trình đảo ngược từng từ trong chuỗi nhưng giữ nguyên thứ tự các từ.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm đảo ngược một đoạn chuỗi từ vị trí l đến r
void reverse(char *s, int l, int r) {
    while (l < r) {
        char t = s[l];
        s[l] = s[r];
        s[r] = t;
        l++;
        r--;
    }
}

int main() {
    char s[256];
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;

    int i = 0, len = strlen(s);
    while (i < len) {
        // Bỏ qua khoảng trắng
        while (i < len && isspace(s[i])) i++;
        int start = i;
        // Tìm hết từ
        while (i < len && !isspace(s[i])) i++;
        int end = i - 1;
        if (start < len)
            reverse(s, start, end);
    }

    printf("Chuoi sau khi dao nguoc tung tu: %s\n", s);
    return 0;
}
// Đề bài:
// Viết chương trình đếm số từ trong một chuỗi. Các từ được phân cách bởi khoảng trắng. Bỏ qua 
// các khoảng trắng thừa ở đầu, cuối và giữa các từ

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countWords(const char *s) {
    int count = 0;
    int inWord = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (!isspace(s[i])) { // Nếu không phải khoảng trắng
            if (!inWord) {    // Bắt đầu một từ mới
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0; // Ra khỏi từ khi gặp khoảng trắng
        }
    }

    return count;
}

int main() {
    char s[1000];

    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);

    // Loại bỏ ký tự newline nếu có
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    int wordCount = countWords(s);
    printf("So tu trong chuoi la: %d\n", wordCount);

    return 0;
}

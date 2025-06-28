// Bài 2: Viết hàm upper(char s[]) đổi toàn bộ các 
// ký tự sang ký tự hoa (giống hàm strupr)
// ❖Bài 3: Viết hàm lower(char s[]) đổi toàn bộ các 
// ký tự sang ký tự thường (giống hàm strlwr)
// ❖Bài 4: Viết hàm proper(char s[]) đổi các ký tự 
// đầu tiên của mỗi từ sang ký tự hoa.
// Bài 5: Viết hàm standard(char s[]) bỏ toàn bộ 
// khoảng trắng đầu chuỗi, cuối chuỗi và giữa 2 từ 
// trong s chỉ còn 1 khoảng trắng.
// ❖Bài 6: Xóa tất cả các khoảng trắng của s
// ❖Bài 7: Đếm xem có bao nhiêu từ trong s. Xuất 
// các từ trên các dòng liên tiếp.
// ❖Bài 8: Tìm từ có chiều dài dài nhất và in ra.
// ❖Bài 9: Trích ra n ký tự đầu tiên/cuối cùng/bắt đầu 
// tại vị trí pos
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Bài 2: Đổi toàn bộ ký tự sang ký tự hoa
void upper(char s[]) {
    for (int i = 0; s[i]; i++)
        s[i] = toupper(s[i]);
}

// Bài 3: Đổi toàn bộ ký tự sang ký tự thường
void lower(char s[]) {
    for (int i = 0; s[i]; i++)
        s[i] = tolower(s[i]);
}

// Bài 4: Đổi ký tự đầu mỗi từ sang hoa
void proper(char s[]) {
    int newWord = 1;
    for (int i = 0; s[i]; i++) {
        if (isspace(s[i]))
            newWord = 1;
        else if (newWord) {
            s[i] = toupper(s[i]);
            newWord = 0;
        } else {
            s[i] = tolower(s[i]);
        }
    }
}

// Bài 5: Chuẩn hóa chuỗi (bỏ khoảng trắng đầu/cuối, giữa 2 từ chỉ còn 1 khoảng trắng)
void standard(char s[]) {
    int i = 0, j = 0, len = strlen(s);
    // Bỏ khoảng trắng đầu
    while (isspace(s[i])) i++;
    // Xử lý giữa và cuối
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

// Bài 6: Xóa tất cả khoảng trắng
void removeSpaces(char s[]) {
    int j = 0;
    for (int i = 0; s[i]; i++)
        if (!isspace(s[i]))
            s[j++] = s[i];
    s[j] = '\0';
}

// Bài 7: Đếm số từ và xuất từng từ trên 1 dòng
int countWords(char s[]) {
    int count = 0, inWord = 0;
    for (int i = 0; s[i]; i++) {
        if (!isspace(s[i]) && !inWord) {
            count++;
            inWord = 1;
        } else if (isspace(s[i])) {
            inWord = 0;
        }
    }
    return count;
}
void printWords(char s[]) {
    int i = 0;
    while (s[i]) {
        while (s[i] && isspace(s[i])) i++;
        if (!s[i]) break;
        while (s[i] && !isspace(s[i])) putchar(s[i++]);
        putchar('\n');
    }
}

// Bài 8: Tìm từ dài nhất và in ra
void longestWord(char s[]) {
    int maxLen = 0, len = 0, start = 0, maxStart = 0, i = 0;
    while (s[i]) {
        while (s[i] && isspace(s[i])) i++;
        start = i;
        len = 0;
        while (s[i] && !isspace(s[i])) { len++; i++; }
        if (len > maxLen) {
            maxLen = len;
            maxStart = start;
        }
    }
    printf("Tu dai nhat: ");
    for (int j = 0; j < maxLen; j++)
        putchar(s[maxStart + j]);
    printf("\n");
}

// Bài 9: Trích n ký tự đầu/cuối/bắt đầu tại pos
void substr_head(char s[], int n, char out[]) {
    strncpy(out, s, n);
    out[n] = '\0';
}
void substr_tail(char s[], int n, char out[]) {
    int len = strlen(s);
    if (n > len) n = len;
    strncpy(out, s + len - n, n);
    out[n] = '\0';
}
void substr_pos(char s[], int pos, int n, char out[]) {
    int len = strlen(s);
    if (pos < 0) pos = 0;
    if (pos + n > len) n = len - pos;
    strncpy(out, s + pos, n);
    out[n] = '\0';
}

// Ví dụ sử dụng
int main() {
    char s[100], out[100];
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;

    upper(s); printf("Upper: %s\n", s);
    lower(s); printf("Lower: %s\n", s);
    proper(s); printf("Proper: %s\n", s);

    strcpy(out, s);
    standard(out); printf("Standard: %s\n", out);

    strcpy(out, s);
    removeSpaces(out); printf("Remove spaces: %s\n", out);

    strcpy(out, s);
    printf("So tu: %d\n", countWords(out));
    printf("Cac tu tren tung dong:\n");
    printWords(out);

    strcpy(out, s);
    longestWord(out);

    substr_head(s, 5, out); printf("5 ky tu dau: %s\n", out);
    substr_tail(s, 5, out); printf("5 ky tu cuoi: %s\n", out);
    substr_pos(s, 2, 4, out); printf("4 ky tu tu vi tri 2: %s\n", out);

    return 0;
}
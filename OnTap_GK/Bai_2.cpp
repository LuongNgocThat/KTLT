// Bài tập 2: Chuẩn hóa chuỗi
// Mô tả hàm: Viết hàm void normalizeString(char *s) chuẩn hóa một chuỗi theo quy tắc: loại bỏ khoảng trắng thừa 
// ở đầu và cuối chuỗi, đồng thời chỉ giữ một khoảng trắng giữa các từ.
// Đầu vào:
// •	Chuỗi s, 0 < length(s) <= 255.
// Minh họa:
// •	Đầu vào: "  "
// •	Đầu ra: "hello world example"
// Giải thích: Loại bỏ khoảng trắng thừa ở đầu và cuối chuỗi, đồng thời chuyển nhiều khoảng trắng liên tiếp giữa 
// các từ thành một khoảng trắng duy nhất.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void normalizeString(char *s) {
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
    s[strcspn(s, "\n")] = 0; // Xóa ký tự xuống dòng nếu có
    normalizeString(s);
    printf("Chuoi sau khi chuan hoa: \"%s\"\n", s);
    return 0;
}
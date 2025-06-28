// Bài tập 3: Tìm và thay thế chuỗi con
// Yêu cầu: Viết một hàm để tìm và thay thế tất cả các lần xuất hiện của một chuỗi con trong chuỗi chính với một chuỗi thay thế.
// Prototype: void ReplaceSubstring(char *original, const char *find, const char *replace);
// Đầu vào:
// •	original: Chuỗi gốc cần xử lý
// •	find: Chuỗi con cần tìm và thay thế
// •	replace: Chuỗi thay thế
// Minh họa:
// •	Đầu vào: original = "Hello world, hello friends", find = "hello", replace = "hi"
// •	Đầu ra: original = "Hello world, hi friends"
#include <stdio.h>
#include <string.h>

// Hàm thay thế tất cả các lần xuất hiện của chuỗi con 'find' trong 'original' bằng 'replace'
void ReplaceSubstring(char *original, const char *find, const char *replace) {
    char buffer[1024];
    char *pos, *lastPos = original;
    int findLen = strlen(find);
    int replaceLen = strlen(replace);
    buffer[0] = '\0';

    while ((pos = strstr(lastPos, find)) != NULL) {
        // Sao chép phần trước chuỗi con tìm thấy
        strncat(buffer, lastPos, pos - lastPos);
        // Thêm chuỗi thay thế
        strcat(buffer, replace);
        // Di chuyển vị trí tiếp theo
        lastPos = pos + findLen;
    }
    // Thêm phần còn lại của chuỗi
    strcat(buffer, lastPos);
    // Sao chép kết quả trở lại original
    strcpy(original, buffer);
}

int main() {
    char original[1024], find[100], replace[100];
    printf("Nhap chuoi goc: ");
    fgets(original, sizeof(original), stdin);
    original[strcspn(original, "\n")] = 0;

    printf("Nhap chuoi can tim: ");
    fgets(find, sizeof(find), stdin);
    find[strcspn(find, "\n")] = 0;

    printf("Nhap chuoi thay the: ");
    fgets(replace, sizeof(replace), stdin);
    replace[strcspn(replace, "\n")] = 0;

    ReplaceSubstring(original, find, replace);
    printf("Chuoi sau khi thay the: %s\n", original);
    return 0;
}
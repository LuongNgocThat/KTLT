// ài tập 8: Kiểm tra loại chuỗi
// Đề bài:
// Viết chương trình kiểm tra một chuỗi thuộc loại nào: chỉ chứa chữ số, chỉ chứa chữ cái, chỉ chứa 
// chữ cái và số, hoặc chứa ký tự đặc biệt
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[256];
    int hasDigit = 0, hasAlpha = 0, hasOther = 0;
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;

    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i]))
            hasDigit = 1;
        else if (isalpha(s[i]))
            hasAlpha = 1;
        else
            hasOther = 1;
    }

    if (hasOther)
        printf("Chuoi chua ky tu dac biet.\n");
    else if (hasAlpha && hasDigit)
        printf("Chuoi chi chua chu cai va so.\n");
    else if (hasAlpha)
        printf("Chuoi chi chua chu cai.\n");
    else if (hasDigit)
        printf("Chuoi chi chua chu so.\n");
    else
        printf("Chuoi rong hoac khong xac dinh.\n");

    return 0;
}
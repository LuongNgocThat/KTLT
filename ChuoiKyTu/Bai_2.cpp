// Đề bài:
// Viết chương trình kiểm tra xem một chuỗi có phải là palindrome hay không. Palindrome là chuỗi 
// đọc từ trái sang phải và từ phải sang trái đều giống nhau. Bỏ qua khoảng trắng và không phân 
// biệt chữ hoa/thường.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(const char *s) {
    int left = 0, right = strlen(s) - 1;
    while (left < right) {
        // Bỏ qua khoảng trắng
        while (left < right && isspace(s[left])) left++;
        while (left < right && isspace(s[right])) right--;
        // So sánh không phân biệt hoa/thường
        if (tolower(s[left]) != tolower(s[right]))
            return 0;
        left++;
        right--;
    }
    return 1;
}

int main() {
    char s[256];
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // Xóa ký tự xuống dòng

    if (isPalindrome(s))
        printf("Chuoi la palindrome.\n");
    else
        printf("Chuoi khong la palindrome.\n");
    return 0;
}
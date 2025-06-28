// Bai5
// a. Viết hàm đổi một ký tự hoa sang ký tự thường.
// b. Viết thủ tục giải phương trình bậc nhất.
// c. Viết thủ tục giải phương trình bậc hai.
// d. Viết hàm trả về giá trị nhỏ nhất của 4 số nguyên. 
// e. Viết thủ tục hoán vị hai số nguyên.
// f. Viết thủ tục sắp xếp 4 số nguyên tăng dần
#include <stdio.h>
#include <ctype.h>
#include <math.h>

// a. Hàm đổi ký tự hoa sang ký tự thường
char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

// b. Thủ tục giải phương trình bậc nhất ax + b = 0
void giaiPTBacNhat(float a, float b) {
    if (a == 0) {
        if (b == 0)
            printf("Phuong trinh vo so nghiem\n");
        else
            printf("Phuong trinh vo nghiem\n");
    } else {
        printf("Nghiem x = %.2f\n", -b / a);
    }
}

// c. Thủ tục giải phương trình bậc hai ax^2 + bx + c = 0
void giaiPTBacHai(float a, float b, float c) {
    if (a == 0) {
        giaiPTBacNhat(b, c);
        return;
    }
    float delta = b * b - 4 * a * c;
    if (delta < 0)
        printf("Phuong trinh vo nghiem\n");
    else if (delta == 0)
        printf("Phuong trinh co nghiem kep x = %.2f\n", -b / (2 * a));
    else {
        float x1 = (-b + sqrt(delta)) / (2 * a);
        float x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Phuong trinh co 2 nghiem: x1 = %.2f, x2 = %.2f\n", x1, x2);
    }
}

// d. Hàm trả về giá trị nhỏ nhất của 4 số nguyên
int min4(int a, int b, int c, int d) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    return min;
}

// e. Thủ tục hoán vị hai số nguyên
void hoanVi(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// f. Thủ tục sắp xếp 4 số nguyên tăng dần
void sapXep4TangDan(int *a, int *b, int *c, int *d) {
    if (*a > *b) hoanVi(a, b);
    if (*a > *c) hoanVi(a, c);
    if (*a > *d) hoanVi(a, d);
    if (*b > *c) hoanVi(b, c);
    if (*b > *d) hoanVi(b, d);
    if (*c > *d) hoanVi(c, d);
}

// Ví dụ sử dụng các hàm/thủ tục trên
int main() {
    // a
    char ch = 'G';
    printf("'%c' -> '%c'\n", ch, toLowerChar(ch));

    // b
    printf("Giai PT bac nhat 2x + 4 = 0:\n");
    giaiPTBacNhat(2, 4);

    // c
    printf("Giai PT bac hai x^2 + 2x + 1 = 0:\n");
    giaiPTBacHai(1, 2, 1);

    // d
    printf("Min cua 4 so (5, 2, 8, 3): %d\n", min4(5, 2, 8, 3));

    // e + f
    int x = 7, y = 2, z = 9, t = 4;
    sapXep4TangDan(&x, &y, &z, &t);
    printf("4 so sau khi sap xep tang dan: %d %d %d %d\n", x, y, z, t);

    return 0;
}
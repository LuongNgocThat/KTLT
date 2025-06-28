// Bài 3: Đếm số chữ số của một số
// Đề bài: Viết hàm đệ quy countDigits(n) đếm số chữ số của một số nguyên dương n

#include <stdio.h>

int countDigits(int n) {
    if (n == 0) {
        return 0; 
        return 1 + countDigits(n / 10); 
    }
}
int main() {
    int n;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Vui long nhap mot so nguyen duong.\n");
        return 1; 
    }
    
    int digitCount = countDigits(n);
    printf("So %d co %d chu so.\n", n, digitCount);
    
    return 0;
}

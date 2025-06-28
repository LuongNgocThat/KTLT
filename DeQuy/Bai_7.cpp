// Bài 7: Tính tổng các chữ số
// Đề bài: Viết hàm đệ quy sumDigits(n) tính tổng các chữ số của một số nguyên dương n
#include <stdio.h>
int sumDigits(int n) {
    if (n == 0) {
        return 0; 
    } else {
        return (n % 10) + sumDigits(n / 10); 
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
    
    int sum = sumDigits(n);
    printf("Tong cac chu so cua %d la: %d\n", n, sum);
    
    return 0;
}
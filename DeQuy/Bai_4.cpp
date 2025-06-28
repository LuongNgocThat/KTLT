// Bài 4: Tìm chữ số lớn nhất trong một số
// Đề bài: Viết hàm đệ quy maxDigit(n) tìm chữ số lớn nhất trong một số nguyên dương n
#include <stdio.h>
int maxDigit(int n) {
    if (n == 0) {
        return 0; 
    } else {
        int lastDigit = n % 10; 
        int maxOfRest = maxDigit(n / 10); 
        return (lastDigit > maxOfRest) ? lastDigit : maxOfRest; 
    }
}
int main() {
    int n;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);
    
    int max = maxDigit(n);
    printf("Chu so lon nhat trong %d la: %d\n", n, max);
    
    return 0;
}
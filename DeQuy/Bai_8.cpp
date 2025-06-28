// Bài 8: Bài toán tăng trưởng dân số
// Đề bài: Dân số ban đầu P người, mỗi năm tăng r%. Viết hàm đệ quy population(P, r, n) tính dân 
// số sau n năm
#include <stdio.h>
double population(double P, double r, int n) {
    if (n == 0) {
        return P; 
    }
    return population(P * (1 + r / 100), r, n - 1); 
}
int main() {
    double P, r;
    int n;
    
    printf("Nhap dan so ban dau P: ");
    scanf("%lf", &P);
    
    printf("Nhap ty le tang truong r (%%): ");
    scanf("%lf", &r);
    
    printf("Nhap so nam n: ");
    scanf("%d", &n);
    
    double result = population(P, r, n);
    printf("Dan so sau %d nam la: %.2lf\n", n, result);
    
    return 0;
}
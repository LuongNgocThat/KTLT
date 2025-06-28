// Bài 6: Bài toán khấu hao tài sản
// Đề bài: Máy móc trị giá V đồng, mỗi năm bị khấu hao k% giá trị. Viết hàm đệ quy 
// depreciation(V, k, n) tính giá trị còn lại sau n năm.
#include <stdio.h>
double depreciation(double V, double k, int n) {
    if (n == 0)
        return V; 
    return depreciation(V * (1 - k / 100), k, n - 1); 
}
int main() {
    double V, k;
    int n;
    printf("Nhap gia tri tai san (dong): ");
    scanf("%lf", &V);
    printf("Nhap ti le khau hao (%%/nam): ");
    scanf("%lf", &k);
    printf("Nhap so nam su dung: ");
    scanf("%d", &n);
    
    double remainingValue = depreciation(V, k, n);
    printf("Gia tri con lai sau %d nam la: %.2lf dong\n", n, remainingValue);
    
    return 0;
}
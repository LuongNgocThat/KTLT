// Bài 5: Tính lãi kép ngân hàng
// Đề bài: Gửi tiết kiệm số tiền P đồng với lãi suất r% mỗi năm (lãi kép). Viết hàm đệ quy 
// compound(P, r, n) tính số tiền có được sau n năm.

#include <stdio.h>
long compound(long P, double r, int n) {
    if (n == 0)
        return P; 
    return compound(P, r, n - 1) * (1 + r / 100); 
}

int main() {
    long P;
    double r;
    int n;
    printf("Nhap so tien gui (dong): ");
    scanf("%ld", &P);
    printf("Nhap lai suat (%%/nam): ");
    scanf("%lf", &r);
    printf("Nhap so nam gui: ");
    scanf("%d", &n);
    printf("So tien sau %d nam la: %ld\n", n, compound(P, r, n));
    return 0;
}
// Bài 9: Tính số cách leo cầu thang
// Đề bài: Cầu thang n bậc, mỗi lần có thể leo 1, 2 hoặc 3 bậc. Viết hàm đệ quy climbStairs(n) tính 
// số cách khác nhau để leo hết cầu thang.
#include <stdio.h>
int climbStairs(int n) {
    if (n < 0) {
        return 0; 
    }
    if (n == 0) {
        return 1; 
    }
    return climbStairs(n - 1) + climbStairs(n - 2) + climbStairs(n - 3);
}
int main() {
    int n;
    printf("Nhap so bac cua cau thang: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("So bac phai la mot so nguyen duong.\n");
        return 1; 
    }
    
    int ways = climbStairs(n);
    printf("So cach leo cau thang %d bac la: %d\n", n, ways);
    
    return 0;
}
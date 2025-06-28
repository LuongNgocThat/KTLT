// bài 10: Bài toán phân bổ ngân sách tối ưu
// Đề bài: Ngân sách N triệu đồng đầu tư vào các dự án. Mỗi dự án cần 1-3 triệu. Lợi nhuận từ dự
// án x triệu là x² triệu. Viết hàm đệ quy maxProfit(N) tính lợi nhuận tối đa
#include <stdio.h>
int maxProfit(int N) {
    if (N <= 0) {
        return 0; 
    }
    int max_profit = 0;
    for (int i = 1; i <= 3 && i <= N; i++) {
        int profit = i * i + maxProfit(N - i); 
        if (profit > max_profit) {
            max_profit = profit;
        }
    }
    
    return max_profit;
}
int main() {
    int N;
    printf("Nhap ngan sach N (trieu dong): ");
    scanf("%d", &N);
    
    if (N < 0) {
        printf("Ngan sach phai la mot so nguyen duong.\n");
        return 1; 
    }
    
    int profit = maxProfit(N);
    printf("Loi nhuan toi da tu ngan sach %d trieu dong la: %d trieu dong\n", N, profit);
    
    return 0;
}
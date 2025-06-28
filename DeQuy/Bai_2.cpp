
// Bài 2: Tính tiền taxi theo quãng đường
// Đề bài: Công ty taxi có bảng giá: km đầu tiên 15.000 đồng, từ km thứ 2 trở đi mỗi km 12.000 
// đồng. Viết hàm đệ quy calculateTaxiFare(km) tính tổng tiền taxi khi đi km quãng đường

#include <stdio.h>
int calculateTaxiFare(int km) {
    if (km <= 0) {
        return 0; 
    } else if (km == 1) {
        return 15000; 
    } else {
        return 15000 + (km - 1) * 12000; 
    }
}
int main() {
    int km;
    printf("Nhap quang duong di taxi (km): ");
    scanf("%d", &km);
    
    int fare = calculateTaxiFare(km);
    printf("Tong tien taxi cho %d km la: %d dong\n", km, fare);
    
    return 0;
}

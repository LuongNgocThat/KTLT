// ài tập 3: Quản lý Hình chữ nhật
// Đề bài: Tạo chương trình quản lý hình chữ nhật:
// • Struct HinhChuNhat có chiều dài và chiều rộng
// • Nhập thông tin nhiều hình chữ nhật
// • Tính chu vi, diện tích cho từng hình
// • So sánh các hình để tìm hình có diện tích lớn nhất
// • Hiển thị thống kê tổng hợp
#include <stdio.h>

typedef struct {
    float dai, rong;
} HinhChuNhat;

float chuVi(HinhChuNhat h) {
    return 2 * (h.dai + h.rong);
}

float dienTich(HinhChuNhat h) {
    return h.dai * h.rong;
}

int main() {
    int n;
    printf("Nhap so luong hinh chu nhat: ");
    scanf("%d", &n);
    HinhChuNhat ds[100];
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin hinh thu %d:\n", i + 1);
        printf("Chieu dai: ");
        scanf("%f", &ds[i].dai);
        printf("Chieu rong: ");
        scanf("%f", &ds[i].rong);
    }

    printf("\n%-5s %-10s %-10s %-10s %-10s\n", "STT", "Dai", "Rong", "Chu vi", "Dien tich");
    float maxDT = 0;
    int idxMax = 0;
    float tongDT = 0, tongCV = 0;
    for (int i = 0; i < n; i++) {
        float cv = chuVi(ds[i]);
        float dt = dienTich(ds[i]);
        printf("%-5d %-10.2f %-10.2f %-10.2f %-10.2f\n", i + 1, ds[i].dai, ds[i].rong, cv, dt);
        if (dt > maxDT) {
            maxDT = dt;
            idxMax = i;
        }
        tongDT += dt;
        tongCV += cv;
    }

    printf("\nHinh co dien tich lon nhat: Hinh thu %d (Dai=%.2f, Rong=%.2f, Dien tich=%.2f)\n",
           idxMax + 1, ds[idxMax].dai, ds[idxMax].rong, maxDT);
    printf("Tong chu vi cac hinh: %.2f\n", tongCV);
    printf("Tong dien tich cac hinh: %.2f\n", tongDT);

    return 0;
}
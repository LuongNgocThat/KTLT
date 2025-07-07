// Bài tập 6: Xử lý Ngày tháng
// Đề bài: Viết chương trình xử lý ngày tháng:
// • Struct NgayThang có ngày, tháng, năm
// • Kiểm tra tính hợp lệ của ngày (xử lý năm nhuận)
// • So sánh 2 ngày, tính khoảng cách giữa 2 ngày
// • Tính ngày trong tuần và các thông tin lịch khá

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int ngay, thang, nam;
} NgayThang;

// Kiểm tra năm nhuận
int laNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

// Số ngày trong tháng
int soNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 2: return laNamNhuan(nam) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

// Kiểm tra ngày hợp lệ
int ngayHopLe(NgayThang d) {
    if (d.nam < 1 || d.thang < 1 || d.thang > 12 || d.ngay < 1)
        return 0;
    if (d.ngay > soNgayTrongThang(d.thang, d.nam))
        return 0;
    return 1;
}

// So sánh 2 ngày: trả về -1 nếu d1 < d2, 0 nếu bằng, 1 nếu d1 > d2
int soSanhNgay(NgayThang d1, NgayThang d2) {
    if (d1.nam != d2.nam)
        return d1.nam < d2.nam ? -1 : 1;
    if (d1.thang != d2.thang)
        return d1.thang < d2.thang ? -1 : 1;
    if (d1.ngay != d2.ngay)
        return d1.ngay < d2.ngay ? -1 : 1;
    return 0;
}

// Đổi ngày/tháng/năm thành số ngày từ 01/01/0001
long demNgay(NgayThang d) {
    long tong = d.ngay;
    for (int y = 1; y < d.nam; y++)
        tong += laNamNhuan(y) ? 366 : 365;
    for (int m = 1; m < d.thang; m++)
        tong += soNgayTrongThang(m, d.nam);
    return tong;
}

// Khoảng cách giữa 2 ngày
long khoangCach(NgayThang d1, NgayThang d2) {
    return labs(demNgay(d1) - demNgay(d2));
}

// Tính ngày trong tuần (0: Chủ nhật, 1: Thứ 2, ..., 6: Thứ 7)
int ngayTrongTuan(NgayThang d) {
    int y = d.nam, m = d.thang;
    if (m < 3) {
        m += 12;
        y--;
    }
    int k = y % 100;
    int j = y / 100;
    int h = (d.ngay + 13*(m+1)/5 + k + k/4 + j/4 + 5*j) % 7;
    // Zeller: 0=Saturday, 1=Sunday, ..., 6=Friday
    // Đổi về: 0=Chủ nhật, 1=Thứ 2, ..., 6=Thứ 7
    return (h + 6) % 7;
}

const char* tenThu(int thu) {
    const char* arr[] = {"Chu nhat", "Thu 2", "Thu 3", "Thu 4", "Thu 5", "Thu 6", "Thu 7"};
    return arr[thu];
}

int main() {
    NgayThang d1, d2;
    printf("Nhap ngay 1 (ngay thang nam): ");
    scanf("%d%d%d", &d1.ngay, &d1.thang, &d1.nam);
    printf("Nhap ngay 2 (ngay thang nam): ");
    scanf("%d%d%d", &d2.ngay, &d2.thang, &d2.nam);

    if (!ngayHopLe(d1) || !ngayHopLe(d2)) {
        printf("Mot trong hai ngay khong hop le!\n");
        return 1;
    }

    printf("Ngay 1 la: %02d/%02d/%04d - %s\n", d1.ngay, d1.thang, d1.nam, tenThu(ngayTrongTuan(d1)));
    printf("Ngay 2 la: %02d/%02d/%04d - %s\n", d2.ngay, d2.thang, d2.nam, tenThu(ngayTrongTuan(d2)));

    int cmp = soSanhNgay(d1, d2);
    if (cmp == 0)
        printf("Hai ngay trung nhau.\n");
    else if (cmp < 0)
        printf("Ngay 1 som hon ngay 2.\n");
    else
        printf("Ngay 1 muon hon ngay 2.\n");

    printf("Khoang cach giua hai ngay: %ld ngay\n", khoangCach(d1, d2));

    return 0;
}
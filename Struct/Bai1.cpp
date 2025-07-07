// Bài tập 1: Quản lý thông tin Sinh viên
// Đề bài: Tạo chương trình quản lý thông tin sinh viên với các yêu cầu:
// • Định nghĩa struct SinhVien gồm: mã sinh viên, họ tên, tuổi, điểm trung bình
// • Nhập thông tin cho n sinh viên từ bàn phím (dùng mảng 1 chiều)
// • Hiển thị thông tin n sinh viên vừa nhập
// • Liệt kê các sinh viên có điểm trung bình >=8
// • Liệt kê sinh viên có điểm trung bình <5
// • Kiểm tra và thông báo xếp loại học lực (Xuất sắc ≥9, Giỏi ≥8, Khá ≥6.5, Trung bình ≥5, 
// Yếu <5)


#include <stdio.h>
#include <string.h>

typedef struct {
    char maSV[20];
    char hoTen[50];
    int tuoi;
    float diemTB;
} SinhVien;

// Hàm nhập thông tin 1 sinh viên
void nhapSV(SinhVien *sv) {
    printf("Nhap ma sinh vien: ");
    scanf("%s", sv->maSV);
    getchar(); // Xóa '\n'
    printf("Nhap ho ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = 0;
    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);
    printf("Nhap diem trung binh: ");
    scanf("%f", &sv->diemTB);
}

// Hàm xuất thông tin 1 sinh viên
void xuatSV(SinhVien sv) {
    printf("%-10s | %-30s | %3d | %5.2f | ", sv.maSV, sv.hoTen, sv.tuoi, sv.diemTB);
    // Xếp loại
    if (sv.diemTB >= 9)
        printf("Xuat sac\n");
    else if (sv.diemTB >= 8)
        printf("Gioi\n");
    else if (sv.diemTB >= 6.5)
        printf("Kha\n");
    else if (sv.diemTB >= 5)
        printf("Trung binh\n");
    else
        printf("Yeu\n");
}

int main() {
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    SinhVien ds[100];
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        nhapSV(&ds[i]);
    }

    printf("\n--- Danh sach sinh vien ---\n");
    printf("%-10s | %-30s | %3s | %5s | %s\n", "MaSV", "Ho ten", "Tuoi", "Diem", "Xep loai");
    for (int i = 0; i < n; i++)
        xuatSV(ds[i]);

    printf("\n--- Sinh vien co diem TB >= 8 ---\n");
    for (int i = 0; i < n; i++)
        if (ds[i].diemTB >= 8)
            xuatSV(ds[i]);

    printf("\n--- Sinh vien co diem TB < 5 ---\n");
    for (int i = 0; i < n; i++)
        if (ds[i].diemTB < 5)
            xuatSV(ds[i]);

    return 0;
}
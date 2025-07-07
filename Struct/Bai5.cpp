// Bài tập 5: Tính lương Nhân viên
// Đề bài: Tạo chương trình tính lương:
// • Struct NhanVien có: mã NV, họ tên, chức vụ, lương cơ bản, hệ số lương, số ngày làm
// • Nhập thông tin cho nhiều nhân viên
// • Tính lương thực lĩnh theo công thức phức tạp
// • Tính các khoản phụ cấp và khấu trừ
// • Xuất bảng lương chi tiết

#include <stdio.h>
#include <string.h>

typedef struct {
    char maNV[20];
    char hoTen[50];
    char chucVu[30];
    float luongCB;
    float heSoLuong;
    int soNgayLam;
    float phuCap;
    float khauTru;
    float thucLinh;
} NhanVien;

// Hàm nhập thông tin 1 nhân viên
void nhapNV(NhanVien *nv) {
    printf("Nhap ma NV: ");
    scanf("%s", nv->maNV);
    getchar();
    printf("Nhap ho ten: ");
    fgets(nv->hoTen, sizeof(nv->hoTen), stdin);
    nv->hoTen[strcspn(nv->hoTen, "\n")] = 0;
    printf("Nhap chuc vu: ");
    fgets(nv->chucVu, sizeof(nv->chucVu), stdin);
    nv->chucVu[strcspn(nv->chucVu, "\n")] = 0;
    printf("Nhap luong co ban: ");
    scanf("%f", &nv->luongCB);
    printf("Nhap he so luong: ");
    scanf("%f", &nv->heSoLuong);
    printf("Nhap so ngay lam: ");
    scanf("%d", &nv->soNgayLam);
}

// Hàm tính phụ cấp dựa vào chức vụ
float tinhPhuCap(const char *chucVu) {
    if (strcmp(chucVu, "Giam doc") == 0)
        return 2000000;
    if (strcmp(chucVu, "Truong phong") == 0)
        return 1000000;
    if (strcmp(chucVu, "Nhan vien") == 0)
        return 500000;
    return 300000; // mặc định cho chức vụ khác
}

// Hàm tính khấu trừ (giả sử: nghỉ quá 2 ngày thì trừ 200k/ngày nghỉ vượt quá)
float tinhKhauTru(int soNgayLam) {
    int nghi = 26 - soNgayLam;
    if (nghi > 2)
        return (nghi - 2) * 200000;
    return 0;
}

// Hàm tính lương thực lĩnh
float tinhThucLinh(float luongCB, float heSo, int soNgayLam, float phuCap, float khauTru) {
    float luong = luongCB * heSo * soNgayLam / 26.0;
    return luong + phuCap - khauTru;
}

// Xuất bảng lương chi tiết
void xuatNV(NhanVien nv) {
    printf("%-10s | %-20s | %-12s | %8.0f | %4.2f | %2d | %8.0f | %8.0f | %10.0f\n",
           nv.maNV, nv.hoTen, nv.chucVu, nv.luongCB, nv.heSoLuong, nv.soNgayLam,
           nv.phuCap, nv.khauTru, nv.thucLinh);
}

int main() {
    int n;
    NhanVien ds[100];
    printf("Nhap so nhan vien: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin nhan vien thu %d:\n", i + 1);
        nhapNV(&ds[i]);
        ds[i].phuCap = tinhPhuCap(ds[i].chucVu);
        ds[i].khauTru = tinhKhauTru(ds[i].soNgayLam);
        ds[i].thucLinh = tinhThucLinh(ds[i].luongCB, ds[i].heSoLuong, ds[i].soNgayLam, ds[i].phuCap, ds[i].khauTru);
    }

    printf("\n%-10s | %-20s | %-12s | %-8s | %-4s | %-2s | %-8s | %-8s | %-10s\n",
           "MaNV", "Ho ten", "Chuc vu", "LuongCB", "HS", "NL", "Phu cap", "Khau tru", "Thuc linh");
    for (int i = 0; i < n; i++)
        xuatNV(ds[i]);

    return 0;
}
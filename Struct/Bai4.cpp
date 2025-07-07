// Bài tập 4: Quản lý thư viện sách
// Đề bài: Viết chương trình quản lý thư viện:
// • Struct Sach gồm: mã sách, tên sách, tác giả, năm xuất bản, giá, số lượng
// • Nhập thông tin cho danh sách sách
// • Hiển thị danh sách với nhiều cách sắp xếp
// • Tìm kiếm sách theo các tiêu chí khác nhau
// • Thống kê giá trị thư viện

#include <stdio.h>
#include <string.h>

typedef struct {
    char maSach[20];
    char tenSach[100];
    char tacGia[50];
    int namXB;
    float gia;
    int soLuong;
} Sach;

// Nhập thông tin 1 sách
void nhapSach(Sach *s) {
    printf("Nhap ma sach: ");
    scanf("%s", s->maSach);
    getchar();
    printf("Nhap ten sach: ");
    fgets(s->tenSach, sizeof(s->tenSach), stdin);
    s->tenSach[strcspn(s->tenSach, "\n")] = 0;
    printf("Nhap tac gia: ");
    fgets(s->tacGia, sizeof(s->tacGia), stdin);
    s->tacGia[strcspn(s->tacGia, "\n")] = 0;
    printf("Nhap nam xuat ban: ");
    scanf("%d", &s->namXB);
    printf("Nhap gia: ");
    scanf("%f", &s->gia);
    printf("Nhap so luong: ");
    scanf("%d", &s->soLuong);
}

// Xuất thông tin 1 sách
void xuatSach(Sach s) {
    printf("%-10s | %-30s | %-20s | %4d | %8.2f | %3d\n",
           s.maSach, s.tenSach, s.tacGia, s.namXB, s.gia, s.soLuong);
}

// Sắp xếp theo giá tăng dần
void sapXepGiaTang(Sach ds[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (ds[i].gia > ds[j].gia) {
                Sach t = ds[i];
                ds[i] = ds[j];
                ds[j] = t;
            }
}

// Sắp xếp theo năm xuất bản giảm dần
void sapXepNamGiam(Sach ds[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (ds[i].namXB < ds[j].namXB) {
                Sach t = ds[i];
                ds[i] = ds[j];
                ds[j] = t;
            }
}

// Tìm kiếm sách theo tên (tìm gần đúng)
void timSachTheoTen(Sach ds[], int n, const char *ten) {
    printf("Ket qua tim kiem theo ten \"%s\":\n", ten);
    int found = 0;
    for (int i = 0; i < n; i++)
        if (strstr(ds[i].tenSach, ten)) {
            xuatSach(ds[i]);
            found = 1;
        }
    if (!found) printf("Khong tim thay sach!\n");
}

// Tìm kiếm sách theo tác giả
void timSachTheoTacGia(Sach ds[], int n, const char *tg) {
    printf("Ket qua tim kiem theo tac gia \"%s\":\n", tg);
    int found = 0;
    for (int i = 0; i < n; i++)
        if (strstr(ds[i].tacGia, tg)) {
            xuatSach(ds[i]);
            found = 1;
        }
    if (!found) printf("Khong tim thay sach!\n");
}

// Thống kê giá trị thư viện
float tongGiaTri(Sach ds[], int n) {
    float tong = 0;
    for (int i = 0; i < n; i++)
        tong += ds[i].gia * ds[i].soLuong;
    return tong;
}

int main() {
    int n;
    Sach ds[100];
    printf("Nhap so luong sach: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sach thu %d:\n", i + 1);
        nhapSach(&ds[i]);
    }

    printf("\n--- Danh sach sach ---\n");
    printf("%-10s | %-30s | %-20s | %4s | %8s | %3s\n", "MaSach", "Ten sach", "Tac gia", "Nam", "Gia", "SL");
    for (int i = 0; i < n; i++)
        xuatSach(ds[i]);

    printf("\n--- Danh sach theo gia tang dan ---\n");
    sapXepGiaTang(ds, n);
    for (int i = 0; i < n; i++)
        xuatSach(ds[i]);

    printf("\n--- Danh sach theo nam xuat ban giam dan ---\n");
    sapXepNamGiam(ds, n);
    for (int i = 0; i < n; i++)
        xuatSach(ds[i]);

    char tenTK[100];
    printf("\nNhap ten sach can tim: ");
    getchar();
    fgets(tenTK, sizeof(tenTK), stdin);
    tenTK[strcspn(tenTK, "\n")] = 0;
    timSachTheoTen(ds, n, tenTK);

    char tgTK[50];
    printf("\nNhap ten tac gia can tim: ");
    fgets(tgTK, sizeof(tgTK), stdin);
    tgTK[strcspn(tgTK, "\n")] = 0;
    timSachTheoTacGia(ds, n, tgTK);

    printf("\nTong gia tri thu vien: %.2f\n", tongGiaTri(ds, n));

    return 0;
}
// Bài tập 10: Quản lý Xe ô tô
// Đề bài: Tạo chương trình quản lý showroom xe:
// • Struct XeOto có: biển số, hãng xe, model, năm sản xuất, giá, màu sắc, tình trạng
// • Nhập thông tin nhiều xe ô tô
// • Tìm kiếm xe theo nhiều tiêu chí
// • Thống kê theo hãng xe, năm sản xuất, tình trạng
// • Quản lý mua bán và cập nhật tồn kho

#include <stdio.h>
#include <string.h>

typedef struct {
    char bienSo[20];
    char hangXe[30];
    char model[30];
    int namSX;
    float gia;
    char mauSac[20];
    char tinhTrang[20]; // "Con hang", "Da ban", "Dat coc", ...
} XeOto;

// Nhập thông tin 1 xe
void nhapXe(XeOto *xe) {
    printf("Nhap bien so: ");
    scanf("%s", xe->bienSo);
    getchar();
    printf("Nhap hang xe: ");
    fgets(xe->hangXe, sizeof(xe->hangXe), stdin);
    xe->hangXe[strcspn(xe->hangXe, "\n")] = 0;
    printf("Nhap model: ");
    fgets(xe->model, sizeof(xe->model), stdin);
    xe->model[strcspn(xe->model, "\n")] = 0;
    printf("Nhap nam san xuat: ");
    scanf("%d", &xe->namSX);
    printf("Nhap gia: ");
    scanf("%f", &xe->gia);
    getchar();
    printf("Nhap mau sac: ");
    fgets(xe->mauSac, sizeof(xe->mauSac), stdin);
    xe->mauSac[strcspn(xe->mauSac, "\n")] = 0;
    printf("Nhap tinh trang: ");
    fgets(xe->tinhTrang, sizeof(xe->tinhTrang), stdin);
    xe->tinhTrang[strcspn(xe->tinhTrang, "\n")] = 0;
}

// Xuất thông tin 1 xe
void xuatXe(XeOto xe) {
    printf("%-10s | %-10s | %-10s | %4d | %10.0f | %-10s | %-10s\n",
           xe.bienSo, xe.hangXe, xe.model, xe.namSX, xe.gia, xe.mauSac, xe.tinhTrang);
}

// Tìm kiếm xe theo hãng
void timTheoHang(XeOto ds[], int n, const char *hang) {
    printf("Danh sach xe hang %s:\n", hang);
    int found = 0;
    for (int i = 0; i < n; i++)
        if (strcmp(ds[i].hangXe, hang) == 0) {
            xuatXe(ds[i]);
            found = 1;
        }
    if (!found) printf("Khong co xe thuoc hang nay!\n");
}

// Tìm kiếm xe theo năm sản xuất
void timTheoNam(XeOto ds[], int n, int nam) {
    printf("Danh sach xe nam %d:\n", nam);
    int found = 0;
    for (int i = 0; i < n; i++)
        if (ds[i].namSX == nam) {
            xuatXe(ds[i]);
            found = 1;
        }
    if (!found) printf("Khong co xe nam nay!\n");
}

// Tìm kiếm xe theo tình trạng
void timTheoTinhTrang(XeOto ds[], int n, const char *tt) {
    printf("Danh sach xe tinh trang %s:\n", tt);
    int found = 0;
    for (int i = 0; i < n; i++)
        if (strcmp(ds[i].tinhTrang, tt) == 0) {
            xuatXe(ds[i]);
            found = 1;
        }
    if (!found) printf("Khong co xe tinh trang nay!\n");
}

// Thống kê theo hãng xe
void thongKeHang(XeOto ds[], int n) {
    printf("\nThong ke so luong xe theo hang:\n");
    for (int i = 0; i < n; i++) {
        int daThongKe = 0;
        for (int j = 0; j < i; j++)
            if (strcmp(ds[i].hangXe, ds[j].hangXe) == 0)
                daThongKe = 1;
        if (!daThongKe) {
            int dem = 0;
            for (int k = 0; k < n; k++)
                if (strcmp(ds[i].hangXe, ds[k].hangXe) == 0)
                    dem++;
            printf("%-10s: %d xe\n", ds[i].hangXe, dem);
        }
    }
}

// Thống kê theo năm sản xuất
void thongKeNam(XeOto ds[], int n) {
    printf("\nThong ke so luong xe theo nam san xuat:\n");
    for (int i = 0; i < n; i++) {
        int daThongKe = 0;
        for (int j = 0; j < i; j++)
            if (ds[i].namSX == ds[j].namSX)
                daThongKe = 1;
        if (!daThongKe) {
            int dem = 0;
            for (int k = 0; k < n; k++)
                if (ds[i].namSX == ds[k].namSX)
                    dem++;
            printf("%4d: %d xe\n", ds[i].namSX, dem);
        }
    }
}

// Thống kê theo tình trạng
void thongKeTinhTrang(XeOto ds[], int n) {
    printf("\nThong ke so luong xe theo tinh trang:\n");
    for (int i = 0; i < n; i++) {
        int daThongKe = 0;
        for (int j = 0; j < i; j++)
            if (strcmp(ds[i].tinhTrang, ds[j].tinhTrang) == 0)
                daThongKe = 1;
        if (!daThongKe) {
            int dem = 0;
            for (int k = 0; k < n; k++)
                if (strcmp(ds[i].tinhTrang, ds[k].tinhTrang) == 0)
                    dem++;
            printf("%-10s: %d xe\n", ds[i].tinhTrang, dem);
        }
    }
}

// Quản lý mua bán: cập nhật tình trạng xe theo biển số
void capNhatTinhTrang(XeOto ds[], int n, const char *bienSo, const char *tinhTrangMoi) {
    for (int i = 0; i < n; i++)
        if (strcmp(ds[i].bienSo, bienSo) == 0) {
            strcpy(ds[i].tinhTrang, tinhTrangMoi);
            printf("Da cap nhat tinh trang xe %s thanh %s\n", bienSo, tinhTrangMoi);
            return;
        }
    printf("Khong tim thay xe co bien so %s!\n", bienSo);
}

int main() {
    int n;
    XeOto ds[100];
    printf("Nhap so luong xe: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin xe thu %d:\n", i + 1);
        nhapXe(&ds[i]);
    }

    printf("\n%-10s | %-10s | %-10s | %-4s | %-10s | %-10s | %-10s\n",
           "Bien so", "Hang", "Model", "Nam", "Gia", "Mau", "Tinh trang");
    for (int i = 0; i < n; i++)
        xuatXe(ds[i]);

    // Tìm kiếm
    char hang[30], tt[20];
    int nam;
    printf("\nNhap hang xe can tim: ");
    getchar();
    fgets(hang, sizeof(hang), stdin);
    hang[strcspn(hang, "\n")] = 0;
    timTheoHang(ds, n, hang);

    printf("\nNhap nam san xuat can tim: ");
    scanf("%d", &nam);
    timTheoNam(ds, n, nam);

    printf("\nNhap tinh trang can tim: ");
    getchar();
    fgets(tt, sizeof(tt), stdin);
    tt[strcspn(tt, "\n")] = 0;
    timTheoTinhTrang(ds, n, tt);

    // Thống kê
    thongKeHang(ds, n);
    thongKeNam(ds, n);
    thongKeTinhTrang(ds, n);

    // Quản lý mua bán: cập nhật tồn kho
    char bienSo[20], tinhTrangMoi[20];
    printf("\nNhap bien so xe can cap nhat: ");
    fgets(bienSo, sizeof(bienSo), stdin);
    bienSo[strcspn(bienSo, "\n")] = 0;
    printf("Nhap tinh trang moi: ");
    fgets(tinhTrangMoi, sizeof(tinhTrangMoi), stdin);
    tinhTrangMoi[strcspn(tinhTrangMoi, "\n")] = 0;
    capNhatTinhTrang(ds, n, bienSo, tinhTrangMoi);

    return 0;
}
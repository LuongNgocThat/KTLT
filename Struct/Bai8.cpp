// ài tập 8: Xếp loại Học sinh
// Đề bài: Tạo chương trình quản lý điểm học sinh:
// • Struct HocSinh có: họ tên, lớp, điểm các môn, điểm rèn luyện
// • Tính điểm trung bình có trọng số
// • Xếp loại học lực và hạnh kiểm
// • Thống kê lớp học và tìm học sinh xuất sắc

#include <stdio.h>
#include <string.h>

typedef struct {
    char hoTen[50];
    char lop[10];
    float toan, van, anh, renLuyen;
    float diemTB;
    char xepLoaiHocLuc[20];
    char xepLoaiRenLuyen[20];
} HocSinh;

// Tính điểm trung bình có trọng số (Toán*2, Văn*2, Anh*1)
float tinhDiemTB(HocSinh hs) {
    return (hs.toan*2 + hs.van*2 + hs.anh) / 5.0;
}

// Xếp loại học lực
void xepLoaiHoc(HocSinh *hs) {
    if (hs->diemTB >= 9)
        strcpy(hs->xepLoaiHocLuc, "Xuat sac");
    else if (hs->diemTB >= 8)
        strcpy(hs->xepLoaiHocLuc, "Gioi");
    else if (hs->diemTB >= 6.5)
        strcpy(hs->xepLoaiHocLuc, "Kha");
    else if (hs->diemTB >= 5)
        strcpy(hs->xepLoaiHocLuc, "Trung binh");
    else
        strcpy(hs->xepLoaiHocLuc, "Yeu");
}

// Xếp loại rèn luyện
void xepLoaiRL(HocSinh *hs) {
    if (hs->renLuyen >= 9)
        strcpy(hs->xepLoaiRenLuyen, "Tot");
    else if (hs->renLuyen >= 7)
        strcpy(hs->xepLoaiRenLuyen, "Kha");
    else if (hs->renLuyen >= 5)
        strcpy(hs->xepLoaiRenLuyen, "Trung binh");
    else
        strcpy(hs->xepLoaiRenLuyen, "Yeu");
}

// Nhập thông tin học sinh
void nhapHS(HocSinh *hs) {
    printf("Nhap ho ten: ");
    getchar();
    fgets(hs->hoTen, sizeof(hs->hoTen), stdin);
    hs->hoTen[strcspn(hs->hoTen, "\n")] = 0;
    printf("Nhap lop: ");
    fgets(hs->lop, sizeof(hs->lop), stdin);
    hs->lop[strcspn(hs->lop, "\n")] = 0;
    printf("Nhap diem Toan: ");
    scanf("%f", &hs->toan);
    printf("Nhap diem Van: ");
    scanf("%f", &hs->van);
    printf("Nhap diem Anh: ");
    scanf("%f", &hs->anh);
    printf("Nhap diem ren luyen: ");
    scanf("%f", &hs->renLuyen);
    hs->diemTB = tinhDiemTB(*hs);
    xepLoaiHoc(hs);
    xepLoaiRL(hs);
}

// Xuất thông tin học sinh
void xuatHS(HocSinh hs) {
    printf("%-20s | %-6s | %4.1f | %4.1f | %4.1f | %4.1f | %5.2f | %-10s | %-10s\n",
           hs.hoTen, hs.lop, hs.toan, hs.van, hs.anh, hs.renLuyen, hs.diemTB, hs.xepLoaiHocLuc, hs.xepLoaiRenLuyen);
}

int main() {
    int n;
    HocSinh ds[100];
    printf("Nhap so hoc sinh: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin hoc sinh thu %d:\n", i + 1);
        nhapHS(&ds[i]);
    }

    printf("\n%-20s | %-6s | %4s | %4s | %4s | %4s | %5s | %-10s | %-10s\n",
           "Ho ten", "Lop", "Toan", "Van", "Anh", "RL", "DTB", "Hoc luc", "Ren luyen");
    for (int i = 0; i < n; i++)
        xuatHS(ds[i]);

    // Thống kê lớp học
    printf("\nThong ke hoc sinh theo lop:\n");
    for (int i = 0; i < n; i++) {
        int daThongKe = 0;
        for (int j = 0; j < i; j++)
            if (strcmp(ds[i].lop, ds[j].lop) == 0)
                daThongKe = 1;
        if (!daThongKe) {
            int dem = 0;
            for (int k = 0; k < n; k++)
                if (strcmp(ds[i].lop, ds[k].lop) == 0)
                    dem++;
            printf("Lop %s: %d hoc sinh\n", ds[i].lop, dem);
        }
    }

    // Tìm học sinh xuất sắc
    printf("\nHoc sinh xuat sac:\n");
    int found = 0;
    for (int i = 0; i < n; i++)
        if (strcmp(ds[i].xepLoaiHocLuc, "Xuat sac") == 0 && strcmp(ds[i].xepLoaiRenLuyen, "Tot") == 0) {
            xuatHS(ds[i]);
            found = 1;
        }
    if (!found)
        printf("Khong co hoc sinh xuat sac!\n");

    return 0;
}
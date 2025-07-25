// ĐỀ ÔN TẬP SỐ 1 - Y TẾ
// Cho tập tin patients.txt chứa thông tin bệnh nhân theo cấu trúc: Mã BN, Họ tên, Tuổi, Giới 
// tính, Chẩn đoán, Ngày nhập viện
// BN001,Nguyen Van Nam,45,Nam,Cao huyet ap,2025-01-15
// BN002,Tran Thi Mai,32,Nu,Viem gan B,2025-01-16
// BN003,Le Minh Duc,28,Nam,Gan ruou,2025-01-17
// BN004,Pham Thi Lan,55,Nu,Tieu duong,2025-01-18
// BN005,Hoang Van Tuan,67,Nam,Suy tim,2025-01-19
// Thực hiện các yêu cầu sau: 

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
// a) Khai báo cấu trúc có tên BenhNhan để quản lý thông tin bệnh nhân. (1 điểm) 
typedef struct {
    char maBN[10];
    char hoTen[50];
    int tuoi;
    char gioiTinh[10];
    char chanDoan[50];
    char ngayNhapVien[20];
} BenhNhan;
// b) Viết hàm đọc dữ liệu từ file và lưu vào mảng động. (2 điểm) 

int docFile(BenhNhan **bn, const char *tenFile) {
    // Mở file (0.5 điểm)
    FILE *f = fopen(tenFile, "r");
    if (f == NULL) {
        printf("Khong the mo file %s\n", tenFile);
        return 0;
    }

    // Cấp phát bộ nhớ (0.25 điểm)
    *bn = (BenhNhan*)malloc(100 * sizeof(BenhNhan));
    int n = 0;

    // Đọc dữ liệu (1 điểm)
    char line[200];
    while (fgets(line, sizeof(line), f)) {
        char *token = strtok(line, ",");
        strcpy((*bn)[n].maBN, token);

        token = strtok(NULL, ",");
        strcpy((*bn)[n].hoTen, token);

        token = strtok(NULL, ",");
        (*bn)[n].tuoi = atoi(token);

        token = strtok(NULL, ",");
        strcpy((*bn)[n].gioiTinh, token);

        token = strtok(NULL, ",");
        strcpy((*bn)[n].chanDoan, token);

        token = strtok(NULL, ",\n");
        strcpy((*bn)[n].ngayNhapVien, token);

        n++;
    }

    // Đóng file (0.25 điểm)
    fclose(f);
    return n;
}

// c) Viết hàm tìm bệnh nhân cao tuổi nhất và in thông tin. (1 điểm) 

int timBenhNhanCaoTuoiNhat(BenhNhan *bn, int n) {
    int maxIndex = 0;

    // Tìm bệnh nhân lớn tuổi nhất (0.5 điểm)
    for (int i = 1; i < n; i++) {
        if (bn[i].tuoi > bn[maxIndex].tuoi) {
            maxIndex = i;
        }
    }

    // In kết quả (0.5 điểm)
    printf("Benh nhan cao tuoi nhat:\n");
    printf("Ma BN: %s\n", bn[maxIndex].maBN);
    printf("Ho ten: %s\n", bn[maxIndex].hoTen);
    printf("Tuoi: %d\n", bn[maxIndex].tuoi);
    printf("Gioi tinh: %s\n", bn[maxIndex].gioiTinh);
    printf("Chan doan: %s\n", bn[maxIndex].chanDoan);
    printf("Ngay nhap vien: %s\n", bn[maxIndex].ngayNhapVien);

    return maxIndex;
}

// d) Viết hàm thống kê số lượng bệnh nhân theo giới tính, ghi kết quả vào file  gender_stats.txt. (1 điểm)

void ghiThongKeGioiTinh(BenhNhan *bn, int n) {
    int nam = 0, nu = 0;

    // Đếm số lượng theo giới tính (0.5 điểm)
    for (int i = 0; i < n; i++) {
        if (strcmp(bn[i].gioiTinh, "Nam") == 0) nam++;
        else if (strcmp(bn[i].gioiTinh, "Nu") == 0) nu++;
    }

    // Ghi file (0.5 điểm)
    FILE *f = fopen("gender_stats.txt", "w");
    if (f == NULL) {
        printf("Khong the ghi file gender_stats.txt\n");
        return;
    }

    fprintf(f, "Gioi tinh: Nam\nSo luong: %d\n", nam);
    fprintf(f, "Gioi tinh: Nu\nSo luong: %d\n", nu);
    fclose(f);
}


int main() {
    BenhNhan *ds;
    int soLuong = docFile(&ds, "patients.txt");
    if (soLuong == 0) return 1;

    timBenhNhanCaoTuoiNhat(ds, soLuong);
    ghiThongKeGioiTinh(ds, soLuong);

    free(ds);
    return 0;
}

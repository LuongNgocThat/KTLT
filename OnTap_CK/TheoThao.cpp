// ĐỀ ÔN TẬP SỐ 3 - THỂ THAO
// CÂU 2: CLO (5.0 điểm)
// Cho tập tin athletes.txt chứa thông tin vận động viên theo cấu trúc: Mã VDV, Họ tên, Môn 
// thi đấu, Tuổi, Thành tích (giây)
// VDV001,Nguyen Van Duc,Boi loi,22,118.45
// VDV002,Tran Thi Hoa,Boi loi,24,125.30
// VDV003,Le Minh Tuan,Boi loi,26,121.75
// VDV004,Pham Thi Lan,Boi loi,23,119.80
// VDV005,Hoang Van Nam,Boi loi,28,123.60
// VDV006,Vo Thi Mai,Boi loi,25,117.25
// VDV007,Dang Van Phuc,Boi loi,27,120.90
// VDV008,Nguyen Thi Linh,Boi loi,24,122.45
// Thực hiện các yêu cầu sau:
// a) Khai báo cấu trúc VanDongVien để lưu trữ thông tin. (1 điểm)
typedef struct {
    char maVDV[10];        // 0.2 điểm
    char hoTen[50];        // 0.2 điểm
    char monThiDau[30];    // 0.2 điểm
    int tuoi;              // 0.2 điểm
    float thanhTich;       // 0.2 điểm
} VanDongVien;

// b) Viết hàm đọc file và lưu vào mảng động. (2 điểm)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int docFile(VanDongVien **ds, const char *tenFile) {
    // Mở file (0.5 điểm)
    FILE *f = fopen(tenFile, "r");
    if (f == NULL) {
        printf("Khong the mo file %s\n", tenFile);
        return 0;
    }

    // Cấp phát bộ nhớ (0.25 điểm)
    *ds = (VanDongVien*)malloc(100 * sizeof(VanDongVien));
    int n = 0;
    char line[200];

    // Đọc dữ liệu từng dòng (1 điểm)
    while (fgets(line, sizeof(line), f)) {
        char *token = strtok(line, ",");
        strcpy((*ds)[n].maVDV, token);

        token = strtok(NULL, ",");
        strcpy((*ds)[n].hoTen, token);

        token = strtok(NULL, ",");
        strcpy((*ds)[n].monThiDau, token);

        token = strtok(NULL, ",");
        (*ds)[n].tuoi = atoi(token);

        token = strtok(NULL, ",\n");
        (*ds)[n].thanhTich = atof(token);

        n++;
    }

    // Đóng file (0.25 điểm)
    fclose(f);
    return n;
}

// c) Viết hàm tìm và in thông tin vận động viên trẻ nhất. (1 điểm)
void timVDVTreNhat(VanDongVien *ds, int n) {
    if (n == 0) return;

    int minIndex = 0;

    // Tìm vị trí VĐV trẻ nhất (0.5 điểm)
    for (int i = 1; i < n; i++) {
        if (ds[i].tuoi < ds[minIndex].tuoi) {
            minIndex = i;
        }
    }

    // In thông tin (0.5 điểm)
    printf("Van dong vien tre nhat:\n");
    printf("Ma VDV: %s\n", ds[minIndex].maVDV);
    printf("Ho ten: %s\n", ds[minIndex].hoTen);
    printf("Mon thi dau: %s\n", ds[minIndex].monThiDau);
    printf("Tuoi: %d\n", ds[minIndex].tuoi);
    printf("Thanh tich: %.2f giay\n", ds[minIndex].thanhTich);
}

// d) Viết hàm tìm 3 vận động viên có thành tích cao nhất (thời gian thấp nhất), ghi kết quả
// vào file top3_swimmers.txt theo thứ tự thành tích tăng dần. (1 điểm)
void ghiTop3ThanhTich(VanDongVien *ds, int n) {
    if (n < 3) return;

    // Sắp xếp tăng dần theo thành tích (0.5 điểm)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].thanhTich > ds[j].thanhTich) {
                VanDongVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    // Ghi 3 VĐV đầu tiên vào file (0.5 điểm)
    FILE *f = fopen("top3_swimmers.txt", "w");
    if (f == NULL) {
        printf("Khong the ghi file top3_swimmers.txt\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        fprintf(f, "%s,%s,%s,%d,%.2f\n",
            ds[i].maVDV, ds[i].hoTen, ds[i].monThiDau,
            ds[i].tuoi, ds[i].thanhTich);
    }

    fclose(f);
}
int main() {
    VanDongVien *ds;
    int soLuong = docFile(&ds, "athletes.txt");
    if (soLuong == 0) return 1;

    timVDVTreNhat(ds, soLuong);
    ghiTop3ThanhTich(ds, soLuong);

    free(ds);
    return 0;
}

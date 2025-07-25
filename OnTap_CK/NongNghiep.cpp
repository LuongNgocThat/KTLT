// ĐỀ ÔN TẬP SỐ 7 - NÔNG NGHIỆP
// CÂU 2: CLO (5.0 điểm)
// Cho tập tin crops.txt chứa thông tin nông sản theo cấu trúc: Mã NS, Tên nông sản, Vùng 
// trồng, Năng suất (tấn/ha), Giá thu mua (VND/kg)
// NS001,Lua ST25,Mien Tay,7.2,8000
// NS002,Cà phê Robusta,Tay Nguyen,3.5,45000
// NS003,Cao su,Dong Nam Bo,2.8,15000
// NS004,Dua,Mien Tay,25.0,12000
// NS005,Ngo,Mien Bac,5.5,6000
// Thực hiện các yêu cầu sau: 
// a) Khai báo cấu trúc NongSan để lưu trữ thông tin. (1 điểm) 
typedef struct {
    char maNS[10];
    char tenNS[50];
    char vungTrong[30];
    float nangSuat;       // đơn vị: tấn/ha
    int giaThuMua;        // đơn vị: VND/kg
} NongSan;

// b) Viết hàm đọc file và lưu vào mảng động. (2 điểm) 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NongSan* docFile(char* tenFile, int* soLuong) {
    FILE* f = fopen(tenFile, "r");
    if (!f) {
        printf("Khong mo duoc file.\n");
        return NULL;
    }

    NongSan* ds = NULL;
    *soLuong = 0;
    char line[200];

    while (fgets(line, sizeof(line), f)) {
        ds = (NongSan*)realloc(ds, (*soLuong + 1) * sizeof(NongSan));
        char* token = strtok(line, ",");
        strcpy(ds[*soLuong].maNS, token);

        token = strtok(NULL, ",");
        strcpy(ds[*soLuong].tenNS, token);

        token = strtok(NULL, ",");
        strcpy(ds[*soLuong].vungTrong, token);

        token = strtok(NULL, ",");
        ds[*soLuong].nangSuat = atof(token);

        token = strtok(NULL, ",");
        ds[*soLuong].giaThuMua = atoi(token);

        (*soLuong)++;
    }

    fclose(f);
    return ds;
}

// c) Viết hàm tìm nông sản có năng suất cao nhất theo vùng (nhập từ bàn phím). (1 điểm) 
void timNangSuatCaoNhatTheoVung(NongSan* ds, int n, char* vung) {
    float maxNS = -1;
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].vungTrong, vung) == 0 && ds[i].nangSuat > maxNS) {
            maxNS = ds[i].nangSuat;
            found = i;
        }
    }

    if (maxNS != -1) {
        printf("Nong san co nang suat cao nhat o %s:\n", vung);
        printf("Ma NS: %s\n", ds[found].maNS);
        printf("Ten: %s\n", ds[found].tenNS);
        printf("Nang suat: %.2f tan/ha\n", ds[found].nangSuat);
    } else {
        printf("Khong tim thay nong san o vung %s.\n", vung);
    }
}

// d) Viết hàm tính doanh thu ước tính cho mỗi nông sản (năng suất tấn/ha × 1000 kg/tấn × 
// giá VND/kg), ghi vào file revenue_estimate.txt theo định dạng (1điểm):
// Ma NS: NS001
// Ten nong san: Lua ST25
// Doanh thu uoc tinh: 57600000 VND/ha
// Ma NS: NS002
// Ten nong san: Ca phe Robusta
// Doanh thu uoc tinh: 157500000 VND/ha
void ghiDoanhThuUocTinh(NongSan* ds, int n, char* tenFileOut) {
    FILE* f = fopen(tenFileOut, "w");
    if (!f) {
        printf("Khong ghi duoc file.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        long doanhThu = (long)(ds[i].nangSuat * 1000 * ds[i].giaThuMua);
        fprintf(f, "Ma NS: %s\n", ds[i].maNS);
        fprintf(f, "Ten nong san: %s\n", ds[i].tenNS);
        fprintf(f, "Doanh thu uoc tinh: %ld VND/ha\n\n", doanhThu);
    }

    fclose(f);
    printf("Da ghi doanh thu uoc tinh vao file %s\n", tenFileOut);
}
int main() {
    int n;
    NongSan* ds = docFile("crops.txt", &n);

    if (!ds) return 1;

    char vung[30];
    printf("Nhap vung trong: ");
    gets(vung);  // hoặc dùng fgets + xử lý '\n'
    timNangSuatCaoNhatTheoVung(ds, n, vung);

    ghiDoanhThuUocTinh(ds, n, "revenue_estimate.txt");

    free(ds);
    return 0;
}

// ĐỀ ÔN TẬP SỐ 9 - BẤT ĐỘNG SẢN
// CÂU 2: CLO (5.0 điểm)
// Cho tập tin properties.txt chứa thông tin bất động sản theo cấu trúc: Mã BDS, Loại hình, 
// Quận/huyện, Diện tích (m²), Giá (triệu VND)
// BDS001,Chung cu,Quan 1,75,8500
// BDS002,Nha pho,Quan 7,120,12000
// BDS003,Dat nen,Hoc Mon,150,3500
// BDS004,Biet thu,Quan 2,250,25000
// BDS005,Chung cu,Quan 9,65,4800
// Thực hiện các yêu cầu sau: 
// a) Khai báo cấu trúc BatDongSan để quản lý thông tin. (1 điểm) 
typedef struct {
    char maBDS[10];
    char loaiHinh[30];
    char quanHuyen[30];
    float dienTich;    // m2
    float gia;         // triệu VND
} BatDongSan;

// b) Viết hàm đọc file và lưu vào mảng động. (2 điểm) 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

BatDongSan* docFile(const char* tenFile, int* n) {
    FILE* f = fopen(tenFile, "r");
    if (!f) {
        printf("Khong mo duoc file.\n");
        return NULL;
    }

    BatDongSan* ds = NULL;
    *n = 0;
    char line[200];

    while (fgets(line, sizeof(line), f)) {
        ds = (BatDongSan*)realloc(ds, (*n + 1) * sizeof(BatDongSan));
        char* token = strtok(line, ",");
        strcpy(ds[*n].maBDS, token);

        token = strtok(NULL, ",");
        strcpy(ds[*n].loaiHinh, token);

        token = strtok(NULL, ",");
        strcpy(ds[*n].quanHuyen, token);

        token = strtok(NULL, ",");
        ds[*n].dienTich = atof(token);

        token = strtok(NULL, ",\n");
        ds[*n].gia = atof(token);

        (*n)++;
    }

    fclose(f);
    return ds;
}

// c) Viết hàm tính giá trung bình mỗi m² theo loại hình được nhập từ bàn phím. (1 điểm) 
void tinhGiaTrungBinhTheoLoai(BatDongSan* ds, int n) {
    char loaiCanTim[30];
    printf("Nhap loai hinh can tinh gia trung binh: ");
    scanf("%s", loaiCanTim);

    float tongGia = 0;
    float tongDienTich = 0;
    int dem = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].loaiHinh, loaiCanTim) == 0) {
            tongGia += ds[i].gia;
            tongDienTich += ds[i].dienTich;
            dem++;
        }
    }

    if (dem > 0 && tongDienTich > 0) {
        float giaTB = tongGia / tongDienTich;
        printf("Gia trung binh moi m2 cua loai %s la: %.2f trieu/m2\n", loaiCanTim, giaTB);
    } else {
        printf("Khong co du lieu cho loai hinh %s\n", loaiCanTim);
    }
}

// d) Viết hàm lọc BDS có giá <= 10000 triệu, sắp xếp theo diện tích giảm dần, ghi vào file 
// affordable_properties.txt. (1 điểm)
int soSanhDienTichGiam(const void* a, const void* b) {
    BatDongSan* x = (BatDongSan*)a;
    BatDongSan* y = (BatDongSan*)b;
    if (y->dienTich > x->dienTich) return 1;
    else if (y->dienTich < x->dienTich) return -1;
    return 0;
}

void locVaGhiFile(BatDongSan* ds, int n, const char* tenFileOut) {
    BatDongSan* filtered = (BatDongSan*)malloc(n * sizeof(BatDongSan));
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (ds[i].gia <= 10000) {
            filtered[count++] = ds[i];
        }
    }

    qsort(filtered, count, sizeof(BatDongSan), soSanhDienTichGiam);

    FILE* f = fopen(tenFileOut, "w");
    for (int i = 0; i < count; i++) {
        fprintf(f, "%s,%s,%s,%.2f,%.2f\n",
                filtered[i].maBDS,
                filtered[i].loaiHinh,
                filtered[i].quanHuyen,
                filtered[i].dienTich,
                filtered[i].gia);
    }

    fclose(f);
    free(filtered);
}
int main() {
    int n;
    BatDongSan* ds = docFile("properties.txt", &n);
    if (!ds) return 1;

    tinhGiaTrungBinhTheoLoai(ds, n);

    locVaGhiFile(ds, n, "affordable_properties.txt");

    free(ds);
    return 0;
}

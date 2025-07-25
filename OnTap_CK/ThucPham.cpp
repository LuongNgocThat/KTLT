// ĐỀ ÔN TẬP SỐ 4 - THỰC PHẨM
// CÂU 2: CLO (5.0 điểm)
// Cho tập tin foods.txt chứa thông tin thực phẩm theo cấu trúc: Mã SP, Tên món, Loại thực 
// phẩm, Calories, Giá bán
// SP001,Pho Bo,Mon chinh,450,35000
// SP002,Banh mi,An sang,320,15000
// SP003,Che ba mau,Trang mieng,280,20000
// SP004,Com tam,Mon chinh,520,40000
// SP005,Sinh to xoai,Nuoc uong,180,25000
// Thực hiện các yêu cầu sau:
// a) Khai báo cấu trúc ThucPham phù hợp. (1 điểm) 
typedef struct {
    char maSP[10];         // 0.2 điểm
    char tenMon[50];       // 0.2 điểm
    char loaiTP[30];       // 0.2 điểm
    int calories;          // 0.2 điểm
    int giaBan;            // 0.2 điểm
} ThucPham;

// b) Viết hàm đọc dữ liệu từ file vào mảng động. (2 điểm) 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int docFile(ThucPham **tp, const char *tenFile) {
    // Mở file (0.5 điểm)
    FILE *f = fopen(tenFile, "r");
    if (f == NULL) {
        printf("Khong the mo file %s\n", tenFile);
        return 0;
    }

    // Cấp phát bộ nhớ (0.25 điểm)
    *tp = (ThucPham*)malloc(100 * sizeof(ThucPham));
    int n = 0;
    char line[200];

    // Đọc từng dòng dữ liệu (1 điểm)
    while (fgets(line, sizeof(line), f)) {
        char *token = strtok(line, ",");
        strcpy((*tp)[n].maSP, token);

        token = strtok(NULL, ",");
        strcpy((*tp)[n].tenMon, token);

        token = strtok(NULL, ",");
        strcpy((*tp)[n].loaiTP, token);

        token = strtok(NULL, ",");
        (*tp)[n].calories = atoi(token);

        token = strtok(NULL, ",\n");
        (*tp)[n].giaBan = atoi(token);

        n++;
    }

    // Đóng file (0.25 điểm)
    fclose(f);
    return n;
}

// c) Viết hàm tìm món ăn có calories thấp nhất và in thông tin. (1 điểm) 
void timMonCaloriesThapNhat(ThucPham *tp, int n) {
    if (n == 0) return;
    int minIndex = 0;

    // Tìm vị trí calories thấp nhất (0.5 điểm)
    for (int i = 1; i < n; i++) {
        if (tp[i].calories < tp[minIndex].calories) {
            minIndex = i;
        }
    }

    // In thông tin món ăn (0.5 điểm)
    printf("Mon an co calories thap nhat:\n");
    printf("Ma SP: %s\n", tp[minIndex].maSP);
    printf("Ten mon: %s\n", tp[minIndex].tenMon);
    printf("Loai TP: %s\n", tp[minIndex].loaiTP);
    printf("Calories: %d\n", tp[minIndex].calories);
    printf("Gia ban: %d\n", tp[minIndex].giaBan);
}

// d) Viết hàm lọc các món có giá <= 30000, sắp xếp theo calories tăng dần, ghi vào file 
// budget_menu.txt. (1 điểm)
void ghiMonGiaRe(ThucPham *tp, int n) {
    // Lọc món có giá <= 30000 (0.25 điểm)
    ThucPham *ds = (ThucPham*)malloc(n * sizeof(ThucPham));
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (tp[i].giaBan <= 30000) {
            ds[count++] = tp[i];
        }
    }

    // Sắp xếp tăng dần theo calories (0.25 điểm)
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (ds[i].calories > ds[j].calories) {
                ThucPham temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    // Ghi vào file (0.5 điểm)
    FILE *f = fopen("budget_menu.txt", "w");
    if (f == NULL) {
        printf("Khong ghi duoc file budget_menu.txt\n");
        free(ds);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(f, "%s,%s,%s,%d,%d\n",
            ds[i].maSP, ds[i].tenMon, ds[i].loaiTP,
            ds[i].calories, ds[i].giaBan);
    }

    fclose(f);
    free(ds);
}
int main() {
    ThucPham *ds;
    int soLuong = docFile(&ds, "foods.txt");
    if (soLuong == 0) return 1;

    timMonCaloriesThapNhat(ds, soLuong);
    ghiMonGiaRe(ds, soLuong);

    free(ds);
    return 0;
}

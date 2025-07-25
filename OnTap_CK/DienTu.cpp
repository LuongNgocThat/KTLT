// ĐỀ ÔN TẬP SỐ 5 - ĐIỆN TỬ
// CÂU 2: CLO (5.0 điểm)
// Cho tập tin electronics.txt chứa thông tin thiết bị điện tử theo cấu trúc: Mã TB, Tên thiết 
// bị, Hãng sản xuất, Công suất (W), Bảo hành (tháng)
// TB001,Tivi 55 inch,Samsung,150,24
// TB002,May lanh 1.5HP,Daikin,1200,36
// TB003,Tu lanh 2 canh,LG,180,24
// TB004,May giat 8kg,Electrolux,500,24
// TB005,Loa Bluetooth,JBL,20,12
// Thực hiện các yêu cầu sau: 
// a) Khai báo cấu trúc ThietBi để quản lý thông tin. (1 điểm) 
typedef struct {
    char maTB[10];
    char tenTB[50];
    char hangSX[30];
    int congSuat;
    int baoHanh;
} ThietBi;


// b) Viết hàm đọc file và lưu vào mảng động. (2 điểm) 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ThietBi* docFile(const char* tenFile, int* n) {
    FILE* f = fopen(tenFile, "r");
    if (!f) {
        printf("Khong mo duoc file!\n");
        exit(1);
    }

    ThietBi* ds = NULL;
    *n = 0;
    char line[200];
    
    while (fgets(line, sizeof(line), f)) {
        ds = realloc(ds, (*n + 1) * sizeof(ThietBi));
        sscanf(line, "%[^,],%[^,],%[^,],%d,%d",
               ds[*n].maTB, ds[*n].tenTB, ds[*n].hangSX,
               &ds[*n].congSuat, &ds[*n].baoHanh);
        (*n)++;
    }

    fclose(f);
    return ds;
}

// c) Viết hàm tính tổng công suất của tất cả thiết bị. (1 điểm) 
int tinhTongCongSuat(ThietBi* ds, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].congSuat;
    }
    return tong;
}

// d) Viết hàm lọc thiết bị có bảo hành >= 24 tháng, ghi vào file long_warranty.txt theo thứ
// tự công suất tăng dần. (1 điểm)
int soSanhCongSuat(const void* a, const void* b) {
    ThietBi* x = (ThietBi*)a;
    ThietBi* y = (ThietBi*)b;
    return x->congSuat - y->congSuat;
}

void locVaGhiThietBi(ThietBi* ds, int n, const char* tenFileOut) {
    ThietBi* ketQua = malloc(n * sizeof(ThietBi));
    int dem = 0;

    for (int i = 0; i < n; i++) {
        if (ds[i].baoHanh >= 24) {
            ketQua[dem++] = ds[i];
        }
    }

    qsort(ketQua, dem, sizeof(ThietBi), soSanhCongSuat);

    FILE* f = fopen(tenFileOut, "w");
    for (int i = 0; i < dem; i++) {
        fprintf(f, "%s,%s,%s,%d,%d\n",
                ketQua[i].maTB,
                ketQua[i].tenTB,
                ketQua[i].hangSX,
                ketQua[i].congSuat,
                ketQua[i].baoHanh);
    }
    fclose(f);
    free(ketQua);
}

int main() {
    int n;
    ThietBi* ds = docFile("electronics.txt", &n);

    printf("Tong cong suat: %d W\n", tinhTongCongSuat(ds, n));

    locVaGhiThietBi(ds, n, "long_warranty.txt");

    free(ds);
    return 0;
}

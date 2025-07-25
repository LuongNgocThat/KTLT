// ĐỀ ÔN TẬP SỐ 10 - KHÁCH SẠN
// CÂU 2: CLO (5.0 điểm)
// Cho tập tin bookings.txt chứa thông tin đặt phòng theo cấu trúc: Mã booking, Tên khách, 
// Loại phòng, Số đêm, Giá phòng/đêm
// BK001,Nguyen Van A,Deluxe,3,1200000
// BK002,Tran Thi B,Standard,2,800000
// BK003,Le Van C,Suite,5,2500000
// BK004,Pham Thi D,Standard,1,800000
// BK005,Hoang Van E,Deluxe,4,1200000
// Thực hiện các yêu cầu sau: 
// a) Khai báo cấu trúc DatPhong phù hợp. (1 điểm) 
typedef struct {
    char maBooking[10];
    char tenKhach[50];
    char loaiPhong[20];
    int soDem;
    long giaPhong;  // giá phòng / đêm
} DatPhong;

// b) Viết hàm đọc dữ liệu và lưu vào mảng động. (2 điểm) 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DatPhong* docFile(const char* tenFile, int* n) {
    FILE* f = fopen(tenFile, "r");
    if (!f) {
        printf("Khong mo duoc file.\n");
        return NULL;
    }

    DatPhong* ds = NULL;
    *n = 0;
    char line[200];

    while (fgets(line, sizeof(line), f)) {
        ds = (DatPhong*)realloc(ds, (*n + 1) * sizeof(DatPhong));
        char* token = strtok(line, ",");
        strcpy(ds[*n].maBooking, token);

        token = strtok(NULL, ",");
        strcpy(ds[*n].tenKhach, token);

        token = strtok(NULL, ",");
        strcpy(ds[*n].loaiPhong, token);

        token = strtok(NULL, ",");
        ds[*n].soDem = atoi(token);

        token = strtok(NULL, ",\n");
        ds[*n].giaPhong = atol(token);

        (*n)++;
    }

    fclose(f);
    return ds;
}

// c) Viết hàm tính tổng doanh thu từ tất cả booking (số đêm × giá phòng/đêm). (1 điểm) 
long tinhTongDoanhThu(DatPhong* ds, int n) {
    long tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].soDem * ds[i].giaPhong;
    }
    return tong;
}

// d) Viết hàm tìm khách hàng có tổng chi phí cao hơn hoặc bằng 5000000, ghi vào file 
// vip_customers.txt. (1 điểm)

void ghiVipCustomers(DatPhong* ds, int n, const char* tenFileOut) {
    FILE* f = fopen(tenFileOut, "w");
    if (!f) {
        printf("Khong mo duoc file ghi.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        long tongChiPhi = ds[i].soDem * ds[i].giaPhong;
        if (tongChiPhi >= 5000000) {
            fprintf(f, "%s,%s,%s,%d,%ld\n",
                    ds[i].maBooking,
                    ds[i].tenKhach,
                    ds[i].loaiPhong,
                    ds[i].soDem,
                    ds[i].giaPhong);
        }
    }

    fclose(f);
}
int main() {
    int n;
    DatPhong* ds = docFile("bookings.txt", &n);
    if (!ds) return 1;

    long tongDoanhThu = tinhTongDoanhThu(ds, n);
    printf("Tong doanh thu: %ld VND\n", tongDoanhThu);

    ghiVipCustomers(ds, n, "vip_customers.txt");

    free(ds);
    return 0;
}

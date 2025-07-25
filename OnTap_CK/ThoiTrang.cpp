// ĐỀ ÔN TẬP SỐ 6 - THỜI TRANG
// CÂU 2: CLO (5.0 điểm)
// Cho tập tin fashion.txt chứa thông tin sản phẩm thời trang theo cấu trúc: Mã SP, Tên sản 
// phẩm, Size, Màu sắc, Giá bán
// SP001,Ao somi nam,M,Trang,450000
// SP002,Quan jeans nu,S,Xanh,320000
// SP003,Vay cong so,L,Den,280000
// SP004,Ao khoac nam,XL,Nau,520000
// SP005,Giay sneaker,42,Trang,180000
// Thực hiện các yêu cầu sau: 
// a) Khai báo cấu trúc ThoiTrang phù hợp. (1 điểm) 
typedef struct {
    char maSP[10];       // 0.2 điểm
    char tenSP[50];      // 0.2 điểm
    char size[10];       // 0.2 điểm
    char mauSac[20];     // 0.2 điểm
    long giaBan;         // 0.2 điểm
} ThoiTrang;

// b) Viết hàm đọc dữ liệu và lưu vào mảng động. (2 điểm) 
int docFile(ThoiTrang **ds, const char *tenFile) {
    FILE *f = fopen(tenFile, "r"); // 0.5 điểm
    if (f == NULL) {
        printf("Khong the mo file %s\n", tenFile);
        return 0;
    }

    *ds = (ThoiTrang*)malloc(100 * sizeof(ThoiTrang)); // 0.25 điểm
    int n = 0;
    char line[200];

    while (fgets(line, sizeof(line), f)) { // 1.0 điểm
        char *token = strtok(line, ",");
        strcpy((*ds)[n].maSP, token);

        token = strtok(NULL, ",");
        strcpy((*ds)[n].tenSP, token);

        token = strtok(NULL, ",");
        strcpy((*ds)[n].size, token);

        token = strtok(NULL, ",");
        strcpy((*ds)[n].mauSac, token);

        token = strtok(NULL, ",\n");
        (*ds)[n].giaBan = atol(token);

        n++;
    }

    fclose(f); // 0.25 điểm
    return n;
}

// c) Viết hàm đếm số lượng sản phẩm theo màu sắc được nhập từ bàn phím. (1 điểm) 
int demTheoMauSac(ThoiTrang *ds, int n) {
    char mauTim[20];
    int count = 0;

    // Nhập màu (0.25 điểm)
    printf("Nhap mau sac can tim: ");
    scanf("%s", mauTim);

    // Đếm (0.5 điểm)
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].mauSac, mauTim) == 0) {
            count++;
        }
    }

    // In kết quả (0.25 điểm)
    printf("Co %d san pham co mau %s\n", count, mauTim);
    return count;
}

// d) Viết hàm tìm sản phẩm có giá cao nhất và thấp nhất, ghi vào file price_range.txt. (1 
// điểm)
void ghiFilePriceRange(ThoiTrang *ds, int n) {
    if (n == 0) return;

    ThoiTrang max = ds[0], min = ds[0];

    // Tìm sản phẩm cao nhất & thấp nhất (0.5 điểm)
    for (int i = 1; i < n; i++) {
        if (ds[i].giaBan > max.giaBan) {
            max = ds[i];
        }
        if (ds[i].giaBan < min.giaBan) {
            min = ds[i];
        }
    }

    // Ghi vào file (0.5 điểm)
    FILE *f = fopen("price_range.txt", "w");
    if (f != NULL) {
        fprintf(f, "San pham co gia cao nhat:\n%s,%s,%s,%s,%ld\n",
                max.maSP, max.tenSP, max.size, max.mauSac, max.giaBan);

        fprintf(f, "San pham co gia thap nhat:\n%s,%s,%s,%s,%ld\n",
                min.maSP, min.tenSP, min.size, min.mauSac, min.giaBan);

        fclose(f);
    }
}

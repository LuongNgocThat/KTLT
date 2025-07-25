// ĐỀ ÔN TẬP SỐ 2 - GIÁO DỤC
// Cho tập tin students.txt chứa thông tin sinh viên theo cấu trúc: Mã SV, Họ tên, Lớp, Điểm 
// TB, Xếp loại
// SV001,Nguyen Van A,CNTT01,8.5,Gioi
// SV002,Tran Thi B,CNTT02,6.8,Kha
// SV003,Le Van C,CNTT01,9.2,Xuat sac
// SV004,Pham Thi D,CNTT03,5.5,Trung binh
// SV005,Hoang Van E,CNTT02,7.8,Kha
// Thực hiện các yêu cầu sau: 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// a) Khai báo cấu trúc SinhVien phù hợp. (1 điểm) 
typedef struct {
    char maSV[10];       // 0.2 điểm
    char hoTen[50];      // 0.2 điểm
    char lop[20];        // 0.2 điểm
    float diemTB;        // 0.2 điểm
    char xepLoai[20];    // 0.2 điểm
} SinhVien;

// b) Viết hàm đọc dữ liệu và lưu vào mảng động. (2 điểm) 


int docFile(SinhVien **sv, const char *tenFile) {
    // Mở file (0.5 điểm)
    FILE *f = fopen(tenFile, "r");
    if (f == NULL) {
        printf("Khong the mo file %s\n", tenFile);
        return 0;
    }

    // Cấp phát bộ nhớ (0.25 điểm)
    *sv = (SinhVien*)malloc(100 * sizeof(SinhVien));
    int n = 0;
    char line[200];

    // Đọc dữ liệu (1 điểm)
    while (fgets(line, sizeof(line), f)) {
        char *token = strtok(line, ",");
        strcpy((*sv)[n].maSV, token);

        token = strtok(NULL, ",");
        strcpy((*sv)[n].hoTen, token);

        token = strtok(NULL, ",");
        strcpy((*sv)[n].lop, token);

        token = strtok(NULL, ",");
        (*sv)[n].diemTB = atof(token);

        token = strtok(NULL, ",\n");
        strcpy((*sv)[n].xepLoai, token);

        n++;
    }

    // Đóng file (0.25 điểm)
    fclose(f);
    return n;
}

// c) Viết hàm tính điểm trung bình chung của tất cả sinh viên. (1 điểm) 
float tinhDiemTrungBinh(SinhVien *sv, int n) {
    float tong = 0;

    // Cộng điểm (0.5 điểm)
    for (int i = 0; i < n; i++) {
        tong += sv[i].diemTB;
    }

    float dtb = tong / n;

    // In kết quả (0.5 điểm)
    printf("Diem trung binh chung cua tat ca sinh vien: %.2f\n", dtb);
    return dtb;
}

// d) Viết hàm lọc sinh viên có điểm >= 8.0, ghi vào file excellent_students.txt theo thứ tự
// điểm giảm dần. (1 điểm)
void ghiSinhVienGioi(SinhVien *sv, int n) {
    // Lọc sinh viên có điểm >= 8.0 (0.25 điểm)
    SinhVien *gioi = (SinhVien*)malloc(n * sizeof(SinhVien));
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (sv[i].diemTB >= 8.0) {
            gioi[count++] = sv[i];
        }
    }

    // Sắp xếp theo điểm giảm dần (0.25 điểm)
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (gioi[i].diemTB < gioi[j].diemTB) {
                SinhVien tmp = gioi[i];
                gioi[i] = gioi[j];
                gioi[j] = tmp;
            }
        }
    }

    // Ghi file (0.5 điểm)
    FILE *f = fopen("excellent_students.txt", "w");
    if (f == NULL) {
        printf("Khong ghi duoc file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(f, "%s,%s,%s,%.2f,%s\n",
            gioi[i].maSV, gioi[i].hoTen, gioi[i].lop,
            gioi[i].diemTB, gioi[i].xepLoai);
    }

    fclose(f);
    free(gioi);
}
int main() {
    SinhVien *ds;
    int soLuong = docFile(&ds, "students.txt");
    if (soLuong == 0) return 1;

    tinhDiemTrungBinh(ds, soLuong);
    ghiSinhVienGioi(ds, soLuong);

    free(ds);
    return 0;
}

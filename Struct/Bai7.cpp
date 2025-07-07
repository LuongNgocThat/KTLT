// Bài tập 7: Tính toán Phân số
// Đề bài: Viết chương trình tính toán phân số:
// • Struct PhanSo có tử số và mẫu số
// • Thực hiện các phép toán cơ bản (+, -, ×, ÷)
// • Rút gọn phân số và chuyển đổi định dạng
// • So sánh và sắp xếp nhiều phân số

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tu, mau;
} PhanSo;

// Tìm UCLN
int gcd(int a, int b) {
    if (b == 0) return abs(a);
    return gcd(b, a % b);
}

// Rút gọn phân số
void rutGon(PhanSo *ps) {
    int u = gcd(ps->tu, ps->mau);
    ps->tu /= u;
    ps->mau /= u;
    if (ps->mau < 0) { // Đưa dấu âm lên tử
        ps->tu = -ps->tu;
        ps->mau = -ps->mau;
    }
}

// Cộng hai phân số
PhanSo cong(PhanSo a, PhanSo b) {
    PhanSo kq = {a.tu * b.mau + b.tu * a.mau, a.mau * b.mau};
    rutGon(&kq);
    return kq;
}

// Trừ hai phân số
PhanSo tru(PhanSo a, PhanSo b) {
    PhanSo kq = {a.tu * b.mau - b.tu * a.mau, a.mau * b.mau};
    rutGon(&kq);
    return kq;
}

// Nhân hai phân số
PhanSo nhan(PhanSo a, PhanSo b) {
    PhanSo kq = {a.tu * b.tu, a.mau * b.mau};
    rutGon(&kq);
    return kq;
}

// Chia hai phân số
PhanSo chia(PhanSo a, PhanSo b) {
    PhanSo kq = {a.tu * b.mau, a.mau * b.tu};
    rutGon(&kq);
    return kq;
}

// So sánh hai phân số: trả về -1 nếu a < b, 0 nếu a = b, 1 nếu a > b
int soSanh(PhanSo a, PhanSo b) {
    int val1 = a.tu * b.mau;
    int val2 = b.tu * a.mau;
    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}

// In phân số
void inPhanSo(PhanSo ps) {
    rutGon(&ps);
    if (ps.mau == 1)
        printf("%d", ps.tu);
    else
        printf("%d/%d", ps.tu, ps.mau);
}

int main() {
    int n;
    printf("Nhap so luong phan so: ");
    scanf("%d", &n);
    PhanSo ds[100];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d (tu mau): ", i + 1);
        scanf("%d%d", &ds[i].tu, &ds[i].mau);
        rutGon(&ds[i]);
    }

    printf("\nDanh sach phan so da rut gon:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan so %d: ", i + 1);
        inPhanSo(ds[i]);
        printf("\n");
    }

    // Thực hiện phép toán cơ bản với 2 phân số đầu tiên (nếu có)
    if (n >= 2) {
        printf("\nCong: ");
        inPhanSo(ds[0]);
        printf(" + ");
        inPhanSo(ds[1]);
        printf(" = ");
        inPhanSo(cong(ds[0], ds[1]));
        printf("\n");

        printf("Tru: ");
        inPhanSo(ds[0]);
        printf(" - ");
        inPhanSo(ds[1]);
        printf(" = ");
        inPhanSo(tru(ds[0], ds[1]));
        printf("\n");

        printf("Nhan: ");
        inPhanSo(ds[0]);
        printf(" * ");
        inPhanSo(ds[1]);
        printf(" = ");
        inPhanSo(nhan(ds[0], ds[1]));
        printf("\n");

        printf("Chia: ");
        inPhanSo(ds[0]);
        printf(" / ");
        inPhanSo(ds[1]);
        printf(" = ");
        inPhanSo(chia(ds[0], ds[1]));
        printf("\n");
    }

    // Sắp xếp tăng dần
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (soSanh(ds[i], ds[j]) > 0) {
                PhanSo t = ds[i];
                ds[i] = ds[j];
                ds[j] = t;
            }

    printf("\nDanh sach phan so tang dan:\n");
    for (int i = 0; i < n; i++) {
        inPhanSo(ds[i]);
        printf(" ");
    }
    printf("\n");

    return 0;
}
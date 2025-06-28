
	// 1. Nhap mang a co n phan tu la so nguyen duong
	// 2. Xuat mang
	// 3. Tinh tong cac phan tu cua mang
	// 4. Tim phan tu la so nguyen to
	// 5. Sap xep cac phan tu cua mang tang dan
	// 6. Sap xep cac phan tu cua mang giam dan
	// 7. Tim pham tu nho nhat
	// 8. Tim phan tu nho thu 2
	// 9. Tim pham tu lon nhat
	// 10. Tim phan tu lon thu 2

    #include <stdio.h>
#include <stdbool.h>

// 1. Nhap mang a co n phan tu la so nguyen duong
void nhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        do {
            printf("a[%d] = ", i);
            scanf("%d", &a[i]);
            if (a[i] <= 0) printf("Nhap so nguyen duong!\n");
        } while (a[i] <= 0);
    }
}

// 2. Xuat mang
void xuatMang(int a[], int n) {
    printf("Mang: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// 3. Tinh tong cac phan tu cua mang
int tongMang(int a[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++)
        tong += a[i];
    return tong;
}

// 4. Tim phan tu la so nguyen to
bool laSoNguyenTo(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
void xuatSoNguyenTo(int a[], int n) {
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < n; i++)
        if (laSoNguyenTo(a[i]))
            printf("%d ", a[i]);
    printf("\n");
}

// 5. Sap xep tang dan
void sapXepTang(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                int t = a[i]; a[i] = a[j]; a[j] = t;
            }
}

// 6. Sap xep giam dan
void sapXepGiam(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j]) {
                int t = a[i]; a[i] = a[j]; a[j] = t;
            }
}

// 7. Tim phan tu nho nhat
int timMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min) min = a[i];
    return min;
}

// 8. Tim phan tu nho thu 2
int timMin2(int a[], int n) {
    int min = timMin(a, n), min2 = 2147483647;
    for (int i = 0; i < n; i++)
        if (a[i] > min && a[i] < min2)
            min2 = a[i];
    if (min2 == 2147483647) return -1; // Không có
    return min2;
}

// 9. Tim phan tu lon nhat
int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
    return max;
}

// 10. Tim phan tu lon thu 2
int timMax2(int a[], int n) {
    int max = timMax(a, n), max2 = -2147483648;
    for (int i = 0; i < n; i++)
        if (a[i] < max && a[i] > max2)
            max2 = a[i];
    if (max2 == -2147483648) return -1; // Không có
    return max2;
}

int main() {
    int n, a[100];
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    nhapMang(a, n);
    xuatMang(a, n);
    printf("Tong cac phan tu: %d\n", tongMang(a, n));
    xuatSoNguyenTo(a, n);

    sapXepTang(a, n);
    printf("Mang sap xep tang dan: ");
    xuatMang(a, n);

    sapXepGiam(a, n);
    printf("Mang sap xep giam dan: ");
    xuatMang(a, n);

    printf("Phan tu nho nhat: %d\n", timMin(a, n));
    int min2 = timMin2(a, n);
    if (min2 == -1)
        printf("Khong co phan tu nho thu 2\n");
    else
        printf("Phan tu nho thu 2: %d\n", min2);

    printf("Phan tu lon nhat: %d\n", timMax(a, n));
    int max2 = timMax2(a, n);
    if (max2 == -1)
        printf("Khong co phan tu lon thu 2\n");
    else
        printf("Phan tu lon thu 2: %d\n", max2);

    return 0;
}



 


/*
	1. Nhap mang a co n phan tu la so nguyen duong
	2. Xuat mang
	3. Tinh tong cac phan tu cua mang
	4. Tim phan tu la so nguyen to
	5. Sap xep cac phan tu cua mang tang dan
	6. Sap xep cac phan tu cua mang giam dan
	7. Tim pham tu nho nhat
	8. Tim phan tu nho thu 25
	9. Tim pham tu lon nhat
	10. Tim phan tu lon thu 2

*/
#include <stdio.h>
#include <stdbool.h>

// ham kiem tra so nguy�n to?
bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// ham  hoan doi 2 gia tri
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a[100], n;

    // 1. nhpa vao so nguyen to
    printf("Nhap vao so phan tu cua mang: ");
    scanf("%d", &n);

    // Nhap mang
    for(int i = 0; i < n; i++) {
        printf("Nhap vao phan tu a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    // 2. Xuat mang
    printf("\nXuat mang: ");
    for(int i = 0; i < n; i++)
        printf("%d\t", a[i]);

    // 3. Tinh tong cac  phan tu?
    int tong = 0;
    for(int i = 0; i < n; i++)
        tong += a[i];
    printf("\nTong cac phan tu: %d", tong);

    // 4. tim  cac so nguyen to
    printf("\nCac so nguyen to trong mang: ");
    for(int i = 0; i < n; i++) {
        if (laSoNguyenTo(a[i]))
            printf("%d\t", a[i]);
    }

    // 5. sap xep tang dan
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if (a[i] > a[j])
                swap(&a[i], &a[j]);
        }
    }
    printf("\nMang sau khi sap xep tang dan: ");
    for(int i = 0; i < n; i++)
        printf("%d\t", a[i]);

    // 6. sap xep giam dan
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if (a[i] < a[j])
                swap(&a[i], &a[j]);
        }
    }
    printf("\nMang sau khi sap xep giam dan: ");
    for(int i = 0; i < n; i++)
        printf("%d\t", a[i]);

    // 7. tim phan tu nho nhat
    int min = a[0];
    for(int i = 1; i < n; i++)
        if (a[i] < min) 
		min = a[i];
    printf("\nPhan tu nho nhat: %d", min);

    // 8. tim phan tu nho thu 2
     int  min2 = -1;
      for (int  i = 1;i<n;i++){
      	if(a[i] != min){
	      	if( min2 == -1 || a[i] <min2)
	      	min2 =a[i];
	      }
      }
      if(min2 !=-1)
         printf("\nPhan tu nho  thu 2 la: %d",min2);
      else("\nKhong Co......");
    

    // 9. Tim phan tu lon nhat
    int max = a[0];
    for(int i = 1; i < n; i++)
        if (a[i] > max)
		 max = a[i];
    printf("\nPhan tu lon nhat: %d", max);
    

    // 10. Tim phan tu lon thu 2
    int  max2 = -1;
      for (int  i = 1;i<n;i++){
      	if(a[i] != max){
	      	if( max2 == -1 || a[i] > max2)
	      	max2 =a[i];
	      }
          
      }
      if(max2 !=-1)
         printf("\nPhan tu lon  thu 2 la: %d",max2);
      else("\nKhong Co......");
    
    
    printf("\n");
}
 


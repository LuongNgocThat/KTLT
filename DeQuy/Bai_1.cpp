
//Bài 1: Tính ước chung lớn nhất (GCD) - Thuật toán Euclid
// Đề bài: Viết hàm đệ quy gcd(a, b) tìm ước chung lớn nhất của hai số nguyên dương a và b sử
// dụng thuật toán Euclid.
// Công thức toán học:
// • gcd(a, b) = gcd(b, a mod b) nếu b ≠ 0
// • gcd(a, 0) = a
#include <stdio.h>

  int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a %b);
  }

  int main(){
    int a,b;
    printf("Nhap 2 so nguyen duong a va b:");
    scanf("%d%d", &a,&b);
    printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, gcd(a, b));
    return 0;  }



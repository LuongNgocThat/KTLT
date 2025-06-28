// Bài tập 1: Đếm số phần tử chia hết cho 3 trong mảng
// Yêu cầu: Viết hàm đệ quy CountDivisibleBy3 để đếm số phần tử trong mảng chia hết cho 3. 
// Đầu vào: Một mảng A gồm N số nguyên (N > 0).
// Đầu ra: Số lượng phần tử trong mảng chia hết cho 3.
// Ví dụ minh họa:
// •	Đầu vào: A = {3, 7, 9, 12, 5}
// •	Đầu ra: 3 (các số 3, 9, 12 chia hết cho 3)
// Gợi ý giải:
// •	Sử dụng điều kiện dừng khi đã duyệt hết mảng
// •	Kiểm tra phần tử hiện tại xem có chia hết cho 3 không
// •	Đệ quy với phần còn lại của mảng
#include <stdio.h>
int  CountDivisibleBy3(int A[], int n){
    if(n == 0)
        return 0;
    return (A[n-1] % 2 == 0 ? 1 :0)+ CountDivisibleBy3(A,n-1);
    
}
int main(){
    int A[100],n;
    printf("Nhap so phan tu mang:");
    scanf("%d",&n);
    for(int  i =0;i<n;i++){
        printf("A[%d]=",i);
        scanf("%d",&A[i]);
    }
    int result = CountDivisibleBy3(A,n);
    printf("So phan tu chia het cho 2 trong mang la: %d\n",result);
    return 0;
}
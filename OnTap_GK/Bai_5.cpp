// Bài tập 5: Sao chép các phần tử chẵn trong mảng
// Yêu cầu: Hiện thực hàm int* CopyEvenElements(int A[], int n) để sao chép tất cả các phần 
// tử có giá trị chẵn trong mảng A sang một mảng mới. Hàm trả về địa chỉ của mảng kết quả.
// Đầu vào:
// •	Mảng A gồm n phần tử số nguyên
// Ràng buộc:
// •	0 < kích thước mảng <= 10000
// Minh họa:
// •	Đầu vào: n = 6, A = {7, 4, 9, 2, 5, 8}
// •	Đầu ra: {4, 2, 8}
// •	Giải thích: Trả về địa chỉ của mảng chứa các phần tử chẵn 4, 2, 8
#include <stdio.h>
#include <stdlib.h>

// Hàm sao chép các phần tử chẵn sang mảng mới, trả về địa chỉ mảng kết quả
int* CopyEvenElements(int A[], int n, int *evenCount) {
    int *B = (int*)malloc(n * sizeof(int));
    int j = 0;
    for (int i = 0; i < n; i++)
        if (A[i] % 2 == 0)
            B[j++] = A[i];
    *evenCount = j;
    return B;
}

int main() {
    int n, A[10000];
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
    int evenCount;
    int *evenArr = CopyEvenElements(A, n, &evenCount);
    printf("Cac phan tu chan: ");
    for (int i = 0; i < evenCount; i++)
        printf("%d ", evenArr[i]);
    printf("\n");
    free(evenArr);
    return 0;
}
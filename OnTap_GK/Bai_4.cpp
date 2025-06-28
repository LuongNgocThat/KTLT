// Bài tập 4: Tìm địa chỉ của số hoàn hảo đầu tiên trong mảng
// Yêu cầu: Hiện thực hàm AddressOfPerfectEle tìm một phần tử là số hoàn hảo đầu tiên trong mảng n số nguyên. Nếu tìm thấy thì trả về 
// địa chỉ của ô nhớ chứa phần tử đó. Nếu không tìm thấy thì trả về NULL.
// Prototype: int* AddressOfPerfectEle(int A[], int n);
// Đầu vào:
// •	Một mảng số nguyên dương A với n phần tử
// Ràng buộc:
// •	0 < kích thước mảng <= 10000
// •	0 < giá trị phần tử
// Minh họa:
// •	Đầu vào: n = 5, A = {4, 6, 8, 28, 10}
// •	Đầu ra: Địa chỉ của phần tử 6 (số hoàn hảo đầu tiên trong mảng)
// Lưu ý: Số hoàn hảo là số có tổng các ước số (không kể chính nó) bằng chính nó (ví dụ: 6 = 1 + 2 + 3).
#include <stdio.h>

// Hàm kiểm tra số hoàn hảo
int isPerfect(int x) {
    int sum = 0;
    for (int i = 1; i <= x / 2; i++)
        if (x % i == 0)
            sum += i;
    return sum == x;
}

// Hàm tìm địa chỉ số hoàn hảo đầu tiên trong mảng
int* AddressOfPerfectEle(int A[], int n) {
    for (int i = 0; i < n; i++)
        if (isPerfect(A[i]))
            return &A[i];
    return NULL;
}

int main() {
    int n, A[10000];
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
    int *p = AddressOfPerfectEle(A, n);
    if (p != NULL)
        printf("So hoan hao dau tien la %d, dia chi: %p\n", *p, (void*)p);
    else
        printf("Khong co so hoan hao trong mang!\n");
    return 0;
}
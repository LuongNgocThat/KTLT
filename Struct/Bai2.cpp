// ài tập 2: Tính khoảng cách giữa hai điểm
// Đề bài: Viết chương trình:
// • Định nghĩa struct Diem có tọa độ x, y (số thực)
// • Nhập tọa độ 2 điểm A và B từ bàn phím
// • Tính và hiển thị khoảng cách giữa 2 điểm (công thức: √[(x₂-x₁)² + (y₂-y₁)²])
// • Xác định vị trí tương đối của 2 điểm (trùng nhau, nằm trên trục tọa độ, góc phần tư nào)
#include <stdio.h>
#include <math.h>

typedef struct {
    float x, y;
} Diem;

// Hàm nhập tọa độ điểm
void nhapDiem(Diem *d) {
    printf("Nhap x: ");
    scanf("%f", &d->x);
    printf("Nhap y: ");
    scanf("%f", &d->y);
}

// Hàm tính khoảng cách giữa 2 điểm
float khoangCach(Diem a, Diem b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// Hàm xác định vị trí điểm
void viTriDiem(Diem d, char ten) {
    if (d.x == 0 && d.y == 0)
        printf("Diem %c nam tai goc toa do\n", ten);
    else if (d.x == 0)
        printf("Diem %c nam tren truc Oy\n", ten);
    else if (d.y == 0)
        printf("Diem %c nam tren truc Ox\n", ten);
    else if (d.x > 0 && d.y > 0)
        printf("Diem %c nam o goc phan tu thu I\n", ten);
    else if (d.x < 0 && d.y > 0)
        printf("Diem %c nam o goc phan tu thu II\n", ten);
    else if (d.x < 0 && d.y < 0)
        printf("Diem %c nam o goc phan tu thu III\n", ten);
    else if (d.x > 0 && d.y < 0)
        printf("Diem %c nam o goc phan tu thu IV\n", ten);
}

int main() {
    Diem A, B;
    printf("Nhap toa do diem A:\n");
    nhapDiem(&A);
    printf("Nhap toa do diem B:\n");
    nhapDiem(&B);

    float kc = khoangCach(A, B);
    printf("Khoang cach giua A va B: %.4f\n", kc);

    if (A.x == B.x && A.y == B.y)
        printf("Hai diem trung nhau.\n");
    else {
        viTriDiem(A, 'A');
        viTriDiem(B, 'B');
    }

    return 0;
}
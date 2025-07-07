// ài tập 9: Xử lý Thời gian
// Đề bài: Tạo chương trình quản lý thời gian:
// • Struct ThoiGian có giờ, phút, giây
// • Nhập thời gian hiện tại và khoảng thời gian cần cộng/trừ
// • Tính toán thời gian mới và hiển thị kết quả
// • Tính khoảng cách giữa 2 thời điểm
// • Chuyển đổi giữa các định dạng thời gian khác nhau

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int gio, phut, giay;
} ThoiGian;

// Chuẩn hóa thời gian (giây, phút, giờ hợp lệ)
void chuanHoa(ThoiGian *t) {
    if (t->giay >= 60) {
        t->phut += t->giay / 60;
        t->giay %= 60;
    } else if (t->giay < 0) {
        int m = (abs(t->giay) + 59) / 60;
        t->phut -= m;
        t->giay += m * 60;
    }
    if (t->phut >= 60) {
        t->gio += t->phut / 60;
        t->phut %= 60;
    } else if (t->phut < 0) {
        int h = (abs(t->phut) + 59) / 60;
        t->gio -= h;
        t->phut += h * 60;
    }
    // Không xử lý ngày, chỉ giữ giờ >= 0
    if (t->gio < 0) t->gio = t->phut = t->giay = 0;
}

// Đổi thời gian sang tổng số giây
long toSeconds(ThoiGian t) {
    return t.gio * 3600 + t.phut * 60 + t.giay;
}

// Đổi tổng số giây sang struct ThoiGian
ThoiGian fromSeconds(long s) {
    ThoiGian t;
    t.gio = s / 3600;
    t.phut = (s % 3600) / 60;
    t.giay = s % 60;
    return t;
}

// Cộng hai thời gian
ThoiGian cong(ThoiGian a, ThoiGian b) {
    ThoiGian kq;
    kq.gio = a.gio + b.gio;
    kq.phut = a.phut + b.phut;
    kq.giay = a.giay + b.giay;
    chuanHoa(&kq);
    return kq;
}

// Trừ hai thời gian (a - b, nếu âm trả về 0:0:0)
ThoiGian tru(ThoiGian a, ThoiGian b) {
    long s1 = toSeconds(a);
    long s2 = toSeconds(b);
    if (s1 < s2) s1 = s2; // Không cho âm
    return fromSeconds(s1 - s2);
}

// Khoảng cách giữa 2 thời điểm (tính bằng giây)
long khoangCach(ThoiGian a, ThoiGian b) {
    long s1 = toSeconds(a);
    long s2 = toSeconds(b);
    return labs(s1 - s2);
}

// Hiển thị thời gian dạng hh:mm:ss
void hienThi(ThoiGian t) {
    printf("%02d:%02d:%02d", t.gio, t.phut, t.giay);
}

int main() {
    ThoiGian hienTai, khoang;
    printf("Nhap thoi gian hien tai (gio phut giay): ");
    scanf("%d%d%d", &hienTai.gio, &hienTai.phut, &hienTai.giay);
    printf("Nhap khoang thoi gian can cong/tru (gio phut giay): ");
    scanf("%d%d%d", &khoang.gio, &khoang.phut, &khoang.giay);

    ThoiGian tong = cong(hienTai, khoang);
    ThoiGian hieu = tru(hienTai, khoang);

    printf("Thoi gian sau khi cong: ");
    hienThi(tong);
    printf("\n");

    printf("Thoi gian sau khi tru: ");
    hienThi(hieu);
    printf("\n");

    // Tính khoảng cách giữa 2 thời điểm
    ThoiGian t2;
    printf("Nhap thoi diem thu hai (gio phut giay): ");
    scanf("%d%d%d", &t2.gio, &t2.phut, &t2.giay);
    long kc = khoangCach(hienTai, t2);
    printf("Khoang cach giua hai thoi diem: %ld giay\n", kc);

    // Chuyển đổi định dạng
    printf("Thoi gian hien tai (dinh dang hh:mm:ss): ");
    hienThi(hienTai);
    printf("\nTong so giay: %ld\n", toSeconds(hienTai));

    return 0;
}
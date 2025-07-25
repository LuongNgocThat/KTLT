// ĐỀ ÔN TẬP SỐ 8 - GIAO THÔNG
// CÂU 2: CLO (5.0 điểm)
// Cho tập tin vehicles.txt chứa thông tin phương tiện theo cấu trúc: Biển số, Loại xe, Hãng, 
// Năm sản xuất, Mức tiêu thụ (L/100km)
// 29A12345,Sedan,Toyota,2020,6.5
// 30B67890,SUV,Honda,2019,8.2
// 31C11111,Hatchback,Mazda,2021,5.8
// 32D22222,Pickup,Ford,2018,9.5
// 33E33333,Sedan,Hyundai,2022,6.0
// Thực hiện các yêu cầu sau: 
// a) Khai báo cấu trúc PhuongTien phù hợp. (1 điểm) 
struct PhuongTien {
    std::string bienSo;
    std::string loaiXe;
    std::string hang;
    int namSX;
    double mucTieuThu; // L/100km
};

// b) Viết hàm đọc dữ liệu từ file vào mảng động. (2 điểm) 

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void docFile(const string& tenFile, vector<PhuongTien>& ds) {
    ifstream fin(tenFile);
    if (!fin.is_open()) {
        cout << "Khong mo duoc file!\n";
        return;
    }

    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        PhuongTien pt;
        string temp;

        getline(ss, pt.bienSo, ',');
        getline(ss, pt.loaiXe, ',');
        getline(ss, pt.hang, ',');
        getline(ss, temp, ',');
        pt.namSX = stoi(temp);
        getline(ss, temp, ',');
        pt.mucTieuThu = stod(temp);

        ds.push_back(pt);
    }

    fin.close();
}

// c) Viết hàm tìm xe có mức tiêu thụ nhiên liệu thấp nhất. (1 điểm) 
PhuongTien timXeTieuThuThapNhat(const vector<PhuongTien>& ds) {
    if (ds.empty()) return {};

    PhuongTien minXe = ds[0];
    for (const auto& pt : ds) {
        if (pt.mucTieuThu < minXe.mucTieuThu) {
            minXe = pt;
        }
    }
    return minXe;
}

// d) Viết hàm thống kê số lượng xe theo hãng, ghi kết quả vào file brand_statistics.txt theo 
// định dạng (1 điểm):
#include <map>

void thongKeTheoHang(const vector<PhuongTien>& ds, const string& tenFile) {
    map<string, int> thongKe;

    for (const auto& pt : ds) {
        thongKe[pt.hang]++;
    }

    ofstream fout(tenFile);
    for (const auto& pair : thongKe) {
        fout << "Hang: " << pair.first << endl;
        fout << "So luong: " << pair.second << endl;
    }
    fout.close();
}
int main() {
    vector<PhuongTien> ds;
    docFile("vehicles.txt", ds);

    // c) In xe tiết kiệm nhiên liệu nhất
    PhuongTien tietKiem = timXeTieuThuThapNhat(ds);
    cout << "Xe tieu thu thap nhat: " << tietKiem.bienSo << " - " << tietKiem.mucTieuThu << " L/100km\n";

    // d) Ghi thống kê vào file
    thongKeTheoHang(ds, "brand_statistics.txt");

    return 0;
}

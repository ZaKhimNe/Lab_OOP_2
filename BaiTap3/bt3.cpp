#include <iostream>
#include "ThoiGian.h"

using namespace std;

int main() {
    ThoiGian t;
    t.Nhap();

    cout << "Thoi gian vua nhap: ";
    t.Xuat();

    t.TinhCongThemMotGiay();
    cout << "Sau 1 giay: ";
    t.Xuat();

    return 0;
}

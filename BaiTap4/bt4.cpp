#include <iostream>
#include "SoPhuc.h"

using namespace std;

int main() {
    SoPhuc a, b;

    cout << "Nhap so phuc thu nhat:\n";
    a.Nhap();

    cout << "Nhap so phuc thu hai:\n";
    b.Nhap();

    SoPhuc tong = a.Tong(b);
    SoPhuc hieu = a.Hieu(b);
    SoPhuc tich = a.Tich(b);

    cout << "\nTong: ";
    tong.Xuat();

    cout << "Hieu: ";
    hieu.Xuat();

    cout << "Tich: ";
    tich.Xuat();

    auto thuong = a.ThuongThuc(b);
    cout << "Thuong: ";
    cout << thuong.first;
    if (thuong.second >= 0) cout << " + " << thuong.second << "i\n";
    else cout << " - " << abs(thuong.second) << "i\n";


    return 0;
}

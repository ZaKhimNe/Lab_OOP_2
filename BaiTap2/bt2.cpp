#include <iostream>
#include "PhanSo.h"

using namespace std;

int main() {
    PhanSo a, b;
    cout << "Nhap phan so thu nhat:\n";
    a.Nhap();
    cout << "Nhap phan so thu hai:\n";
    b.Nhap();

    PhanSo T = a.tong(b);
    PhanSo H = a.hieu(b);
    PhanSo Ti = a.tich(b);
    PhanSo Th = a.thuong(b);
    cout << "Phan so thu nhat (rut gon): ";
    a.RutGon().Xuat();

    cout << "Phan so thu hai (rut gon): ";
    b.RutGon().Xuat();

    cout << "Tong: ";
    T.Xuat();
    cout << "Hieu: ";
    H.Xuat();
    cout << "Tich: ";
    Ti.Xuat();
    cout << "Thuong: ";
    Th.Xuat();
    int cmp = a.SoSanh(b);
    if (cmp == 0)
        cout << "Hai phan so bang nhau.\n";
    else if (cmp < 0)
        cout << "Phan so thu nhat < Phan so thu hai.\n";
    else
        cout << "Phan so thu nhat > Phan so thu hai.\n";

    return 0;
}

#ifndef THOIGIAN_H
#define THOIGIAN_H

#include <string>

class ThoiGian {
private:
    int iGio;
    int iPhut;
    int iGiay;

public:
    ThoiGian();

    void Nhap();
    void Xuat();
    void TinhCongThemMotGiay();
};

#endif

#ifndef PHANSO_H
#define PHANSO_H

#include <string>

class PhanSo {
private:
    std::string tuso;
    std::string mauso;

public:
    PhanSo();
    PhanSo(int tu, int mau);

    void Nhap();
    void Xuat() const;

    int getTu() const;
    int getMau() const;

    PhanSo RutGon() const;
    PhanSo tong(const PhanSo& a) const;
    PhanSo hieu(const PhanSo& a) const;
    PhanSo tich(const PhanSo& a) const;
    PhanSo thuong(const PhanSo& a) const;
    int SoSanh(const PhanSo& a) const;

private:
    int gcd(int a, int b) const;
};

#endif

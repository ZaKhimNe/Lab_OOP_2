#include "SoPhuc.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

bool isValidDouble(const std::string& str) {
    if (str.empty()) return false;

    int dotCount = 0;
    int start = (str[0] == '-') ? 1 : 0;

    if (start == 1 && str.size() == 1) return false; // chỉ dấu '-' không hợp lệ

    for (size_t i = start; i < str.size(); ++i) {
        if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1) return false;
        }
        else if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

SoPhuc::SoPhuc() : iThuc(0), iAo(0) {}

SoPhuc::SoPhuc(double thuc, double ao) : iThuc(thuc), iAo(ao) {}

void SoPhuc::Nhap() {
    std::string thucStr, aoStr;

    cout << "Nhap phan thuc: ";
    cin >> thucStr;
    while (!isValidDouble(thucStr)) {
        cout << "Khong hop le. Nhap lai phan thuc: ";
        cin >> thucStr;
    }

    cout << "Nhap phan ao: ";
    cin >> aoStr;
    while (!isValidDouble(aoStr)) {
        cout << "Khong hop le. Nhap lai phan ao: ";
        cin >> aoStr;
    }

    iThuc = stod(thucStr);
    iAo = stod(aoStr);
}

void SoPhuc::Xuat() const {
    cout << iThuc;
    if (iAo >= 0) cout << " + " << iAo << "i" << endl;
    else cout << " - " << abs(iAo) << "i" << endl;
}

SoPhuc SoPhuc::Tong(const SoPhuc& sp) const {
    return SoPhuc(iThuc + sp.iThuc, iAo + sp.iAo);
}

SoPhuc SoPhuc::Hieu(const SoPhuc& sp) const {
    return SoPhuc(iThuc - sp.iThuc, iAo - sp.iAo);
}

SoPhuc SoPhuc::Tich(const SoPhuc& sp) const {
    int thuc = iThuc * sp.iThuc - iAo * sp.iAo;
    int ao = iThuc * sp.iAo + iAo * sp.iThuc;
    return SoPhuc(thuc, ao);
}

std::pair<double, double> SoPhuc::ThuongThuc(const SoPhuc& sp) const {
    int a = iThuc;
    int b = iAo;
    int c = sp.iThuc;
    int d = sp.iAo;

    int mau = c * c + d * d;

    if (mau == 0) {
        cout << "Loi: Khong the chia cho 0 + 0i!\n";
        return { 0.0, 0.0 };
    }

    double thuc = static_cast<double>(a * c + b * d) / mau;
    double ao = static_cast<double>(b * c - a * d) / mau;

    return { thuc, ao };
}


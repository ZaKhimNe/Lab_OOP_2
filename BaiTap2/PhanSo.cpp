#include <iostream>
#include <cstdlib> // abs
#include <cctype>  // isdigit
#include "PhanSo.h"

using namespace std;

// Hàm kiểm tra chuỗi là số nguyên (cho phép dấu '-')
bool isAllDigit(const string& str) {
    if (str.empty()) return false;
    int start = 0;
    if (str[0] == '-') {
        if (str.size() == 1) return false;
        start = 1;
    }
    for (size_t i = start; i < str.size(); i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

PhanSo::PhanSo() : tuso("0"), mauso("1") {}

PhanSo::PhanSo(int tu, int mau) {
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
    tuso = to_string(tu);
    mauso = to_string(mau);
}

void PhanSo::Nhap() {
    cout << "Nhap tu so: ";
    cin >> tuso;
    while (!isAllDigit(tuso)) {
        cout << "Khong hop le. Nhap lai tu so: ";
        cin >> tuso;
    }

    cout << "Nhap mau so (khac 0): ";
    cin >> mauso;
    while (!isAllDigit(mauso) || stoi(mauso) == 0) {
        cout << "Khong hop le. Nhap lai mau so (khac 0): ";
        cin >> mauso;
    }

    int tu = stoi(tuso);
    int mau = stoi(mauso);
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
    tuso = to_string(tu);
    mauso = to_string(mau);
}

void PhanSo::Xuat() const {
    if (mauso != "1" && tuso != "0") {
        cout << tuso << "/" << mauso << endl;
    }
    else {
        cout << tuso << endl;
    }
}

int PhanSo::getTu() const { return stoi(tuso); }
int PhanSo::getMau() const { return stoi(mauso); }

int PhanSo::gcd(int a, int b) const {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

PhanSo PhanSo::RutGon() const {
    int tu = getTu();
    int mau = getMau();
    int ucln = gcd(tu, mau);
    tu /= ucln;
    mau /= ucln;
    return PhanSo(tu, mau);
}

PhanSo PhanSo::tong(const PhanSo& a) const {
    int tu = getTu() * a.getMau() + getMau() * a.getTu();
    int mau = getMau() * a.getMau();
    return PhanSo(tu, mau).RutGon();
}

PhanSo PhanSo::hieu(const PhanSo& a) const {
    int tu = getTu() * a.getMau() - getMau() * a.getTu();
    int mau = getMau() * a.getMau();
    return PhanSo(tu, mau).RutGon();
}

PhanSo PhanSo::tich(const PhanSo& a) const {
    int tu = getTu() * a.getTu();
    int mau = getMau() * a.getMau();
    return PhanSo(tu, mau).RutGon();
}

PhanSo PhanSo::thuong(const PhanSo& a) const {
    int tu1 = getTu(), mau1 = getMau();
    int tu2 = a.getTu(), mau2 = a.getMau();

    if (tu2 == 0) {
        cout << "[THUONG] Loi: chia cho 0 => Khong xac dinh!" << endl;
        return PhanSo();
    }

    if (tu1 == 0 && tu2 == 0) {
        cout << "[THUONG] Loi: 0/0 => Khong xac dinh!" << endl;
        return PhanSo();
    }

    int tu = tu1 * mau2;
    int mau = mau1 * tu2;

    if (mau == 0) {
        cout << "[THUONG] Loi: Mau = 0 => Khong xac dinh!" << endl;
        return PhanSo();
    }

    return PhanSo(tu, mau).RutGon();
}

int PhanSo::SoSanh(const PhanSo& a) const {
    int tu1 = getTu() * a.getMau();
    int tu2 = a.getTu() * getMau();

    if (tu1 < tu2) return -1;
    else if (tu1 > tu2) return 1;
    else return 0;
}

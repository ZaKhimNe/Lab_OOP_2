#include "ThoiGian.h"
#include <iostream>
#include <string>
#include <cctype>

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

ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

void ThoiGian::Nhap() {
    string gioStr, phutStr, giayStr;

    while (true) {
        cout << "Nhap gio (0-23): ";
        cin >> gioStr;
        if (!isAllDigit(gioStr) || stoi(gioStr) < 0 || stoi(gioStr) > 23) {
            cout << "Gio khong hop le. Vui long nhap lai!\n";
            continue;
        }

        cout << "Nhap phut (0-59): ";
        cin >> phutStr;
        if (!isAllDigit(phutStr) || stoi(phutStr) < 0 || stoi(phutStr) > 59) {
            cout << "Phut khong hop le. Vui long nhap lai!\n";
            continue;
        }

        cout << "Nhap giay (0-59): ";
        cin >> giayStr;
        if (!isAllDigit(giayStr) || stoi(giayStr) < 0 || stoi(giayStr) > 59) {
            cout << "Giay khong hop le. Vui long nhap lai!\n";
            continue;
        }

        iGio = stoi(gioStr);
        iPhut = stoi(phutStr);
        iGiay = stoi(giayStr);
        break;
    }
}

void ThoiGian::Xuat() {
    cout << "Thoi gian: ";
    if (iGio < 10) cout << "0";
    cout << iGio << ":";
    if (iPhut < 10) cout << "0";
    cout << iPhut << ":";
    if (iGiay < 10) cout << "0";
    cout << iGiay << endl;
}

void ThoiGian::TinhCongThemMotGiay() {
    iGiay++;
    if (iGiay >= 60) {
        iGiay = 0;
        iPhut++;
        if (iPhut >= 60) {
            iPhut = 0;
            iGio++;
            if (iGio >= 24) {
                iGio = 0;
            }
        }
    }
}


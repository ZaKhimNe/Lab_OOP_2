#include "date.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isAllDigit(const string& str) {
    if (str.empty()) return false;
    for (char ch : str) {
        if (!isdigit(ch)) return false;
    }
    return true;
}

Date::Date() : day(0), month(0), year(0) {}
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

bool Date::isLeapYear(int y) {
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

int Date::daysInMonth(int m, int y) {
    switch (m) {
    case 4: case 6: case 9: case 11: return 30;
    case 2: return isLeapYear(y) ? 29 : 28;
    default: return 31;
    }
}

void Date::input() {
    string sd, sm, sy;
    while (true) {
        cout << "Nhap ngay: ";
        cin >> sd;
        cout << "Nhap thang: ";
        cin >> sm;
        cout << "Nhap nam: ";
        cin >> sy;

        if (!isAllDigit(sd) || !isAllDigit(sm) || !isAllDigit(sy)) {
            cout << "Loi: Vui long nhap so nguyen hop le!\n";
            continue;
        }

        day = stoi(sd);
        month = stoi(sm);
        year = stoi(sy);

        if (month < 1 || month > 12) {
            cout << "Thang khong hop le!\n";
        }
        else if (day < 1 || day > daysInMonth(month, year)) {
            cout << "Ngay khong hop le!\n";
        }
        else {
            break;
        }

        cout << "Vui long nhap lai.\n";
    }
}

void Date::print() {
    cout << day << "/" << month << "/" << year << endl;
}

void Date::nextDay() {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

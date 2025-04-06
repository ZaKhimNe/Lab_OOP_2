#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int d, int m, int y);

    bool isLeapYear(int y);
    int daysInMonth(int m, int y);

    void input();
    void print();
    void nextDay();
};

#endif

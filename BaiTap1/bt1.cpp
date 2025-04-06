#include <iostream>
#include "date.h"

using namespace std;

int main() {
    Date myDate;
    myDate.input();

    Date nextDate = myDate;
    nextDate.nextDay();

    cout << "Ngay ke tiep: ";
    nextDate.print();

    return 0;
}

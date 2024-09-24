#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {

    void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const {
        char lname[31]{};
        strcpy(lname, name, 30);
        cout << "| ";
        cout.width(30);
        cout.fill(' ');
        cout.setf(ios::left);
        cout << lname << " | ";
        prnNumber(number);
        cout << " | " << cvv << " | ";
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout.width(2);
        cout << expMon << "/" << expYear << " |" << endl;
        cout.unsetf(ios::right);
    }

}
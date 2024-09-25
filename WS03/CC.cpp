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
    
    void CC::set()
    {
        name = nullptr;
        CVV = 0;
        month = 0;
        year = 0;
        creditNum = 0ull;
    }

    void CC::cleanUp()
    {
        freeMem(name);  //deallocate
        set();   //set empty state
    }

    bool CC::isEmpty() const
    {
        if (name && name[0]) { return false; } //name exit and name[0] is not empty
        return true;
    }

    void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear)
    {
        set(); //set to empty state first
        if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
            alocpy(name, cc_name); //dynamic alocate
            creditNum = cc_no;
            CVV = cvv;
            month = expMon;
            year = expYear;
        }
    }

    void CC::display() const
    {
        //if it is empty, print mess
        if (isEmpty()) { cout << "Invalid Credit Card Record\n"; }
        else {
            display(name, creditNum, year, month, CVV);  //otherwise, display CC class using private display
        }
    }

    bool CC::validate(const char* name,
        unsigned long long cardNo,
        short cvv,
        short expMon,
        short expYear)const {
        //all conditions to validate the credit card information
        if (name && name[0] && strlen(name) > 2 && (cardNo >= 4000000000000000ull && cardNo <= 4099999999999999ull) && (cvv >= 100 && cvv <= 999) && (expMon >= 1 && expMon <= 12) && (expYear >= 24 && expYear <= 32)) {
            return true;
        }

        return false;
    }

    void CC::prnNumber(unsigned long long CCnum)const {
        //format to print the number
        cout << CCnum / 1000000000000ull << " " << (CCnum / 100000000ull) - (CCnum / 1000000000000ull) * 10000 << " " << (CCnum / 10000ull) - (CCnum / 100000000ull) * 10000 << " " << CCnum - (CCnum / 10000ull) * 10000;
    }
}
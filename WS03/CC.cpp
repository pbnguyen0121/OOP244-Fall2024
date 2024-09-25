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
        //divide by 1000000000000ull to get the first 4 digits
        cout.width(4);
        cout.fill(' ');  // No need for leading zeros in the first group
        cout << CCnum / 1000000000000ull << " ";

        //get the remainder (right 12 digits) using modulus
        CCnum = CCnum % 1000000000000ull;

        //set flags for alignment and print the second group of 4 digits
        cout.fill('0');
        cout.width(4);   // Set width to 4 for the next group
        cout.setf(ios::right);  // Ensure right alignment
        cout << CCnum / 100000000ull << " ";

        //get the remainder (right 8 digits) using modulus
        CCnum = CCnum % 100000000ull;

        //print the third set of 4 digits
        cout.fill('0');
        cout.width(4);
        cout.setf(ios::right);
        cout << CCnum / 10000ull << " ";

        //print the last 4 digits
        cout.fill('0');
        cout.width(4);
        cout.setf(ios::right);
        cout << CCnum % 10000ull;
    }
}
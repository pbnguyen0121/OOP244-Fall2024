#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool() const
    {
        return m_number != 0 && m_number != -1;
    }

    Account::operator int() const
    {
        return m_number;
    }

    Account::operator double() const
    {
        return m_balance;
    }

    bool Account::operator~()const
    {
        return m_number == 0;
    }

    Account& Account::operator=(int number)
    {
        if (!this->operator bool()) { //if account is in valid state
            if (~*this) {            //if account is new
                if (number > 10000 && number < 99999) { m_number = number; }
                else { setEmpty(); }
            }
            
        }
        return *this;
    }

    Account& Account::operator=(Account& source)
    {
        if (!this->operator bool()) { //if account is in valid state
            if (~*this || source.operator bool()) {            //if account is new or the right Account operand is valid
                m_number = source.m_number;
                m_balance = source.m_balance;
                source.m_number = 0;
                source.m_balance = 0;
            }
        }
        return *this;
    }

    Account& Account::operator+=(double balance)
    {
        if (this->operator bool() && balance > 0.0) {     //valid state and positive number
            m_balance += balance;
        }
        return *this;
    }

    Account& Account::operator-=(double number)
    {
        if (this->operator bool() && number > 0.0 && this->m_balance > number ) {     //valid state and positive number
            m_balance -= number;
        }
        return *this;
        return *this;
    }

    Account& Account::operator<<(Account& source)
    {
        if (this->operator bool() && source.operator bool() && this->m_number != source.m_number && source.m_balance > 0) {
            //both Account must be in valid state and positive balance;
            m_balance += source.m_balance;
            source.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator>>(Account& source)
    {
        if (this->operator bool() && source.operator bool() && m_balance > 0.0 && source.m_balance > 0) {
            //both Account must be in valid state and positive balance;
            source.m_balance += m_balance;
            m_balance = 0.0;
        }
        return *this;
    }

    
    double operator+(const Account& left, const Account& right)
    {
        if (left.operator bool() && right.operator bool()) {
            double sum{};
            sum = left.operator double() + right.operator double();
            return sum;
        }
        return 0;
    }

    double operator+=(double& number, const Account& right)
    {
        if (right.operator bool()) {
            double sum{};
            sum = number += right.operator double();    //number += right.operator double() actually modifies number by adding the value from right to it
                                                        //The += operator updates number in place, and then sum stores the updated value of number 
            return sum;
        }
        return 0;
        
    }

}
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;

        /// <summary>
        /// returns true if the Account is valid and otherwise false. This operator can not modify the Account object.
        /// </summary>
        operator bool() const;

        /// <summary>
        /// returns the Account number. This operator can not modify the Account object.
        /// </summary>
        operator int() const;

        /// <summary>
        /// returns the balance value. This operator can not modify the Account object.
        /// </summary>
        operator double() const;

        /// <summary>
        /// This operator returns true if the Account is new or not set (i.e. if the Account number is zero)
        /// otherwise it will return false. This operator can not modify the Account object.
        /// </summary>
        /// <returns></returns>
        bool operator ~()const;

        /// <summary>
        /// set the Account number of the Account to the integer value.
        /// </summary>
        /// <param name="number"></param>
        /// <returns></returns>
        Account& operator=(int number);

        /// <summary>
        /// overload the assignment operator so a NEW Account can be set to another Account object
        /// This action should move the balance and the Account number from one Account to another
        /// </summary>
        /// <param name="source"></param>
        /// <returns></returns>
        Account& operator=(Account& source);

        /// <summary>
        /// overload the += operator to add a double value to an Account. This should act like depositing money into an Account
        /// </summary>
        /// <param name="number2"></param>
        /// <returns></returns>
        Account& operator+=(double balance);

        /// <summary>
        /// overload the -= operator to reduce an Account balance by a double value.
        /// This should act like withdrawing money from an Account
        /// </summary>
        /// <param name="number"></param>
        /// <returns></returns>
        Account& operator-=(double number);

        /// <summary>
        /// sum of balance from both account
        /// </summary>
        /// <param name="source"></param>
        /// <returns></returns>
        Account& operator<<(Account& source);

        /// <summary>
        /// same above
        /// </summary>
        /// <param name="source"></param>
        /// <returns></returns>
        Account& operator>>(Account& source);

    };


    double operator+(const Account& left, const Account& right);


    double operator+=(double& number , const Account& right);


}
#endif // SENECA_ACCOUNT_H_
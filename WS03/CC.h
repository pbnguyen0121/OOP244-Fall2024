#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
#include "cstr.h"

namespace seneca {
    class CC {
    private:
        char* name{};
        short CVV{};
        short month{};
        short year{};
        unsigned long long creditNum{};

        /// <summary>
        /// this private method to validate the credit card information received through the argument list
        /// </summary>
        /// <param name="name"></param>
        /// <param name="cardNo"></param>
        /// <param name="cvv"></param>
        /// <param name="expMon"></param>
        /// <param name="expYear"></param>
        /// <returns></returns>
        bool validate(const char* name,
            unsigned long long cardNo,
            short cvv,
            short expMon,
            short expYear)const;

        /// <summary>
        /// This function prints a 16-digit number in a set of 4-digit numbers separated by spaces.
        /// </summary>
        /// <param name="CCnum"></param>
        void prnNumber(unsigned long long CCnum)const;
        
        /// <summary>
        /// Since formatting the output using ostream is not covered yet, the private method display is provided below to be added to the CC class.
        /// </summary>
        /// <param name="name"></param>
        /// <param name="number"></param>
        /// <param name="expYear"></param>
        /// <param name="expMon"></param>
        /// <param name="cvv"></param>
        void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;

    public:

        /// <summary>
        /// Sets the object to a safe empty state by setting all the values to zero and the name pointer to nullptr
        /// </summary>
        void set();

        /// <summary>
        /// First, it will deallocate the cardholder's (using freeMem in cstr.h) name and then it will call the set() method to set the object to a safe empty state
        /// </summary>
        void cleanUp();

        /// <summary>
        /// Returns if the CC object is in a safe empty state or not; by returning true if the cardholder name pointer attribute of the object is nullptr, otherwise, it will return false
        /// </summary>
        /// <returns></returns>
        bool isEmpty() const;

        /// <summary>
        /// overloaded with five arguments
        /// </summary>
        /// <param name="cc_name"></param>
        /// <param name="cc_no"></param>
        /// <param name="cvv"></param>
        /// <param name="expMon"></param>
        /// <param name="expYear"></param>
        void set(const char* cc_name,
            unsigned long long cc_no,
            short cvv,
            short expMon = 12,
            short expYear = 24);

        /// <summary>
        /// overload with no arguments
        /// </summary>
        void display() const;

    };

}
#endif // !SENECA_CC_H_

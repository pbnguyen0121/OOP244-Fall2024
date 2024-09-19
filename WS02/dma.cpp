#include <iostream>
#include "dma.h"
using namespace std;
namespace seneca {

    void reverse()
    {
        //num is the size of array, like how many number you want to input
        size_t num{}, i{};  //i is local variable

        //array for unknown numbers from console
        double* val = nullptr;

        cout << "Enter the number of double values:\n> ";
        cin >> num;

        //dynamically allocate
        val = new double[num];

        //input double numbers
        while (i < num) {
            cout << (i + 1) << "> ";
            cin >> val[i];
            i++;
        }

        //cout(print) the values in reverse order
        for (i = num; i > 0; i--) {
            cout << val[i - 1] << endl;
        }

        //Deallocate the allocated array
        delete [] val;
        val = nullptr;
    }

    Contact* getContact()
    {
        //Creates a Contact compound type dynamically
        Contact* newContact = new Contact;

        // Get name input from the user
        cout << "Name: ";
        cin >> newContact->m_name;

        // Get last name input from the user
        cout << "Last name: ";
        cin >> newContact->m_lastname;

        // Get phone number input from the user
        cout << "Phone number: ";
        cin >> newContact->m_phoneNumber;

        // Return the address
        return newContact;
    }

    //print the contents
    void display(const Contact& C)
    {
        cout << C.m_name << " " << C.m_lastname << ", " << "+" << C.m_phoneNumber << endl;
    }

    //dealloacte the single Contact
    void deallocate(Contact* C)
    {

        //deallocates the single Contact structure pointed by the address
        delete C;
    }

    //set the names to empty C-strings and the phone number to zero
    void setEmpty(Contact& C)
    {
        C.m_phoneNumber = 0;
        C.m_name[0] = '\0';
        C.m_lastname[0] = '\0';
    }

}
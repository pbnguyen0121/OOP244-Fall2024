#include <istream>
#include "cstr.h"  
#include "Canister.h"
using namespace std;
namespace seneca {

    const double PI = 3.14159265;


    bool Canister::isEmpty() const {
        return m_contentVolume < 0.00001;
    }

    bool Canister::usable() const
    {
        return m_height >= 10 && m_height <= 40 && m_diameter >= 10 && m_diameter <= 30;
    }

    void Canister::setToUnusable() {
        freeMem(m_contentName);
        m_diameter = m_height = -1.0;
    }

    double Canister::capacity() const {
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

    bool Canister::hasSameContent(const Canister& C)const {
        return m_contentName && C.m_contentName && strcmp(m_contentName, C.m_contentName) == 0;
    }

    double Canister::volume() const {
        return m_contentVolume;
    }

    Canister::Canister()
    {
        m_contentName = nullptr;
        m_diameter = 10.0;
        m_height = 13.0;
        m_contentVolume = 0.0;
    }

    Canister::Canister(const char* contentName)
    {
        m_contentName = nullptr;        //make sure set it to null or the code will never run
        m_diameter = 10.0;
        m_height = 13.0;
        m_contentVolume = 0.0;
        alocpy(m_contentName, contentName);
    }

    Canister::Canister(double height, double diameter, const char* contentName)
    {
        m_contentName = nullptr; //make sure set it to null or the code will never run
        m_contentVolume = 0.0;
        m_height = height;
        m_diameter = diameter;
        if (usable()) {        //If the object is usable
            alocpy(m_contentName, contentName); //alocpy data
        }
    }

    Canister& Canister::clear()
    {
        freeMem(m_contentName);
        m_contentVolume = 0.0;
        return *this;
    }

    Canister& Canister::setContent(const char* contentName)
    {
        if (contentName && contentName[0] && usable()) {
            if (!(m_contentName && m_contentName[0]) || isEmpty()) {  //change && to || cause it said "OR"
                alocpy(m_contentName, contentName);
            }
            else if (strcmp(m_contentName,contentName) != 0) {  //if the contentName argument and the object’s content name are not the same
                setToUnusable();
            }
        }
        return *this;
    }

    Canister& Canister::pour(double quantity)
    {
        if (usable()) {
            if (quantity > 0 && (quantity + m_contentVolume) < capacity()) {
                m_contentVolume += quantity;
            }
            else {
                setToUnusable();
            }
        }
        return *this;
    }
    
    Canister& Canister::pour(Canister& can)
    {
        //use usable, volume, capacity, pour(double) and setContent in this logic
        //fixed: no need to create an temporary object
        if (usable()) {
            if (can.volume() > (capacity() - volume())) {
                can.m_contentVolume -= (capacity() - volume());
                m_contentVolume = capacity();
            }
            else {
                m_contentVolume += can.volume();  //add content volume to content volume of current object
                can.m_contentVolume = 0.0;
            }

            setContent(can.m_contentName);          // Set content name or render unusable
        }
        return *this;
    }

    Canister::~Canister()
    {
        freeMem(m_contentName);  //use function in cstr to solve this problem
    }

    std::ostream& Canister::display() const {
        cout.setf(ios::fixed);
        cout.precision(1);
        cout.width(7);
        cout << capacity() << "cc (";
        cout.width(4);
        cout << m_height << "x";
        cout.width(4);
        cout << m_diameter << ") Canister";
        if (!usable()) {
            cout << " is  Unusable   recycle!";
        }
        else {
            cout << " of ";
            cout.width(7);
            cout << volume() << "cc   " << (m_contentName ? m_contentName : "Sanetized and Empty");
        }
        return cout;
    }
}
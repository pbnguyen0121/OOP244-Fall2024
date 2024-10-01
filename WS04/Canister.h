#ifndef SENECA_CANISTER_H
#define SENECA_CANISTER_H
#include <iostream>
namespace seneca {
    class Canister {
        char* m_contentName;
        double m_diameter; // in centimeters 
        double m_height;   // in centimeters
        double m_contentVolume;  // in CCs


        /// <summary>
        /// renders the canister unusable by freeing the conent name memory and setting diamieter and height to -1
        /// </summary>
        void setToUnusable();
        /// <summary>
        /// Returns true if canister volume is below 0.00001
        /// </summary>
        /// <returns>true if the canister is emtpy</returns>
        bool isEmpty()const;
        /// <summary>
        /// Returns true if height and diameters are within accepable values
        /// </summary>
        /// <returns>true if canister is usable</returns>
        bool usable()const;
        /// <summary>
        /// Returns true if the conent name of the two canisters are the same
        /// </summary>
        /// <param name="C">const Canister& to compare to</param>
        /// <returns>True if the name is the same</returns>
        bool hasSameContent(const Canister& C)const;
        /// <summary>
        /// returns the capacity of the canister
        /// </summary>
        /// <returns>Capacity of Canister</returns>
        double capacity()const;
        /// <summary>
        /// Returns the content volume. Always less than capacity
        /// </summary>
        /// <returns>Conent Volume</returns>
        double volume()const;
    public:

        /// <summary>
        /// default or no argument constructor
        /// </summary>
        Canister();

        /// <summary>
        /// default with a content name only
        /// </summary>
        /// <param name="contentName"></param>
        Canister(const char* contentName);

        /// <summary>
        /// default with height, diameter, and content name (if the name is not provided, it should default to nullptr)
        /// </summary>
        /// <param name="height"></param>
        /// <param name="diameter"></param>
        /// <param name="contentName"></param>
        Canister(double height, double diameter, const char* contentName = nullptr);

        /// <summary>
        /// clears a Canister back to an empty state
        /// </summary>
        /// <returns></returns>
        Canister& clear();

        /// <summary>
        /// 
        /// </summary>
        /// <param name="contentName"></param>
        /// <returns></returns>
        Canister& setContent(const char* contentName);

        /// <summary>
        /// 
        /// </summary>
        /// <param name="quantity"></param>
        /// <returns></returns>
        Canister& pour(double quantity);

        /// <summary>
        /// 
        /// </summary>
        /// <param name="quantity"></param>
        /// <returns></returns>
        Canister& pour(Canister& can);

        ~Canister();


        std::ostream& display()const;
    };
}

#endif // !SENECA_BOX_H

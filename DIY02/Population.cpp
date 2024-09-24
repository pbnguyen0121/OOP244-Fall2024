#include <cstdio>
#include <iostream>
#include <cstring>
#include "Population.h"
#include "File.h"
#include "File.cpp"
using namespace seneca;
using namespace std;
namespace seneca {

    Population* PopulationRecorded{}; //file scope pointer to keep tracking
    int numRecords = 0;

    bool load(const char* filename)
    {
        //check if file is found
        if (!openFile(filename)) {
            cout << "Could not open data file: " << filename << endl;
            return false; //return to the system
        }

        numRecords = noOfRecords();

        PopulationRecorded = new Population[numRecords]; //allocates memory

        for (size_t i{}; i < numRecords; i++) {
            //this fscanf keep reading data in the correct format, if not, it false then return to the system
            while (!fscanf(fptr, "%3[^,],%d\n", PopulationRecorded[i].postalCode, &PopulationRecorded[i].numOfRec)) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
                return false;
            }
        }

        closeFile(); //close file after work on it
        return true;
    }

    void display()
    {
        size_t totalPopulation{};

        cout << "Postal Code: Population" << endl;
        cout << "-------------------------" << endl;
        for (size_t i{}; i < numRecords; i++) {
            cout << (i + 1) << "- " << PopulationRecorded[i].postalCode << ":  " << PopulationRecorded[i].numOfRec << endl;
            totalPopulation += PopulationRecorded[i].numOfRec;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPopulation;

    }

    void deallocateMemory()
    {
        delete[] PopulationRecorded;
        PopulationRecorded = nullptr;
    }

}
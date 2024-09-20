#ifndef SENECA_POPULATION_H_
#define SENECA_POPULATION_H_
namespace seneca {

    struct Population {
        char postalCode[4];
        int numOfRec;
    };

    /// <summary>
    /// Finds the number of records, allocates memory in the file scope pointer and then Loads the data from the file into the dynamically allocated population records, and returns true if data was successfully loaded, false otherwise
    /// </summary>
    /// <param name="filename"></param>
    bool load(const char filename[]);


    /// <summary>
    /// a function with no parameters that returns nothing and prints the report as shown in the correct output
    /// </summary>
    void display();


    /// <summary>
    /// a function with no parameters that return nothing and deallocate all dynamic memory used by the program.
    /// </summary>
    void deallocateMemory();


}
#endif // SENECA_POPULATION_H_

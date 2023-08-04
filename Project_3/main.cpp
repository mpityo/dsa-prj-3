#include "DataLoader.h"
#include "mergesort.h"
#include "quicksort.h"
#include "comparators.h"
#include <chrono>

int main(int argc, char **argv) {

    //=== INITIALIZE
    // Load Data from data.csv File
    // Amount loaded can be adjusted in DataLoader.cpp
    vector<EarthquakeData> earthquakeData = loadEarthquakeDataFromCSV("./data.csv");
    vector<EarthquakeData> earthquakeData2 = loadEarthquakeDataFromCSV("./data.csv");
    cout << "Vector 1: " << earthquakeData.size() << " records loaded." << endl;
    cout << "Vector 2: " << earthquakeData2.size() << " records loaded.\n" << endl;
    // function reference for passing into sorting classes
    function<bool(const EarthquakeData&, const EarthquakeData&, string operation, bool equals)> comparator;


    //=== GET INPUT
    // From the user
    int userChoice = 0;
    while (userChoice != -1) {
        cout << "Enter your choice for sorting: (1 for magnitude, 2 for latitude, 3 for longitude, 4 for date, ~Any other to exit): ";
        string choiceString;
        cin >> userChoice;
        switch (userChoice) {
            case 1:
                comparator = compareByMagnitude;
                choiceString = "Magnitude";
                break;
            case 2:
                comparator = compareByLatitude;
                choiceString = "Latitude";
                break;
            case 3:
                comparator = compareByLongitude;
                choiceString = "Longitude";
                break;
            case 4:
                comparator = compareByDate;
                choiceString = "Date";
                break;
            default:
                cout << "Exiting Program" << endl;
                return -1;
        }


        //=== MEASURE TIME
        // quicksort
        auto start_quick = chrono::high_resolution_clock::now();
        quickSort(earthquakeData, comparator);
        auto end_quick = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_quick = end_quick - start_quick;
        
        // mergesort
        auto start_merge = chrono::high_resolution_clock::now();
        mergeSort(earthquakeData2, comparator);
        auto end_merge = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_merge = end_merge - start_merge;


        //=== PRINT
        // the sorted data
        cout << "Quicksort took: " << elapsed_quick.count() << " seconds.\n";
        cout << "Mergesort took: " << elapsed_merge.count() << " seconds.\n\n";

        cout << "Quick Sort by " << choiceString << ":" << endl;
        for (auto i: earthquakeData) {
            i.printData();
        }
        cout << "\n\n";

        cout << "Merge Sort by " << choiceString << ":" << endl;
        for (auto i: earthquakeData2) {
            i.printData();
        }
        cout << "\n\n";
    }

    //=== END
    return 0;
}

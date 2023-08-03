#include "DataLoader.cpp"
#include "mergesort.h"
#include "quicksort.h"
#include <chrono>
//#include <QApplication>
//#include <QLabel>

int main(int argc, char **argv) {
    
    std::vector<EarthquakeData> earthquakeData = loadEarthquakeDataFromCSV("./data.csv");
    std::vector<EarthquakeData> earthquakeData2 = loadEarthquakeDataFromCSV("./data.csv");
    cout << "1: " << earthquakeData.size() << " records loaded." << endl;
    cout << "2: " << earthquakeData2.size() << " records loaded." << endl;

    // Measure time for quicksort
    auto start_quick = std::chrono::high_resolution_clock::now();
    quickSort(earthquakeData);
    auto end_quick = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_quick = end_quick - start_quick;

    // Measure time for mergesort
    auto start_merge = std::chrono::high_resolution_clock::now();
    mergeSort(earthquakeData2);
    auto end_merge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_merge = end_merge - start_merge;

    std::cout << "Quicksort took: " << elapsed_quick.count() << " seconds.\n";
    std::cout << "Mergesort took: " << elapsed_merge.count() << " seconds.\n";

    return 0;
//    QApplication app(argc, argv);
//
//    QLabel label("Hello, Qt Widgets!");
//    label.show();
//
//    return app.exec();
}

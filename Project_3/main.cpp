#include "DataLoader.h"
#include "mergesort.h"
#include "quicksort.h"
#include "comparators.h"
#include <QApplication>
#include <chrono>
#include "welcome_window.h"
#include <functional>
using std::vector;
using std::cout;
using std::cin;
using std::string;
using std::endl;

int main(int argc, char **argv) {

    //=== INITIALIZE
    // Load Data from data.csv File
    // Amount loaded can be adjusted in DataLoader.cpp
    vector<EarthquakeData> earthquakeData = loadEarthquakeDataFromCSV("../data.csv");
    vector<EarthquakeData> earthquakeData2 = loadEarthquakeDataFromCSV("../data.csv");
    cout << "Vector 1: " << earthquakeData.size() << " records loaded." << endl;
    cout << "Vector 2: " << earthquakeData2.size() << " records loaded.\n" << endl;
    // Function reference for passing into sorting classes
    std::function<bool(const EarthquakeData&, const EarthquakeData&, string operation, bool equals)> comparator;
    // GUI window
    QApplication app(argc, argv);

    // Create and show welcome window
    WelcomeWindow welcomeWindow(earthquakeData, earthquakeData, comparator);
    welcomeWindow.show();

    return app.exec();

}
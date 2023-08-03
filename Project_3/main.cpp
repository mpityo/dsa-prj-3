#include "DataLoader.cpp"
#include "mergesort.h"
//#include <QApplication>
//#include <QLabel>

int main(int argc, char **argv) {
    
    std::vector<EarthquakeData> earthquakeData = loadEarthquakeDataFromCSV("./data.csv");
    cout << earthquakeData.size() << " records loaded." << endl;

    mergeSort(earthquakeData);

    return 0;

//    Qt testing
//    QApplication app(argc, argv);
//
//    QLabel label("Hello, Qt Widgets!");
//    label.show();
//
//    return app.exec();
}

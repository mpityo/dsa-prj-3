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
    // function reference for passing into sorting classes
    std::function<bool(const EarthquakeData&, const EarthquakeData&, string operation, bool equals)> comparator;

    QApplication app(argc, argv);

    QWidget welcomeWindow;
    welcomeWindow.setFixedSize(574, 427);
    welcomeWindow.setStyleSheet("QWidget {background-image: url(../Images/bcko.png)}");

    QLabel welcomeLabel(&welcomeWindow);
    welcomeLabel.setText("Welcome to Our Application");
    QFont f("Arial", 15);
    welcomeLabel.setFont(f);
    welcomeLabel.setStyleSheet("QLabel {color : white; background: transparent}");
    welcomeLabel.move(286 - (welcomeLabel.sizeHint().width() / 2), 36);

    QPushButton welcomeButton("Start!", &welcomeWindow);
    welcomeButton.move(286 - (welcomeButton.sizeHint().width() / 2), 330);
    welcomeButton.setStyleSheet("QPushButton {background: rgb(91,10,10); border-style: outset; border-width: 1.2px; border-radius: 5px;  border-color: black; font: bold 14px; min-width: 3em;  padding: 6px;}");

    QObject::connect(&welcomeButton, &QPushButton::clicked, [&]() {
        QWidget* earthquakeWindow = new QWidget;
        earthquakeWindow->setFixedSize(574, 427);
        earthquakeWindow->setStyleSheet("QWidget {background-image: url(../Images/bcko.png)}");

        QLabel* earthquakeLabel = new QLabel("Comparison between Quick Sort and Merge Sort");
        earthquakeLabel->setFont(f);
        earthquakeLabel->setStyleSheet("QLabel {color : white; background: transparent}");
        earthquakeLabel->move(286- ((earthquakeWindow->width() - earthquakeLabel->sizeHint().width()) / 2), 10);

        QHBoxLayout* buttonLayout = new QHBoxLayout;

        QPushButton* dateSort = new QPushButton("Date");
        dateSort->setStyleSheet("QPushButton {background: rgb(91,10,10); border-style: outset; border-width: 1.2px; border-radius: 5px;  border-color: black; font: bold 14px; min-width: 3em;  padding: 6px;}");

        QObject::connect(dateSort, &QPushButton::clicked, [&]() {
            comparator = compareByDate;
            string choiceString = "Date";

            // quicksort
            auto start_quick = std::chrono::high_resolution_clock::now();
            quickSort(earthquakeData, comparator);
            auto end_quick = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_quick = end_quick - start_quick;

            // mergesort
            auto start_merge = std::chrono::high_resolution_clock::now();
            mergeSort(earthquakeData2, comparator);
            auto end_merge = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_merge = end_merge - start_merge;

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

        });
        buttonLayout->addWidget(dateSort);

        QPushButton* magnitudeSort = new QPushButton("MagnitudeSort");
        magnitudeSort->setStyleSheet("QPushButton {background: rgb(91,10,10); border-style: outset; border-width: 1.2px; border-radius: 5px;  border-color: black; font: bold 14px; min-width: 3em;  padding: 6px;}");
        QObject::connect(magnitudeSort, &QPushButton::clicked, [&]() {
            comparator = compareByMagnitude;
            string choiceString = "Magnitude";
            // quicksort
            auto start_quick = std::chrono::high_resolution_clock::now();
            quickSort(earthquakeData, comparator);
            auto end_quick = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_quick = end_quick - start_quick;

            // mergesort
            auto start_merge = std::chrono::high_resolution_clock::now();
            mergeSort(earthquakeData2, comparator);
            auto end_merge = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_merge = end_merge - start_merge;

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
        });
        buttonLayout->addWidget(magnitudeSort);

        QPushButton* longitudeSort = new QPushButton("Longitude");
        longitudeSort->setStyleSheet("QPushButton {background: rgb(91,10,10); border-style: outset; border-width: 1.2px; border-radius: 5px;  border-color: black; font: bold 14px; min-width: 3em;  padding: 6px;}");
        QObject::connect(longitudeSort, &QPushButton::clicked, [&]() {
            comparator = compareByLongitude;
            string choiceString = "Longitude";

            // quicksort
            auto start_quick = std::chrono::high_resolution_clock::now();
            quickSort(earthquakeData, comparator);
            auto end_quick = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_quick = end_quick - start_quick;

            // mergesort
            auto start_merge = std::chrono::high_resolution_clock::now();
            mergeSort(earthquakeData2, comparator);
            auto end_merge = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_merge = end_merge - start_merge;
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
        });

        buttonLayout->addWidget(longitudeSort);

        QPushButton* latitudeSort = new QPushButton("Latitude");
        latitudeSort->setStyleSheet("QPushButton {background: rgb(91,10,10); border-style: outset; border-width: 1.2px; border-radius: 5px;  border-color: black; font: bold 14px; min-width: 3em;  padding: 6px;}");
        QObject::connect(latitudeSort, &QPushButton::clicked, [&]() {
            comparator = compareByLatitude;
            string choiceString = "Latitude";

            // quicksort
            auto start_quick = std::chrono::high_resolution_clock::now();
            quickSort(earthquakeData, comparator);
            auto end_quick = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_quick = end_quick - start_quick;

            // mergesort
            auto start_merge = std::chrono::high_resolution_clock::now();
            mergeSort(earthquakeData2, comparator);
            auto end_merge = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_merge = end_merge - start_merge;

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
        });
        buttonLayout->addWidget(latitudeSort);

        QVBoxLayout* mainLayout = new QVBoxLayout;
        mainLayout->addWidget(earthquakeLabel);
        mainLayout->addSpacing(500);
        mainLayout->addLayout(buttonLayout);
        earthquakeLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        earthquakeWindow->setLayout(mainLayout);
        earthquakeWindow->show();

        welcomeWindow.close();
    });

    welcomeWindow.show();
    return app.exec();



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
        auto start_quick = std::chrono::high_resolution_clock::now();
        quickSort(earthquakeData, comparator);
        auto end_quick = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_quick = end_quick - start_quick;

        // mergesort
        auto start_merge = std::chrono::high_resolution_clock::now();
        mergeSort(earthquakeData2, comparator);
        auto end_merge = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_merge = end_merge - start_merge;


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

    // gui

}
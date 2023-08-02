
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "EarthquakeData.h"

using namespace std;

int RECORDS_TO_LOAD = 50;

vector<string> splitString(const string& input, char delimiter) {
    vector<string> tokens;
    stringstream ss(input);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<EarthquakeData> loadEarthquakeDataFromCSV(const string& filename) {
    vector<EarthquakeData> dataObjects;
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file: " << filename << endl;
        return dataObjects;
    }

    // Read the header line to validate the order of columns
    string header;
    getline(inFile, header);

    const string expectedHeader = "Time,Date,Year,Month,Day,Hour,Minutes,Seconds,Latit,Longit,Url,Magnitude";
    if (header != expectedHeader) {
        cout << "Invalid header format" << endl;
        return dataObjects;
    }

    // Read data lines and create EarthquakeData objects
    while (inFile) {
        string line;
        if (!getline(inFile, line))
            break;

        // Use string stream to split the line into individual values
        vector<string> values = splitString(line, ',');
        if (values.size() != 12) {
            cout << "Invalid number of values" << endl;
            continue;
        }

        // Parse values and create an EarthquakeData object
        string time = values[0];
        string dateStr = values[1];
        int year = stoi(values[2]);
        int month = stoi(values[3]);
        int day = stoi(values[4]);
        int hour = stoi(values[5]);
        int minutes = stoi(values[6]);
        int seconds = stoi(values[7]);
        float latit = stof(values[8]);
        float longit = stof(values[9]);
        string url = values[10];
        double magnitude = stod(values[11]);

        EarthquakeData data(time, dateStr, year, month, day, hour, minutes, seconds, latit, longit, url, magnitude);
        dataObjects.push_back(data);

        // only load how many we want to test
        if (dataObjects.size() == RECORDS_TO_LOAD)
            inFile.close();
    }

//    inFile.close();
    return dataObjects;
}

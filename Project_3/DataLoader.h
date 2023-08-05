#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "EarthquakeData.h"



int RECORDS_TO_LOAD = 50000;

std::vector<std::string> splitString(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<EarthquakeData> loadEarthquakeDataFromCSV(const std::string& filename) {
    std::vector<EarthquakeData> dataObjects;
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cout << "Error opening file: " << filename << std::endl;
        return dataObjects;
    }

    // Read the header line to validate the order of columns
    std::string header;
    getline(inFile, header);

    const std::string expectedHeader = "Time,Date,Year,Month,Day,Hour,Minutes,Seconds,Latit,Longit,Url,Magnitude";
    if (header != expectedHeader) {
        std::cout << "Invalid header format" << std::endl;
        return dataObjects;
    }

    // Read data lines and create EarthquakeData objects
    while (inFile) {
        std::string line;
        if (!getline(inFile, line))
            break;

        // Use string stream to split the line into individual values
        std::vector<std::string> values = splitString(line, ',');
        if (values.size() != 12) {
            std::cout << "Invalid number of values" << std::endl;
            continue;
        }

        // Parse values and create an EarthquakeData object
        std::string time = values[0];
        std::string dateStr = values[1];
        int year = stoi(values[2]);
        int month = stoi(values[3]);
        int day = stoi(values[4]);
        int hour = stoi(values[5]);
        int minutes = stoi(values[6]);
        int seconds = stoi(values[7]);
        float latit = stof(values[8]);
        float longit = stof(values[9]);
        std::string url = values[10];
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

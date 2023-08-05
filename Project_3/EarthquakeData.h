#pragma once
#include <string>

class EarthquakeData {
public:
    // Constructor
    EarthquakeData(const std::string& time, const std::string& dateStr, int year, int month, int day,
                   int hour, int minutes, int seconds, float latit, float longit,
                   const std::string& url, double magnitude);
    EarthquakeData();

    // Getters
    std::string getTime() const;
    std::string getDateStr() const;
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinutes() const;
    int getSeconds() const;
    float getLatitude() const;
    float getLongitude() const;
    std::string getURL() const;
    double getMagnitude() const;

    // Operations
    void printData();

    std::string toString();

private:
    std::string _time;
    std::string _dateStr;
    int _year;
    int _month;
    int _day;
    int _hour;
    int _minutes;
    int _seconds;
    float _latit;
    float _longit;
    std::string _url;
    double _magnitude;

};

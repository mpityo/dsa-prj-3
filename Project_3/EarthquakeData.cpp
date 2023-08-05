#include <iostream>
#include "EarthquakeData.h"
#include <functional>
#include <sstream>

// Constructor
EarthquakeData::EarthquakeData(const std::string& time, const std::string& dateStr, int year, int month, int day,
                               int hour, int minutes, int seconds, float latit, float longit,
                               const std::string& url, double magnitude)
    : _time(time), _dateStr(dateStr), _year(year), _month(month), _day(day),
      _hour(hour), _minutes(minutes), _seconds(seconds), _latit(latit), _longit(longit),
      _url(url), _magnitude(magnitude) {}
EarthquakeData::EarthquakeData()
    : _time(""), _dateStr(""), _year(-1), _month(-1), _day(-1), _hour(-1), _minutes(-1),
      _seconds(-1), _latit(-1), _longit(-1), _url(""), _magnitude(-1.0) {}

// Getters
std::string EarthquakeData::getTime() const {
    return _time;
}

std::string EarthquakeData::getDateStr() const {
    return _dateStr;
}

int EarthquakeData::getYear() const {
    return _year;
}

int EarthquakeData::getMonth() const {
    return _month;
}

int EarthquakeData::getDay() const {
    return _day;
}

int EarthquakeData::getHour() const {
    return _hour;
}

int EarthquakeData::getMinutes() const {
    return _minutes;
}

int EarthquakeData::getSeconds() const {
    return _seconds;
}

float EarthquakeData::getLatitude() const {
    return _latit;
}

float EarthquakeData::getLongitude() const {
    return _longit;
}

std::string EarthquakeData::getURL() const {
    return _url;
}

double EarthquakeData::getMagnitude() const {
    return _magnitude;
}

long EarthquakeData::getDateNumber() const {
    int a = (14 - _month) / 12;
    int y = _year + 4800 - a;
    int m = _month + 12 * a - 3;
    return _day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}

// Operations
void EarthquakeData::printData() {
    std::cout << "Magnitude: " << _magnitude << std::endl;
    std::cout << "Date: " << _dateStr << std::endl;
    std::cout << "Latitude: " << _latit << ", Longitude: " << _longit << std::endl;
    std::cout << "URL: " << _url << std::endl;
}

std::string EarthquakeData::toString() {
    std::ostringstream ss;
    ss.precision(2);
    ss<<std::fixed;
    ss << _magnitude << "\t\t";
    ss.precision(4);
    ss << _latit << "\t\t";
    ss << _longit << "\t\t";
    ss << _dateStr << "\n";
    return ss.str();
}
#include "EarthquakeData.h"

// Constructor
EarthquakeData::EarthquakeData(const std::string& time, const std::string& dateStr, int year, int month, int day,
                               int hour, int minutes, int seconds, float latit, float longit,
                               const std::string& url, double magnitude)
    : _time(time), _dateStr(dateStr), _year(year), _month(month), _day(day),
      _hour(hour), _minutes(minutes), _seconds(seconds), _latit(latit), _longit(longit),
      _url(url), _magnitude(magnitude) {}

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

// Setters
void EarthquakeData::setTime(const std::string& time) {
    _time = time;
}

void EarthquakeData::setDateStr(const std::string& dateStr) {
    _dateStr = dateStr;
}

void EarthquakeData::setYear(int year) {
    _year = year;
}

void EarthquakeData::setMonth(int month) {
    _month = month;
}

void EarthquakeData::setDay(int day) {
    _day = day;
}

void EarthquakeData::setHour(int hour) {
    _hour = hour;
}

void EarthquakeData::setMinutes(int minutes) {
    _minutes = minutes;
}

void EarthquakeData::setSeconds(int seconds) {
    _seconds = seconds;
}

void EarthquakeData::setLatitude(float latit) {
    _latit = latit;
}

void EarthquakeData::setLongitude(float longit) {
    _longit = longit;
}

void EarthquakeData::setURL(const std::string& url) {
    _url = url;
}

void EarthquakeData::setMagnitude(double magnitude) {
    _magnitude = magnitude;
}

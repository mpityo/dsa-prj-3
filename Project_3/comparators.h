// Use these to compare complex data within the EarthquakeData class based on user input
// These will be passed to the sorting functions
// =======
// Comparison can be either "less" or "greater"
// Equal is true if the comparison is "equal to" and false if it's just less than or greater than

bool compareByMagnitude(const EarthquakeData& a, const EarthquakeData& b, const std::string& comparison, bool equal) {
    if (comparison == "less") {
        if (equal)
            return a.getMagnitude() <= b.getMagnitude();
        else
            return a.getMagnitude() < b.getMagnitude();
    } else {
        if (equal)
            return a.getMagnitude() >= b.getMagnitude();
        else
            return a.getMagnitude() > b.getMagnitude();
    }
}

bool compareByLatitude(const EarthquakeData& a, const EarthquakeData& b, const std::string& comparison, bool equal) {
    if (comparison == "less") {
        if (equal)
            return a.getLatitude() <= b.getLatitude();
        else
            return a.getLatitude() < b.getLatitude();
    } else {
        if (equal)
            return a.getLatitude() >= b.getLatitude();
        else
            return a.getLatitude() > b.getLatitude();
    }
}

bool compareByLongitude(const EarthquakeData& a, const EarthquakeData& b, const std::string& comparison, bool equal) {
    if (comparison == "less") {
        if (equal)
            return a.getLongitude() <= b.getLongitude();
        else
            return a.getLongitude() < b.getLongitude();
    } else {
        if (equal)
            return a.getLongitude() >= b.getLongitude();
        else
            return a.getLongitude() > b.getLongitude();
    }
}

bool compareByDate(const EarthquakeData& a, const EarthquakeData& b, const std::string& comparison, bool equal) {
    if (comparison == "less") {
        if (equal)
            return a.getDateStr() <= b.getDateStr();
        else
            return a.getDateStr() < b.getDateStr();
    } else {
        if (equal)
            return a.getDateStr() >= b.getDateStr();
        else
            return a.getDateStr() > b.getDateStr();
    }
}

bool compareByMagnitude(const EarthquakeData& a, const EarthquakeData& b, string comparison, bool equal) {
    if (comparison == "less")
        if (equal)
            return a.getMagnitude() <= b.getMagnitude();
        else
            return a.getMagnitude() < b.getMagnitude();
    else
        if (equal)
            return a.getMagnitude() >= b.getMagnitude();
        else
            return a.getMagnitude() > b.getMagnitude();

}

bool compareByLatitude(const EarthquakeData& a, const EarthquakeData& b, string comparison, bool equal) {
    if (comparison == "less")
        if (equal)
            return a.getLatitude() <= b.getLatitude();
        else
            return a.getLatitude() < b.getLatitude();
    else
    if (equal)
        return a.getLatitude() >= b.getLatitude();
    else
        return a.getLatitude() > b.getLatitude();
}

bool compareByLongitude(const EarthquakeData& a, const EarthquakeData& b, string comparison, bool equal) {
    if (comparison == "less")
        if (equal)
            return a.getLongitude() <= b.getLongitude();
        else
            return a.getLongitude() < b.getLongitude();
    else
    if (equal)
        return a.getLongitude() >= b.getLongitude();
    else
        return a.getLongitude() > b.getLongitude();
}

bool compareByDate(const EarthquakeData& a, const EarthquakeData& b, string comparison, bool equal) {
    if (comparison == "less")
        if (equal)
            return a.getDateStr() <= b.getDateStr();
        else
            return a.getDateStr() < b.getDateStr();
    else
    if (equal)
        return a.getDateStr() >= b.getDateStr();
    else
        return a.getDateStr() > b.getDateStr();
}

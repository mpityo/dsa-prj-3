#include "DataLoader.cpp"

int main(int argc, char **argv) {
    
    std::vector<EarthquakeData> earthquakeData = loadEarthquakeDataFromCSV("../data.csv");
    cout << earthquakeData.size() << " records loaded." << endl;

    return 0;
}

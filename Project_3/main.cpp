#include "Bridges.h"
#include "Secrets.h"
#include "DataSource.h"
#include "data_src/EarthquakeUSGS.h"

using namespace bridges;

int MAX_AMOUNT = 1;

int main(int argc, char **argv) {
    // create Bridges object
    Bridges bridges (1, username, apiKey);
    // set title
    bridges.setTitle("Accessing USGIS Earthquake Data (USGIS Data)");

    // read the earth quake  data
    DataSource ds (&bridges);
    vector<EarthquakeUSGS> eq_list = ds.getEarthquakeUSGSData(MAX_AMOUNT);

    // print the first quake record
    cout << "Earthquake 0:" << endl;
    cout << "\tMagnitude: " << eq_list[0].getMagnitude() << endl
        << "\tDate: " << eq_list[0].getDateStr() << endl
        << "\tLocation: " <<  eq_list[0].getLocation() << endl
        << "\tLat/Long: "  << eq_list[0].getLatit() << "," <<
        eq_list[0].getLongit() << endl;

    return 0;
}

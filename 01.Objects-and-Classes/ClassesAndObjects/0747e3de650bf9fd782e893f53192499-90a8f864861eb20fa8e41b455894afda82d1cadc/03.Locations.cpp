#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class GeoLoc {

    string lat, lng;

    public:

        GeoLoc() {}

        GeoLoc(const string & lat, const string & lng)
            : lat(lat), 
              lng(lng) 
        {}

        string toString() {
            return lat + ',' + lng;
        }

        bool compare(const GeoLoc & other) {
            return this->lat == other.lat && this->lng == other.lng;
        }

};

class Location {

    GeoLoc loc;
    string name;
    
    public:

        Location() {};

        Location(istream & istr) {

            string lat;
            string lng;
    
            getline(istr, name, ',');
            getline(istr, lat, ',');
            istr >> lng;
    
            loc = GeoLoc(lat, lng);
        }

        string toString() {
            return name + ',' + loc.toString();
        }

        string getName() { return name; }
        GeoLoc getLoc() { return loc; }
};

typedef vector < Location > LocationsVector;
LocationsVector locations;

void printByCoords(const GeoLoc & coordinates) {

    LocationsVector::iterator itCurr = locations.begin();

    while(itCurr != locations.end()) {

        if (itCurr->getLoc().compare(coordinates))
            cout << itCurr->toString() << endl;

        itCurr++;
    }

}

void printByName(const string & name) {

    LocationsVector::iterator itCurr = locations.begin();

    while(itCurr != locations.end()) {
        if (itCurr->getName() == name) {
            cout << itCurr->toString() << endl;
            return;
        }
        itCurr++;
    }
}

int main(void) {

    // "Sofia,42.70,23.33"

    while(true) {

        string buffer;
        getline(cin, buffer);
        if (buffer == ".")
            break;

        istringstream istr(buffer);

        locations.push_back(Location(istr));
    }

    while(true) {

        string line;
        getline(cin, line);
        if (line == ".")
            break;

        istringstream istr(line);

        if (isdigit(line[0])) {
            // pair of coordinates

            string lat, lng;
            istr >> lat >> lng;

            printByCoords(GeoLoc(lat, lng));

        } else {
            string name;
            istr >> name;

            printByName(name);
        }

    }

    return 0;
}

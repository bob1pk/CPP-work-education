#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(void) {

    map<string, // Contients
        map<string, // Countries
            set<string> > > data; // Cities

    //map<string, map<string, set<string> > > data;

    int N;
    cin >> N;

    while(N--) {
        string continent, country, city;

        cin >> continent >> country >> city;

        data[continent] // => returns map<Countries, set<Cities>
            [country] // => returns set<Cities>
                .insert(city); // => inserts the city in the set
    }

    for(auto itCont = data.begin(); itCont != data.end(); itCont++) {
        cout << itCont->first << ':' << endl;

        map<string, set<string> > & countries = itCont->second;

        for(auto itCountries = countries.begin(); itCountries != countries.end(); itCountries++) {
            cout << "  " << itCountries->first << " -> ";

            set<string> & cities = itCountries->second;
            bool bFirst = true;
            for(auto itS = cities.begin(); itS != cities.end(); itS++) {
                if (!bFirst) 
                    cout << ", ";
                else 
                    bFirst = false;
                cout << *itS; 
            }
            cout << endl;
        }

    }

    return 0;
}
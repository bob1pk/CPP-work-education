#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip> // За setprecision
using namespace std;

int main()
{
    map<string, // Contients
    map<string, // Countries
        set<string> > > data; // Cities
    int num;
    cin>>num;
    while(num)
    {string continent,country,capital;
        cin>>continent>>country>>capital;
        data[continent][country].insert(capital);

        num--;
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
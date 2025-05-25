#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(void) {

    set<string> cars;

    while(true) {
        string cmd;

        cin >> cmd;

        string plate;
        switch(cmd[0]) {
            case 'I':
            case 'O':
                cin >> plate;
                if (cmd[0] == 'I') {
                    // car enters the parking
                    cars.insert(plate);
                } else {
                    // car exits the parking
                    cars.erase(plate);
                }
                break;
            case 'E':
                if (cars.size() == 0)
                    cout << "Parking Lot is Empty" << endl;
                else
                    for(string car : cars)
                        cout << car << endl;
                return 0;
        }
    }

    return 0;
}
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    vector<string> names;

    int N;
    cin >> N;

    while(N--) {
        string name;
        cin >> name;

        if (find(names.begin(), names.end(), name) == names.end()) {
            names.push_back(name);
        }
    }

    for(auto name : names) 
        cout << name << endl;

    return 0;
}
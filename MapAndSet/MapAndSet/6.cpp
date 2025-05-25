#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(void) {

    int N;
    cin >> N;

    set<string> userNames;

    while(N--) {
        string userName;
        getline(cin >> ws, userName);

        userNames.insert(userName);
    }

    for(const string & name : userNames) {
        cout << name << endl;
    }

    return 0;
}
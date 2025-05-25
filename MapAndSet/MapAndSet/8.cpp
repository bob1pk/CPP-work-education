#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(void) {

    map<int, size_t> data;

    int N;
    cin >> N;

    while(N--) {
        int number;
        cin >> number;
        data[number]++;
    }

    for(map<int, size_t>::iterator itData = data.begin(); itData != data.end(); itData++) {
        if (itData->second % 2 == 0) {
            cout << itData->first << endl;
            //return 0;
        }
    }

    return 0;
}
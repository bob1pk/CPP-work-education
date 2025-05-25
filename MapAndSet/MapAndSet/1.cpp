#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(void) {

    map<double, size_t> occurrences;
    vector<double> order;

    string buffer;
    getline(cin, buffer);
    istringstream istr(buffer);

    double number;
    while(istr >> number) {
        pair<map<double, size_t>::iterator, bool> insRes 
                = occurrences.insert({number, 1});

        if (insRes.second == true) {
            // the insert was successful -> new element
            order.push_back(number);
        } else {
            // already existing number!
            insRes. // pair, it result of `insert`
                first-> // the iterator to the actual map storage of the <K, V> pair, which corresponds to `number`
                    second++; // the number of occurrences of the `number`
        }
    }

    for(auto d : order)
        cout << d << " - " << occurrences[d] << " times" << endl;

    return 0;
}
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;


int main() {
    map<double, size_t> osc;
    vector<double> order;
    string buffer;
    getline(cin, buffer);
    istringstream istr(buffer);

    double number;
    while (istr>>number)
    {   
        auto result =osc.insert({number,1});
        if(result.second)
        {
            order.push_back(number);
        }
        else
        {
            result.first->second++;
        }


    }
    
    for(auto d : order)
        cout << d << " - " << osc[d] << " times" << endl;

    return 0;
}
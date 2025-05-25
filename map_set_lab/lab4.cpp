#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip> // За setprecision
using namespace std;

int main()
{
    set<string> data; // Cities
    vector<string>real_data;
    int num;
    cin>>num;
    while(num)
    {string name;
        cin>>name;
       auto res = data.insert(name);
        num--;
        if(res.second)
        {
            real_data.push_back(name);
        }
    }
    for(auto n:real_data)
    cout<<n<<endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {

    char buffer[10000]; // buffer for all structured data we will read!
    char *nextData = buffer;
    map<int, const char *> index;

    while(true) {
        string companyName;

        cin >> companyName;
        if (companyName == "end")
            break;

        int id;
        cin >> id;

        int * addrId = (int *)nextData;
        *addrId = id;
        nextData += sizeof(int);
        index[id] = nextData;

        for(size_t cnt = 0; cnt < companyName.size(); cnt++) {
            *nextData = companyName[cnt];
            nextData++;
        }
        *nextData = '\0';
        nextData++;
    }

    int searchId;
    cin >> searchId;

    auto found = index.find(searchId);
    if (found != index.end()) 
        cout << found->second << ' ' << found->first << endl;
    else
        cout << "[not found]" << endl;

    return 0;
}
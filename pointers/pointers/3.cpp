#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool companySort(
    const pair<const int *, const char *> a,
    const pair<const int *, const char *> b) {

    return *(a.first) < *b.first;
}

int main(void) {

    char buffer[10000]; // buffer for all structured data we will read!
    vector< pair<const int *, const char *> > index;

    char *nextData = buffer;

    while(true) {
        string companyName;
        pair<const int *, const char *> currComp;

        cin >> companyName;
        if (companyName == "end")
            break;

        int id;
        cin >> id;

        int * addrId = (int *)nextData;
        currComp.first = addrId;
        *addrId = id;
        nextData += sizeof(int);
        currComp.second = nextData;

        for(size_t cnt = 0; cnt < companyName.size(); cnt++) {
            *nextData = companyName[cnt];
            nextData++;
        }
        *nextData = '\0';
        nextData++;

        index.push_back(currComp);
    }

    sort(index.begin(), index.end(), &companySort);

    for(auto curr : index) {
        cout << curr.second << ' ' << *curr.first << endl;
    }

    return 0;
}
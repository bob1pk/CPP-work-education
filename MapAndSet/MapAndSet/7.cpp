#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void readSet(int size, set<int> & set) {
    while(size--)
    {
        int number;
        cin >> number;
        set.insert(number);
    }
}

int main(void) {

    set<int> a, b;

    int n, m;
    cin >> n >> m;

    readSet(n, a);
    readSet(m, b);

    for(int fromA : a) {
        if (b.find(fromA) != b.end())
            cout << fromA << ' ';
    }

    cout << endl;

    return 0;
}
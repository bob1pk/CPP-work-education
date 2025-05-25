#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(void) {

    int N;
    cin >> N;

    set<int> numbers;

    while(N--) {
        int number;
        cin >> number;
        auto it = numbers.find(number);
        if (it != numbers.end())
            numbers.erase(it);
        else
            numbers.insert(number);
    }

    for(int number : numbers) 
        cout << number << endl;

    return 0;
}

/*

7
1
2
3
4
3
2
1



*/
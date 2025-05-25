#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>
#include <set>

using namespace std;

int main(void) {

    map<string, vector<double> > studentData;

    int N;
    cin >> N;

    while(N--) {
        string name;
        double grade;

        cin >> name >> grade;

        (studentData[name]) // връща vector<double> за студента `name`
            .push_back(grade); // добавя във vector<double> поредната оценка `grade`
    }

    cout << fixed << setprecision(2);

    for(auto it = studentData.begin(); it!=studentData.end(); it++) {
        cout << it->first << " -> ";

        vector<double> & grades = it->second;
        double average = 0;
        for(double grade : grades) {
            cout << grade << " ";
            average += grade;
        }
        cout << "(avg: " << average / grades.size() << ')' << endl;
    }

    return 0;
}
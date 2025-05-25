#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <iomanip> // За setprecision
using namespace std;

int main()
{
    map<string,vector<double>>student_grades;
    int num;
    cin>>num;
    while(num)
    {
        string name;
        double grade;

        cin >> name >> grade;
        num--;
        student_grades[name].push_back(grade);
    }
    for(auto it = student_grades.begin(); it != student_grades.end(); it++)
    {
        cout << std::fixed << std::setprecision(2) << it->first << " -> ";

        vector<double> &copy_grades=it->second;
        double average = 0;
        for(double grade:copy_grades)
        {
            cout << grade << " ";
            average += grade;
        }
        cout << "(avg: " << average / copy_grades.size() << ')' << endl;
    }

    return 0;
}

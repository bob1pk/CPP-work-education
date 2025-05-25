#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#include <iomanip>

using namespace std;
class point
{
private:
    double p, q;

public:
    point(istream &in)
    {
        // string buf;
        // getline(in, buf);
        // istringstream istr(buf);
        in >> this->p >> this->q;
    }

    int getP() { return this->p; }

    int getQ() { return this->q; }

    double CalculateTheEuclidean(point &other)
    {
        return sqrt(pow(this->p - other.getP(), 2) + pow(this->q - other.getQ(), 2));
    }
};

int main()
{
    point p1(cin);
    point p2(cin);

    cout << fixed << setprecision(3) << p1.CalculateTheEuclidean(p2) << endl;
    return 0;
}
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#include <iomanip>

using namespace std;
class Sale
{
    string town;
    string product;
    double price;
    double quantity;

    // Sale(string town_, string product_, double price_, double quantity_) : town(town_), product(product_), price(price_), quantity(quantity_) {}
    public:
    Sale(istream &in)
    {
        in >> town >> product >> price >> quantity;
    }

    Sale() : price(0), quantity(0) {}

    double CalcSale(void)
    {
        return (this->price) * (this->quantity);
    }

    string GetTown(void) { return town; }
    string GetProduct(void) { return product; }
    double GetPrice(void) { return price; }
    double GetQuan(void) { return quantity; }
};

class Sales
{
public:
    typedef vector<Sale> SalesData;

private:
    SalesData data;

public:
    Sales(istream &istr)
    {
        size_t count;
        istr >> count;

        while (count--)
            data.push_back(Sale(istr));
    }
     SalesData getData(void) { return data; }
};

class SalesReport{
     Sales & source;

    map<string,double> reportData;
    public:
    SalesReport( Sales & source_):source(source_){
        calc();

    }

    void generate(ostream & out){
        for(pair<string,double> data : reportData)
        {    
        out<<fixed<<setprecision(2)<<data.first<< " -> " <<data.second<<endl;
        }

    }
    void calc(void)
    {
        reportData.clear();
        Sales::SalesData data = source.getData();

        for( Sale & s: data){
            reportData[s.GetTown()]+= s.CalcSale();
        }
    }

};

int main()
{
    Sales data(cin);
    SalesReport report(data);
    report.generate(cout);
    return 0;
}
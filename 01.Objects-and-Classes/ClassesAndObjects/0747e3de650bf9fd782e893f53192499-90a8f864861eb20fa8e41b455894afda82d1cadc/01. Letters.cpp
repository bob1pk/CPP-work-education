#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

class WordBox {
    // private is the default access

    private:
        set<string> words;

        void readWords(istream & input) {

            string buf;
            getline(input, buf);
        
            for(char & c : buf)
                //if ( !(c >= 'A' && c <='Z') && !(c>='a' && c <= 'z'))
                if (ispunct(c))
                    c = ' ';
        
            istringstream istr(buf);
            string tmp;
            while(istr >> tmp)
                words.insert(tmp);
        }

    public:

        WordBox(istream & istr) {
            readWords(istr);
        }

        void processChar(char c, ostream & ostr) {

            c = ::tolower(c);

            bool bFound = false;
            for(const string & curr : words) {
                string transformed = curr; 
                transform(transformed.begin(), transformed.end(), transformed.begin(), ::tolower);
                if (transformed.find(c) != string::npos) {
                    bFound = true;
                    ostr << curr << " ";
                }
            }
    
            if (!bFound)
                ostr << "---";
    
            ostr << endl;
    
        }

        void processInput(istream & istr, ostream & ostr) {

            while(true) {

                char c;
                istr >> c;
        
                if (c == '.')
                    break;
        
                processChar(c, ostr);
            }
        
        }

};

int main(void) {

    WordBox wb(cin);

    wb.processInput(cin, cout);

    return 0;
}

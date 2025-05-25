#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;
class Shifter
{
private:
    deque<string> sentence_words;

public:
    Shifter(istream &isstream)
    {
        string sentence;
        getline(isstream, sentence);

        istringstream istr(sentence);

        string word;
        while (istr >> word)
        {
            sentence_words.push_back(word);
        }
    }

    Shifter() {}

    void shift_it(void)
    {
        sentence_words.push_front(sentence_words.back());
        sentence_words.pop_back();
    }

    void print_shifter(ostream &osstream){
        while(sentence_words.size()){
            
            osstream << sentence_words.front();
            osstream << endl;
            sentence_words.pop_front();
        }
    }
};

class Sentence_Shifter
{
private:
    Shifter Sentence_whole;
    int shift_times;

public:
    Sentence_Shifter(istream &isstream)
        : Sentence_whole(isstream)
    {
        isstream >> shift_times;
    }

    void getShiftedSentence(void)
    {
        while (shift_times--)
        {
            Sentence_whole.shift_it();
        }
        Sentence_whole.print_shifter(cout);
    }
};

int main(void)
{
    Sentence_Shifter shift(cin);

    shift.getShiftedSentence();

    return 0;
}
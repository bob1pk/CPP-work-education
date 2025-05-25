#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

const size_t DIMENSION = 10;

class Board {

    char matrix[DIMENSION][DIMENSION] = {0};
    public:

        enum FieldType : char { RUST = '!', ALPAKA = '#', EMPTY = '.', TEMP_RUST = '?'};

        Board(istream & istr) {
            for(size_t row = 0; row < DIMENSION; row++)
                for(size_t col = 0; col < DIMENSION; col++)
                    istr >> matrix[row][col];
        }

        void print(ostream & ostr) {

            for(size_t row = 0; row < DIMENSION; row++) {
                for(int col = 0; col < DIMENSION; col++)
                    ostr << matrix[row][col]; 
                ostr << endl;
            }
        }

        void setCell(int row, int col, FieldType symbol) {

            if (row < 0 || col < 0 || row >= DIMENSION || col >= DIMENSION)
                return;
            
            matrix[row][col] = symbol;
        }

        void setRust(int row, int col, FieldType symbol) {

            if (row < 0 || col < 0 || row >= DIMENSION || col >= DIMENSION)
                return;
            
            if (matrix[row][col] == EMPTY)    
                matrix[row][col] = symbol;
        }

        bool hasRust(int row, int col) { return matrix[row][col] == RUST; }

        void fixTempRust(void) {
            for(int row = 0; row < DIMENSION; row++)
                for(int col = 0; col < DIMENSION; col++) 
                    if (matrix[row][col] == TEMP_RUST)
                        matrix[row][col] = RUST;
        }
};

class Rust {

    Board board;
    int ticks;

    public:

        Rust(istream & istr) 
            : board(istr) 
        {
            istr >> ticks;
        }

        void putTempRust() {

            for(int row = 0; row < DIMENSION; row++)
                for(int col = 0; col < DIMENSION; col++) 
                    if (board.hasRust(row, col)) // matrix[row][col] == RUST
                    {
                        board.setRust(row-1, col, Board::TEMP_RUST);
                        board.setRust(row+1, col, Board::TEMP_RUST);
                        board.setRust(row, col-1, Board::TEMP_RUST);
                        board.setRust(row, col+1, Board::TEMP_RUST);
                    }
        }

        void fixTempRust() {
            board.fixTempRust();        
        }

        void process(istream & istr, ostream & ostr) {
            
            for(;ticks;ticks--) {

                putTempRust();
                //cout << "----" << endl << "Tick: " << ticks << ", applied temp rust." << endl;
                //printMatrix(matrix);
                
                fixTempRust();
                //cout << "----" << endl << "Tick: " << ticks << ", fixed temp rust." << endl;
                //printMatrix(matrix);
            }
        
            board.print(ostr);
        }
        
};

int main(void) {

    Rust rust(cin);

    rust.process(cin, cout);

    return 0;
}

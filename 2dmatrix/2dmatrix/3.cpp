#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;

    cin >> N >> ws;

    vector< string > matrix(N);

    for(int r = 0; r < N; r++) {
        string curRow;
        getline(cin, curRow);
        matrix[r] = curRow;
    }

    char ch;
    cin >> ch;
    cin.ignore();

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++)
            if (ch == matrix[r][c]) {
                cout << "(" << r << ", " << c << ")" << endl;
                return 0;
            }
    }

    // not found!
    cout << ch << " does not occur in the matrix" << endl;

    return 0;
}


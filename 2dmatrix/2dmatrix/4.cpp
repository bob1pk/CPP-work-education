#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int N;

    cin >> N;

    vector< vector<int> > matrix(N, vector<int>(N) );

    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            cin >> matrix[r][c];

    int primaryDiag = 0, secondaryDiag = 0;
    for(int n = 0; n < N; n++) {
        primaryDiag += matrix[n][n];
        secondaryDiag += matrix[n][N - 1 - n];
    }

    cout << abs(primaryDiag - secondaryDiag) << endl;

    return 0;
}


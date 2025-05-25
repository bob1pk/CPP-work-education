#include <iostream>

using namespace std;

int main() {

    const int MaxRows = 20, MaxCols = 20; 

    int matrix[MaxRows][MaxCols];

    int rows, cols;

    cin >> rows >> cols;

    if (rows > MaxRows || cols > MaxCols) {
        cout << "ERROR: Too big dimensions: rows = " << rows << ", cols = " << cols << "!" << endl;
        return 1; // program ends after error
    }

    for(int r = 0; r < rows; r++)
        for(int c = 0; c < cols; c++)
            cin >> matrix[r][c];

    for(int c = 0; c < cols; c++) {
        int sum = 0;
        for(int r = 0; r < rows; r++)
            sum += matrix[r][c];
        cout << sum << endl;
    }

    return 0;
}


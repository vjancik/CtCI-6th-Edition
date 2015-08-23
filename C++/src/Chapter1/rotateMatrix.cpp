#include <iostream>
#include <string>
#include <sstream>

#include "Matrix.hpp"

using namespace std;

void printUsage (char* progName) {
    cout << "Usage: " << progName << "HEIGHT WIDTH"<< endl <<
        "Read a matrix of size HEIGHT WIDTH from standard input and return it rotated by 90 degrees." << endl;
}

void readMatrix (int** matrix) {
    string inputLine;
    int i = 0, j = 0, value;
    while (getline(cin, inputLine)) {
        istringstream istream(inputLine);;
        while (istream >> value) {
            matrix[i][j] = value;
            ++j;
        }
        j=0; ++i;
    }
}

int main (int argc, char* argv[]) {
    if (argc < 3) {
        printUsage(argv[0]);
        return 1;
    }
    int height = stoi(argv[1]);
    int width = stoi(argv[2]);
    int** matrix = Matrix::allocate_matrix(height, width);
    readMatrix(matrix);
    Matrix m(matrix, height, width);
    cout << m.rotate().toString() << endl;
    Matrix::delete_matrix(matrix, height, width);
    return 0;
}

#include <iostream>
#include <string>
#include <sstream>

#include "Matrix.hpp"

class ZeroRowsColsMatrix : public Matrix {
    private:
        void nullify_row(int** m, int row, int w) {
            for (int i = 0; i < w; ++i)
                m[row][i] = 0;
        }
        void nullify_col(int** m, int col, int h) {
            for (int i = 0; i < h; ++i)
                m[i][col] = 0;
        }
    public:
        ZeroRowsColsMatrix (int** m, int height, int width) : Matrix(m, height, width) {} 
        ZeroRowsColsMatrix zeroRowsCols() {
            int** zeroedOut = allocate_matrix(width, height);
            copy_matrix(matrix, zeroedOut, height, width);
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    if (matrix[i][j] == 0) {
                        nullify_row(zeroedOut, i, width);
                        nullify_col(zeroedOut, j, height);
                    }
                }
            }
            return ZeroRowsColsMatrix(zeroedOut, height, width);
        }
};

using namespace std;

void printUsage (char* progName) {
    cout << "Usage: " << progName << "HEIGHT WIDTH"<< endl <<
        "Read a matrix of size HEIGHT WIDTH from standard input and return" << endl <<
        "it with all rows and columns containing a 0, zeroed out." << endl;
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
    int** matrix = ZeroRowsColsMatrix::allocate_matrix(height, width);
    readMatrix(matrix);
    ZeroRowsColsMatrix m(matrix, height, width);
    cout << m.zeroRowsCols().toString() << endl;
    ZeroRowsColsMatrix::delete_matrix(matrix, height, width);
    return 0;
}

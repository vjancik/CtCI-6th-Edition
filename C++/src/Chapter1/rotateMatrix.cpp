#include <iostream>
#include <string>
#include <sstream>

#include "Matrix.hpp"

class RotationMatrix : public Matrix {
    public:
        RotationMatrix (int** m, int height, int width) : Matrix(m, height, width) {} 
        RotationMatrix rotate() {
            int** rotated;
            rotated = allocate_matrix(width, height);
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    rotated[j][height - i - 1] = matrix[i][j];
                }
            }
            return RotationMatrix(rotated, width, height);
        }
};

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
    int** matrix = RotationMatrix::allocate_matrix(height, width);
    readMatrix(matrix);
    RotationMatrix m(matrix, height, width);
    cout << m.rotate().toString() << endl;
    RotationMatrix::delete_matrix(matrix, height, width);
    return 0;
}

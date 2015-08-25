#include <iostream>
#include <string>
#include <sstream>

#include "Matrix.hpp"

using namespace std;

int** Matrix::allocate_matrix(int h, int w) {
    int** m = new int*[h];
    for (int i = 0; i < h; ++i)
        m[i] = new int[w];
    return m;
}
void Matrix::initialize_matrix(int** m, int h, int w, int val) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            m[i][j] = val;
        }
    }

}
void Matrix::copy_matrix(int** src, int** dst, int h, int w) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            dst[i][j] = src[i][j];
        }
    }
}
void Matrix::delete_matrix(int** m, int h, int w) {
    for (int i = 0; i < h; ++i)
        delete[] m[i];
    delete[] m;
}
Matrix::Matrix (int** m, int height, int width) : height(height), width(width){
    matrix = allocate_matrix(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            matrix[i][j] = m[i][j];
        }
    }
};
Matrix::~Matrix () {
    delete_matrix(matrix, height, width);
}
string Matrix::toString() {
    ostringstream ostream;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            ostream << matrix[i][j] << '\t';
        }
        if (i != height - 1) ostream << endl;
    }
    return ostream.str();
}

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

using namespace std;

class Matrix {
    int** matrix;
    int height, width;

    public:
        static int ** allocate_matrix(int h, int w);
        static void delete_matrix(int** m, int h, int w);
        int get_height() { return height; }
        int get_width() { return width; }
        
        Matrix (int** m, int height, int width);
        ~Matrix();

        Matrix rotate();
        string toString();
};

#endif

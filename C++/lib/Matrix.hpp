#ifndef MATRIX_HPP_
#define MATRIX_HPP_

using namespace std;

class Matrix {
    protected:
        int** matrix;
        int height, width;
    public:
        static int ** allocate_matrix(int h, int w);
        static void initialize_matrix(int** m, int h, int w, int value);
        static void copy_matrix(int** src, int** dst, int h, int w);
        static void delete_matrix(int** m, int h, int w);
        int get_height() { return height; }
        int get_width() { return width; }
        
        Matrix (int** m, int height, int width);
        ~Matrix();

        string toString();
};

#endif

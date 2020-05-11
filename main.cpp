#include <iostream>
#include "Matrix.cpp"

#define PRINT_MATRIX(variable) std::cout << std::string(#variable) << ": "<< std::endl<<variable << std::endl; // todo remove

using namespace std;

Matrix changeNum(Matrix m);

int main() {
    int **m1 = new int *[2];
    m1[0] = new int[2]{0, 2};
    m1[1] = new int[2]{7, 4};
    int **m2 = new int *[2];
    m2[0] = new int[2]{8, 1};
    m2[1] = new int[2]{8, 5};

    Matrix matrix1 = Matrix(2, 2, m1);
    Matrix matrix2 = Matrix(2, 2, m2);

    PRINT_MATRIX(matrix1)
    PRINT_MATRIX(&matrix2)
    Matrix matrix3 = changeNum(matrix1);
    PRINT_MATRIX(matrix3)

    PRINT_MATRIX(matrix1 + matrix2)
    PRINT_MATRIX(matrix1 - matrix2)
    PRINT_MATRIX(matrix1 * matrix2)

    return 0;
}

Matrix changeNum(Matrix m) {
    int w = m.getWidth();
    int h = m.getHeight();
    Matrix matrix = Matrix(m.getWidth(), m.getHeight());
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            int num = m[x][y];
            if (num == 0)
                matrix[x][y] = 1;
            else
                matrix[x][y] = num;
        }
    }
    return matrix;
}

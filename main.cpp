#include <iostream>
#include "Matrix.cpp"
//#include "Matrix.h"
#include "ListInt.cpp"
#include "List.cpp"

//Matrix changeNum(Matrix m);
#define PRINT_MATRIX(variable) std::cout << std::string(#variable) << ": "<< std::endl<<variable << std::endl;


int main() {
    int **m1 = new int *[2];
    m1[0] = new int[2]{0, 2};
    m1[1] = new int[2]{7, 4};
    int **m2 = new int *[2];
    m2[0] = new int[2]{8, 1};
    m2[1] = new int[2]{8, 5};

    Matrix matrix1 = Matrix(2, 2, List(2, 2, m1));
    Matrix matrix2 = Matrix(2, 2, List(2, 2, m2));

    PRINT_MATRIX(matrix1)
    PRINT_MATRIX(&matrix2)
    Matrix matrix3 = changeNum(matrix1);
    PRINT_MATRIX(matrix3)

    Matrix matrixSum = matrix1.plus(matrix2);
    PRINT_MATRIX( matrixSum )
    PRINT_MATRIX(matrix1.subtraction(matrix2))
    PRINT_MATRIX( matrix1 * matrix2 )

    return 0;
}
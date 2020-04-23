//
// Created by Michael on 09.02.2020.
//

#ifndef S2LB1_2_MATRIX_H
#define S2LB1_2_MATRIX_H


#include <ostream>
#include "ListInt.cpp"
#include "List.cpp"

class Matrix {

private:
    List array;
    int width, height;
public:

    Matrix();

    Matrix(const Matrix &m);

    Matrix(int width, int height);

    Matrix(int width, int height, int defaultValue);

    Matrix(int width, int height, List array);

    virtual ~Matrix();

    friend std::ostream &operator<<(std::ostream &os, Matrix *matrix);
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    friend std::istream &operator>>(std::istream &is, Matrix matrix);

    ListInt &operator[](int i);

    friend Matrix operator+(Matrix m1, Matrix m2);

    friend Matrix operator-(Matrix m1, Matrix m2);

    friend Matrix operator*(Matrix m1, Matrix m2);

//    friend  Matrix operator=(const Matrix &m)
    int get(int width, int height) const;

    void set(int width, int height, int value);

    Matrix plus(Matrix matrix);

    const Matrix subtraction(Matrix matrix);

    const Matrix multiply(Matrix matrix);

    Matrix multiply(int value);

    int getWidth() const;

    int getHeight() const;


    friend Matrix changeNum(Matrix m);

private:

    int multiplyLines(ListInt line1, ListInt line2);

    ListInt getLineHeight(int width);

    ListInt getLineWidth(int height);

    List createArray(int width, int height, int defaultValue) const;
};

#endif //S2LB1_2_MATRIX_H

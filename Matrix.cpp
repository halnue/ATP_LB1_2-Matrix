//

#include "Matrix.h"
#include "IncompatibleMatrices.h"
#include "NullPointException.h"

Matrix::Matrix():Matrix(1, 1) {}

Matrix::Matrix(int width, int height) {
    List list = createArray(width, height, 1);
    this->list = list;
}

Matrix::Matrix(List arrayInt) {
    list = arrayInt;
}


List Matrix::createArray(int width, int height, int defaultValue) const {
    List list = List();
    for (int i = 0; i < width; ++i) {
        ListInt list1 = ListInt();
        for (int j = 0; j < height; ++j) {
            list1.add(defaultValue);
        }
        list.add(list1);
    }
    return list;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    for (int i = 0; i < matrix.getWidth(); i++) {
        os << "| ";
        for (int i1 = 0; i1 < matrix.getHeight(); i1++) {
            os << matrix.get(i, i1) << " ";
        }
        os << "|" << std::endl;
    }
    return os;
}

std::ostream &operator<<(ostream &os, Matrix *matrix) {
    for (int i = 0; i < matrix->getWidth(); i++) {
        os << "| ";
        for (int i1 = 0; i1 < matrix->getHeight(); i1++) {
            os << matrix->get(i, i1) << " ";
        }
        os << "|" << std::endl;
    }
    return os;
}

int Matrix::get(int width, int height) const {
    if (width > getWidth() || height > getHeight())
        throw NullPointException();
    return list.get(width).get(height);
}

void Matrix::set(int width, int height, int value) {
    list[width][height] = value;
}

Matrix Matrix::plus(Matrix matrix) {
    if (this->getWidth() != matrix.getWidth() && this->getHeight() != matrix.getHeight())
        throw IncompatibleMatrices();
    else {
        Matrix matrixResult = Matrix(getWidth(), getHeight());
        for (int i = 0; i < matrix.getWidth(); ++i) {
            for (int j = 0; j < matrix.getHeight(); ++j) {
                int r = get(i, j) + matrix.get(i, j);
                matrixResult.set(i, j, r);
            }
        }
        return matrixResult;
    }
}

const Matrix Matrix::subtraction(Matrix matrix) {
    if (this->getWidth() != matrix.getWidth() && this->getHeight() != matrix.getHeight())
        throw IncompatibleMatrices();
    else {
        Matrix matrixResult = Matrix(getWidth(), getHeight());
        for (int i = 0; i < matrix.getWidth(); ++i) {
            for (int j = 0; j < matrix.getHeight(); ++j) {
                matrixResult.set(i, j, get(i, j) - matrix.get(i, j));
            }
        }
        return matrixResult;
    }
}

const Matrix Matrix::multiply(Matrix matrix) {
    if (this->getHeight() != matrix.getWidth())
        throw IncompatibleMatrices();
    else {
        Matrix result = Matrix(getWidth(), matrix.getHeight());
        for (int x = 0; x < matrix.getWidth(); ++x) {
            for (int y = 0; y < matrix.getHeight(); ++y) {
                ListInt m2 = matrix.getLineWidth(y);
                ListInt m1 = getLineHeight(x);
                int r = multiplyLines(m1, m2);
                result.set(x, y, r);
            }
        }
        return result;
    }
}

Matrix Matrix::multiply(int value) {
    Matrix matrixResult = Matrix(getWidth(), getHeight());
    for (int x = 0; x < matrixResult.getWidth(); ++x) {
        for (int y = 0; y < matrixResult.getHeight(); ++y) {
            matrixResult.set(x, y, this->get(x, y) * value);
        }
    }
    return matrixResult;
}

ListInt Matrix::getLineHeight(int width) {
    return list[width];
}

ListInt Matrix::getLineWidth(int height) {
    ListInt listResult = ListInt();
    for (int j = 0; j < getHeight(); ++j) {
        listResult.add(get(j, height));
    }
    return listResult;
}

int Matrix::multiplyLines(ListInt line1, ListInt line2) {
    int result = 0;
    for (int i = 0; i < line1.size(); ++i) {
        int sum = line1[i] * line2[i];
        result += sum;
    }
    return result;
}

int Matrix::getWidth() const {
    return list.size();
}

int Matrix::getHeight() const {
    if (getWidth()>0)
        return list.get(0).size();
    else return 0;
}

std::istream &operator>>(std::istream &in, Matrix m) {
    for (int j = 0; j < m.getWidth(); ++j) {
        for (int i = 0; i < m.getHeight(); ++i) {
            int num;
            in >> num;
            m.set(j, i, num);
        }
    }
    return in;
}

Matrix operator+(Matrix m1, Matrix m2) {
    return m1.plus(m2);
}

Matrix operator-(Matrix m1, Matrix m2) {
    return m1.subtraction(m2);
}

Matrix operator*(Matrix m1, Matrix m2) {
    return m1.multiply(m2);
}


Matrix::Matrix(const Matrix &m) {
    List list = createArray(m.getWidth(), m.getHeight(), 1);

    for (int i = 0; i < m.getWidth(); ++i) {
        for (int j = 0; j < m.getHeight(); ++j) {
            list[i][j] = m.get(i, j);
        }
    }
    this->list = list;
}

ListInt &Matrix::operator[](int i) {
    if (getWidth() > i && i >= 0)
        return list[i];
    else
        throw NullPointException();
}

Matrix::Matrix(int width, int height, int **arrayInt) {
    list = List(width,height,arrayInt);
}

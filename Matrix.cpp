//

#include "Matrix.h"
//#include "ListInt.cpp"
#include "IncompatibleMatrices.h"
#include "NullPointErexception.h"

Matrix::Matrix() {
    Matrix(1, 1);
}

Matrix::Matrix(int width, int height) {
    Matrix(height, width, 1);
}

Matrix::Matrix(int width, int height, List arrayInt) {
    array = arrayInt;
    this->width = width;
    this->height = height;
}

Matrix::Matrix(int width, int height, int defaultValue) {
    List list = createArray(width, height, defaultValue);
    this->array = list;
    this->height = height;
    this->width = width;
}

List Matrix::createArray(int width, int height, int defaultValue) const {
    List list = List();
    for (int i = 0; i < width; ++i) {
        ListInt list1 = ListInt();
        for (int j = 0; j < height; ++j) {
//            list1.set(j,defaultValue);
            list1.add(defaultValue);
        }
        list.add(list1);
    }
    return list;
}

//int **Matrix::getList() const {
//    return array;
//}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
//    os << "list: " << std::endl;
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

//void Matrix::setList(int **list1) {
//    this->array = list1;
//    this->height = sizeof(list1[0]) / sizeof(list1[0][0]);
//    this->width = sizeof(list1) / sizeof(list1[0]);
//}

int Matrix::get(int width, int height) const {
    if (width > getWidth() && height > getHeight())
        throw NullPointErexception();
    return array.get(width).get(height);
}

void Matrix::set(int width, int height, int value) {
    array[width][height] = value;
}

Matrix Matrix::plus(Matrix matrix) {
    if (this->getWidth() != matrix.getWidth() && this->getHeight() != matrix.getHeight())
        throw IncompatibleMatrices();
    else {
        Matrix matrixResult = Matrix(width, height, 1);
        for (int i = 0; i < matrix.getWidth(); ++i) {
            for (int j = 0; j < matrix.getHeight(); ++j) {
                int r = get(i, j) + matrix.get(i, j);
                matrixResult.set(i, j, r);
            }
        }
//        std::cout << matrixResult;
        return matrixResult;
//        return Matrix(matrix);
    }
}

const Matrix Matrix::subtraction(Matrix matrix) {
    if (this->getWidth() != matrix.getWidth() && this->getHeight() != matrix.getHeight())
        throw IncompatibleMatrices();
    else {
        Matrix matrixResult = Matrix(width, height, 1);
        for (int i = 0; i < matrix.getWidth(); ++i) {
            for (int j = 0; j < matrix.getHeight(); ++j) {
                matrixResult.set(i, j, get(i, j) - matrix.get(i, j));
            }
        }
//        std::cout << result;
        return matrixResult;
    }
}

const Matrix Matrix::multiply(Matrix matrix) {
    if (this->getHeight() != matrix.getWidth())
        throw IncompatibleMatrices();
    else {
        Matrix result = Matrix(width, matrix.getHeight(),1);
        for (int x = 0; x < matrix.getWidth(); ++x) {
            for (int y = 0; y < matrix.getHeight(); ++y) {
                ListInt m2 = matrix.getLineWidth(y);
                ListInt m1 = getLineHeight(x);
//                matrix.getLineWidth(y, m2);
                int r = multiplyLines(m1, m2);
                result.set(x, y, r);
            }
        }
//        std::cout << result;
        return result;
    }
}

Matrix Matrix::multiply(int value) {
    Matrix matrixResult = Matrix(width, height, 1);
    for (int x = 0; x < matrixResult.getWidth(); ++x) {
        for (int y = 0; y < matrixResult.getHeight(); ++y) {
            matrixResult.set(x, y, this->get(x, y) * value);
        }
    }
    return matrixResult;
}

ListInt Matrix::getLineHeight(int width) {
    return array[width];
}

ListInt Matrix::getLineWidth(int height) {
//    int *listResult = new int[getWidth()];
    ListInt listResult = ListInt();
    for (int j = 0; j < getHeight(); ++j) {
        listResult.add(get(j, height));
    }
    return listResult;
}

int Matrix::multiplyLines(ListInt line1, ListInt line2) {
    int result = 0;
//    int size = sizeof(&line1) / sizeof(&line1[0]);
    for (int i = 0; i < line1.size(); ++i) {
        int sum = line1[i] * line2[i];
        result += sum;
    }
    return result;
}

Matrix::~Matrix() {
//    delete[] array;
    width = 0;
    height = 0;
}

int Matrix::getWidth() const {
    return width;
}

int Matrix::getHeight() const {
    return height;
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
//    Matrix result = Matrix(m1.getWidth(), m1.getHeight(), 1);

    return m1.plus(m2);
}

Matrix operator-(Matrix m1, Matrix m2) {
//    Matrix result = Matrix(m1.getWidth(), m1.getHeight(), 1);

    return m1.subtraction(m2);
}

Matrix operator*(Matrix m1, Matrix m2) {
//    Matrix result = Matrix(m1.getWidth(), m1.getHeight(), 1);

    return m1.multiply(m2);
}

Matrix changeNum(Matrix m) {
    int w = m.getWidth();
    int h = m.getHeight();
    List l = List();
    for (int x = 0; x < w; ++x) {
        ListInt listInt = ListInt();
        for (int y = 0; y < h; ++y) {
            int num = m.get(x, y);
            if (num == 0)
                listInt.add(1);
            else
                listInt.add(num);

        }
        l.add(listInt);
    }
    return Matrix(m.getWidth(), m.getHeight(), l);
}

Matrix::Matrix(const Matrix &m) {
    List list = createArray(m.getWidth(), m.getHeight(), 1);

    for (int i = 0; i < m.getWidth(); ++i) {
        for (int j = 0; j < m.getHeight(); ++j) {
            list[i][j] = m.get(i, j);
        }
    }
    this->array = list;
    this->height = m.getHeight();
    this->width = m.getWidth();
}

ListInt &Matrix::operator[](int i) {
    if (width > i)
        return array[i];
    else
        throw NullPointErexception();
}

//Matrix Matrix::operator=(const Matrix &m) noexcept {
//    return Matrix(m);
//}
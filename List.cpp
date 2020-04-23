//
// Created by Michael on 14.02.2020.
//

#ifndef S2LB1_2_LIST_CPP
#define S2LB1_2_LIST_CPP

#include "NullPointErexception.h"
#include "ListInt.cpp"

class List {
private:
    ListInt *array;
    int length;
    int maxLength;
public:

    List(int maxSize) {
        array = new ListInt[maxSize];
        maxLength = maxSize;
        length = 0;
    }

    List(List const &listInt) {
        this->length = listInt.size();
        this->maxLength = listInt.size()*2;
        array = new ListInt[maxLength];
        for (int i = 0; i < listInt.size(); ++i) {
            array[i] = listInt.get(i);
        }
    }

    List() {
        int maxSize = 10;
        array = new ListInt[maxSize];
        maxLength = maxSize;
        length = 0;
    }

    List(int size,ListInt *arrayInt) {
        int maxSize = size * 2;
        array = new ListInt[maxSize];
        maxLength = maxSize;
        length = 0;
        for (int i = 0; i < size; ++i) {
            add(arrayInt[i]);
        }
    }

    List(int size,int interiorSize,int **arrayInt) {
        int maxSize = size * 2;
        array = new ListInt[maxSize];
        maxLength = maxSize;
        length = 0;
        for (int i = 0; i < size; ++i) {
            add(ListInt(interiorSize,arrayInt[i]));
        }
    }

    void add(ListInt value) {
        if (length == maxLength) {
            maxLength *= 2;
            ListInt *newArray = new ListInt[maxLength];
            for (int i = 0; i < length; ++i) {
                newArray[i] = get(i);
            }
            array = newArray;
        }
        array[length] = value;
        length++;
    }

    const  ListInt get(int i) const {
        if (i < length)
            return array[i];
        else
            throw NullPointErexception();
    }

    void update(int i, ListInt value) {
        if (i < length)
            array[i] = value;
        else
            throw NullPointErexception();
    }

    int size() const {
        return length;
    }

    void clear() {
        delete[] array;
        length = 0;
    }

//    void set(int i, int value) {
//        array[i] = value;
//    }

    ListInt &operator[](int i) {
        if (i < length)
            return array[i];
        else
            throw NullPointErexception();
    }

//    operator[]=(int i) {
//        if (length > i)
//            return array[i];
//        else
//            throw NullPointErexception();
//    }
};


#endif //S2LB1_2_LIST_CPP

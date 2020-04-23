//
// Created by Michael on 14.02.2020.
//

#ifndef S2LB1_2_LISTINT_CPP
#define S2LB1_2_LISTINT_CPP

#include "NullPointErexception.h"

class ListInt {
private:
    int *array;
    int length;
    int maxLength;
public:

    ListInt(int maxSize) {
        array = new int[maxSize];
        maxLength = maxSize;
        length = 0;
    }

    ListInt(ListInt const &listInt) {
        this->length = listInt.size();
        this->maxLength = listInt.size()*2;
        array = new int[maxLength];
        for (int i = 0; i < listInt.size(); ++i) {
            array[i] = listInt.get(i);
        }
    }

    ListInt() {
        int maxSize = 10;
        array = new int[maxSize];
        maxLength = maxSize;
        length = 0;
    }

    ListInt(int size,int *arrayInt) {
        int maxSize = size * 2;
        array = new int[maxSize];
        maxLength = maxSize;
        length = 0;
        for (int i = 0; i < size; ++i) {
            add(arrayInt[i]);
        }
    }

    void add(int value) {
        if (length == maxLength) {
            maxLength *= 2;
            int *newArray = new int[maxLength];
            for (int i = 0; i < length; ++i) {
                newArray[i] = get(i);
            }
            array = newArray;
        }
        array[length] = value;
        length++;
    }

    const  int get(int i) const {
        if (i < length)
            return array[i];
        else
            throw NullPointErexception();
    }

    void update(int i, int value) {
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

    int &operator[](int i) {
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


#endif //S2LB1_2_LISTINT_CPP

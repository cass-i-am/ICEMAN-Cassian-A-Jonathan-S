#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
#include <memory>
#include <vector>

class Actor;
class Ice;

template <typename T>
class list {

private:
    int size{ 0 };
    int capacity;
    T* arr;

public:
    list() {
        arr = new T[1];
        capacity = 1;
        size++;
    }

    list(T v) : capacity(v), arr(new T[v]) {
        for (int i = 0; i < capacity; i++) {
            arr[i] = 0;
        }
    }

    void pushBack(const T& val) {
        if (size >= capacity) {
            capacity *= 2;
            T* arrNew = new T[capacity];
            for (int k = 0; k < size; k++) {
                arrNew[k] = arr[k];
            }
            delete[]arr;
            arr = arrNew;
        }
        arr[size] = val;
        size++;
    }

    void pushFront(const T& val) {
        T* temp = nullptr;
        if (size >= capacity) {
            capacity *= 2;
            temp = new T[capacity];
        }
        else {
            temp = new T[capacity + 1];
            temp[0] = 0;
            for (int i = 0; i < size; i++) {
                temp[i + 1] = arr[i];
            }
        }

        temp[0] = val;
        arr = temp;
        size++;
    }

    void popFront() {
        if (size == 0) {
            return;
        }
        for (int i = 0; i < size; i++) {
            arr[i] = arr[i + 1];
        }
    }

    void popBack() {
        if (size == 0) {
            return;
        }
        arr[size + 1] = 0;
    }

    void remove(int const index) {
        if (size == 0) {
            return;
        }
        for (int i = index; i < size; i++) {
            arr[i] = arr[i + 1];
        }
    }

    inline int sizeOf() const {
        return size;
    }


    T& operator[](int index) const {
        if (index < 0 || index >size) {
            std::cerr << "Index out of range: " << index << std::endl;
            static T defaultObj{};
            return defaultObj;
        }
        return arr[index];
    }


    void insert(T value, int index) {
        if (index > capacity || index < 0) {
            std::cerr << "Index out of range " << index << std::endl;
        }
        arr[index] = value;
    }

    bool empty() {
        if (size == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    ~list() {
        delete[] arr;
    }

};


class StudentWorld : public GameWorld
{
public:
	StudentWorld(std::string assetDir) : GameWorld(assetDir) {};

	virtual int init();

	virtual int move();

	virtual void cleanUp();

private:
    IceBlock* ice[60][60];
    Player* iceMan;
};



#endif // STUDENTWORLD_H_


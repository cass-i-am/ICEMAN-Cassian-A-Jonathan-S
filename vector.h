// bubbleSOrt To impliment this well known algorith

// mergeSort() To impliment this well known algorithm
// slelctionSort() To impliment this well known algorithm. 

#ifndef VECTOR_H_
#define VECTOR_H_



#include <iostream>
#include <stdexcept>
#include <memory>



template <typename T>
class vector {

private: 
    int size{0}; 
    int capacity;
    T *arr; 

public:
    vector(T v): capacity(v), arr(new T[v]){
        for(int i = 0; i < capacity; i++ ){
            arr[i] = 0; 
        }
    }

    void pushBack(const T &val) {
        if(size >= capacity){
            capacity *= 2; 
            T * arrNew = new T[capacity];
            for (int k = 0; k < size; k++){
                arrNew[k] = arr[k]; 
            }
            delete []arr;
                arr = arrNew;
        }
        arr[size] = val; 
        size++; 
    }

    void pushFront(const T& val){
        T* temp = nullptr;
        if(size >= capacity){
            capacity *=2;
            temp = new T[capacity];
        } else {
            temp = new T[capacity + 1]; 
            temp[0] = 0; 
            for(int i = 0; i < size; i++){
                temp[i + 1] = arr[i];  
            }
        }

        temp[0] = val; 
        arr = temp;
        size++;
    }

    void popFront(){
        if(size == 0 ){
            return; 
        }
        for(int i = 0; i < size; i++){
            arr[i] = arr[i + 1]; 
        }
    }

    void popBack(){
        if (size == 0){
            return;
        }
        arr[size + 1 ] = 0; 
    }

    void remove(int const index){
        if (size == 0 ){
            return; 
        }
        for(int i = index; i < size; i++){
            arr[i] = arr[i + 1]; 
        }
    }

    inline int sizeOf() const  {
        return size; 
    }

    void print(){
        empty();

        if (arr == nullptr){
            std::cout << "Array has not been created " << std:: endl;
            return;
        }
        if(size != 0 ){
            std::cout << "vector: ";
        }
        for(int i = 0; i < size; i++){
            std::cout << arr[i] << ", "; 
        }
        std::cout << "" << std::endl; 
    }

    T& operator[](int index) const{
        if(index < 0 || index >size){
            std::cerr << "Index out of range: " << index << std::endl;
            static T defaultObj{}; 
            return defaultObj;
        }
        return arr[index]; 
    }


    void insert(T value, int index){
        if (index > capacity || index < 0 ){
            std::cerr << "Index out of range " << index << std::endl; 
        }
        arr[index] = value; 
    }

    void find(const T val) const {
        bool found = false;
       for (int i = 0; i < size; i++){
            if (arr[i] == val){
                std::cout << std::endl;
                std::cout << "value found at index: "; 
                std::cout << i << ", " << std::endl; 
                std::cout << std::endl; 
                found = true;
            }
        }
        if (!found){
        std::cout << "value not found: " << std::endl; 
        }
    }

    T front() const{
        return arr[0]; 
    }

    T back() const{
        return arr[size - 1]; 
    }

    void reSize(const int SIZE){
        T * sizedArr = new T[SIZE]();
        for(int i = 0; i < size; i++){
            arr[i] = sizedArr[1];
        }
        sizedArr = arr;
    }

    void reverse(){
        T *reversed = new T[capacity]; 
        int base = 0;
        int tail = size - 1; 
        int emptyIndexies = size + 2;
        for(int i = 0; i < size; i++){
            reversed[base ++] = arr[tail --]; 
            for(int j= emptyIndexies; j < capacity; j++){
                reversed[j] = 0; 
            } 
        }
        for(int j= emptyIndexies; j < capacity; j++){
            reversed[j] = 0; 
        } 
        delete [] arr;
        arr = reversed;
    }




    void clear(){
        for(int i = 0; i < capacity; i++){
            arr[i] = 0; 
            size--;
        }
        size = 0;
    }



    void exit(){
        return;
    }


    bool empty(){
        if(size == 0){
            std::cout << "Vector is: empty. " << std::endl; 
            return true;
        } else 
            std::cout << "Vector is not emplty. " << std::endl; 
            return false; 
    }

    // void selectSort(int arr[], int n) {
    //     for (int i = 0; i < n - 1; i++) {
    //         int minIndex = i;
    //         for (int j = i + 1; j < n; j++) {
    //             if (arr[j] < arr[minIndex]) {
    //                 minIndex = j;
    //             }
    //         }
    //         int temp = arr[i];
    //         arr[i] = arr[minIndex];
    //         arr[minIndex] = temp;
            
    //     }
    // }



    ~vector(){
        delete [] arr;
    }

}; 


    template <typename T> 
    void vectorBubbleSort(vector<T>& arr, int n) {
        bool swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int c = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = c;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            } 
            std::cout << std::endl;
            std::cout << "Sorting pass " << i+1 << ": "; 
            for (int l = 0; l < n; l++){
                std::cout << arr[l] << " ";
            }
            std::cout << "" << std::endl;
        }

    }

#endif
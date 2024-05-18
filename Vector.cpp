 /*
    1. Create a templated vector class with move assignment operator, Copy Constructor & Move constructor member funtions.
    
    2. You should also include basic and fundimental operations such as, pushBack(), pushFront(), popFront(), popBack(), find(), 
    remove(), size(), and a destructor.  

    3. You should also include some special sorting algorithms implimented as member functions such as 
    bubble sort, Quick Sort, Merge Sort, 

    4. You should also make use of the STL exception class and must write exception safe code when possible given the data structure 
    that you have to work with. 
*/ 

// Remember to handle any exceptions that might be thrown by your member functions. For example, your operator[] 
// function throws an exception if the index is out of range. You can use a try-catch block in your main function 
// to catch this exception and print an error message.

//////////////// Completed Functions  //////////////
// sizeOf() to check the size of the array
// print() To print the value of the elements in the array. 
// operator[] for access to elements
// pushBack() to add to the back 
// exit() To exit the user based interface. 
// destructor to delete dynamically allocated memory
// find()   To find a specific value of that may be in an array
// pushFront() To add an element to the front of the array
// front() to access the first element
// back() to access the last element
// clear() to remove all elements from the vector
// popFront()  To remove an element from the front of an array.
// popBack()   To remove an element from the back of an array 
// remove()  To remove a specific element in an array
// empty() to check if the vector is empty
// insert() to insert an element at a specific position
// reverse() To reverse or flip the order of the elements in the array.

// bubbleSOrt To impliment this well known algorith

// mergeSort() To impliment this well known algorithm
// slelctionSort() To impliment this well known algorithm. 









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


    void listt(){
        std::cout << "pushBack() To add to the back of the array. " << std::endl;
        std::cout << "pushFront() To add an element to the front of the array. " << std::endl;
        std::cout << "popFront() To remove an element from the front of an array. " << std::endl;
        std::cout << "popBack() To remove an element from the back of an array.  " << std::endl;
        std::cout << "find() To find a specific value of that may be in an array " << std::endl;
        std::cout << "remove() To remove a specific element in an array " << std::endl;
        std::cout << "sizeOf() To check the size of the array " << std::endl;
        std::cout << "print() To print the value of the elements in the array. " << std::endl;
        std::cout << "clear() To remove all elements from the vector. " << std::endl; 
        std::cout << "empty() To check if the vector is empty " << std::endl;
        std::cout << "insert() To insert an element at a specific position. " << std::endl;
        std::cout << "erase() To remove an element at a specific position " << std::endl;
        std::cout << "front() To access the first element. " << std::endl;
        std::cout << "back() To access the last element. " << std::endl;
    }

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

// Bubble Sort Algorithm:

// 1. Start from the first element of the array, compare the current element with the next one.

// 2. If the current element is greater than the next one, swap them. If not, move to the next element.

// 3. Continue this process until you've gone through the entire array once. This completes one pass.

// 4. In each pass, the largest element "bubbles up" to its correct position (end of the array in case of ascending order).

// 5. Repeat the passes until no more swaps are needed. This means the array is sorted.

// Note: After each pass, the next largest element is placed at its correct position. 
// Therefore, with each subsequent pass, you need to consider one less element at the end of the array.


int main() {
    // Create a vector with initial capacity of  10
    vector<int> v1(10);

    // Test pushBack
    v1.pushBack(5);
    v1.pushBack(10);
    v1.pushBack(15);
    v1.pushBack(20);
    v1.pushBack(25);
    v1.print();  // Should print "vector: 5, vector: 10, vector: 15, vector: 20, vector: 25,"

    // Test sizeOf
    std::cout << "Size: " << v1.sizeOf() << std::endl;  // Should print "Size: 5"

    // Test operator[]
    std::cout << "Element at index 0: " << v1[0] << std::endl;  // Should print "Element at index 0: 5"
    std::cout << "Element at index 4: " << v1[4] << std::endl;  // Should print "Element at index 4: 25"

    // Test with an out-of-range index
    std::cout << "Element at index 10: " << v1[10] << std::endl;  // Should throw an exception or print an error message
    // Test other member functions as needed...

    v1.find(15); 

    v1.pushFront(1);

    v1.print();

    std::cout << "Size: " << v1.sizeOf() << std::endl;  // Should print "Size: 5"

    std::cout << "The element at the front of the vector is " << v1.front() << std::endl; 
    std::cout << "The element at the rear of the vector is " << v1.back() << std::endl; 

    v1.reverse();
    std::cout << "The reversed vector is: "; 
    v1.print();
    v1.clear();
    v1.print();
    v1.pushBack(7); 
    v1.pushBack(11);
    v1.pushBack(5);
    v1.pushBack(10);
    v1.pushBack(55);
    v1.pushBack(28);
    v1.pushBack(4);
    v1.pushBack(19);
    v1.pushBack(2);
    v1.print();
    std::cout << "Bubble sort first pass \n" << std::endl; 
    vectorBubbleSort(v1, 5);
    v1.print();

    return 0;
}
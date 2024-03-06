//
//  Wk9-1.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/28/23.
//

#include <iostream>
#include <string>
#include <vector>

//constant global variable
const int MY_VECTOR_MAX_SIZE = 100;

//Implement a vector using an array
struct MyDoubleVector {
public:
    MyDoubleVector(): size_var(0) {}
    MyDoubleVector(size_t size):size_var(size) {
        assert(size<=MY_VECTOR_MAX_SIZE)
        for (size_t i = 0; i < size; ++i){
            elem[i] = 0;
        }
    }
    MyDoubleVector(size_t size, double value):size_var(size){
        assert(size<=MY_VECTOR_MAX_SIZE);
        for (size_t i = 0; i < size; ++i){
            elem[i] = value;
        }
    }
    size_t size() const{
        return size_var;
    }
    void push_back(double value){
        elem[size()] = value;
        ++size_var;
    }
    void pop_back(){
        assert(size_var>1);
        elem[size()-1] = '\0';
        --size_var;
    }
    double get_at(size_t index) const;
    void set_at(size_t index, double value);
    
    
private:
    //Array of elements of the vector. The vector cannot be any bigger than the size of the array, but can be made smaller by ignoring some of the elements in the array
    int elems[MY_VECTOR_MAX_SIZE];
    size_t size_var;
    
};


int main(){
    
    size_t n;
    cin >> n;
    //not allowed because the size of the array has to be determined when the program is built, can't depend on behavior of program while running
    int a[n];
    
    int a[10]; //a will always be size 10
    
    for (size_t i = 0; i < 10; ++i){
        a[i] = i *i;
    }
    
    //when iterating a number down to 0, always use a signed type --> the loop ends when i is -1
    for (int i = 9; i >= 0; --i){
        
    }
    
    return 0;
}

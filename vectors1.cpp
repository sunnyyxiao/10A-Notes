//
//  vectors1.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/1/23.
//

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    /*
     Vectors, like strings are sequence containers which can change their size
     - they hold a sequence of elements each of which can be accessed via an index
     - these elements could be characters, unlike strings though they could also be pretty much any other type
     - vectors can be dynamically reallocated to memory allowing their size to change
     */
    
    //Declare a vector, can be any sort of class
//    vector<int> v5 = {1,2,3,4,5};
//    for (size_t i = 0; i <=v5.size()-1; i++){
//        cout << v5[i];
//    }
//    cout << "\n";
    
    //Examples of member functions: push_back, size, iterate, pop_back
//    vector<int> v2 = {1,2,3};
//    cout << v2.capacity() << " " << v2.size() << endl;
//    v2.push_back(4);
//    cout << v2.capacity() << " " << v2.size() << endl;
//    for (size_t i = 0; i <=v2.size()-1; i++){
//        cout << v2[i];
//    }
//    cout << "\n";
//    
//    v2.pop_back();
//    v2.pop_back();
//    for (size_t i = 0; i <=v2.size()-1; i++){
//        cout << v2[i];
//    }
//    cout << "\n" << v2.capacity() << " " << v2.size() << "\n";
    
    //Size is the number of objects I have put into my vector
    //Capacity is the amount of memory reserved for storing objects in this vector
    
//    vector<int> v = {1,2,3,4,5,6,7,8};
//    cout << v.capacity() << " " << v.size() << endl;
//    v.clear();
//    cout << v.capacity() << " " << v.size() << endl;
//    for(size_t i = 0; i<v.size(); i++){
//        cout << v[v.size()-1]; //no good, v.size() is always changing every time you iterate through the loop
//        v.pop_back();
//    }
//
//    size_t N = v.size();
//    for(size_t i = 0; i<N; i++){
//        cout << v[N-i-1];
//        v.pop_back();
//    }
    
    /* Capacity versus size
     - Whenever capacity of the vector is exceeded it is copied and reallocated to a new memory location with a more contiguous memory
     - This copying is expensive, so we don't want to do it too often, but we don't want to reserve too much memory for the array if it isn't needed
     - Capacity is doubled whenever it is exceeded hits, meaning number of copies is logarithmic in the size of the array
     - Vectors are useful in that they handle the memory storage needeed to contain your data and do so in a smart efficient manner
     */
    
    vector<size_t> v;
    cout << v.capacity() << " " << v.size() << "\n";
    size_t T = 15;
    for (size_t i = 1; i <= T; i++){
        v.push_back(i);
        cout << v.capacity() << " " << v.size() << "\n";
    }
    //size is never greater than capacity
    
    return 0;
}

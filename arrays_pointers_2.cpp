//
//  arrays_pointers_2.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/29/23.
//

#include <iostream>

using namespace std;

int main(){
    {
        //To initialize an array, we need its size and type
        const size_t size = 4;
        int a1[size] = {1, 2, 3, 4};
        //OR
        double a2[] = {1.1, 1.2, 1.3, 1.4, 1.5}; //implicitly given size 5
        
        //Use the sizeof() function to calculate the size of the arrays
        cout << "An int needs " << sizeof(int) << " bytes of memory." << endl;
        cout << "The array a1 needs " << sizeof(a1) << " bytes." << endl;
        cout << "The length of a1 is " << sizeof(a1)/4 << "." << endl;
        
        cout << "A double needs " << sizeof(double) << " bytes of memory." << endl;
        cout << "The array a2 needs " << sizeof(a2) << " bytes." << endl;
        cout << "The length of a2 is " << sizeof(a2)/8 << "." << endl;
        
        //create two pointers: one to store the emmory address of the first element of a1 and another to store that of a2
        int* p1 = &a1[0];
        double* p2 = &a2[0];
        
        cout << boolalpha << "p1 stores address " << p1 << ", " << (p1 == &a1[0]) << endl;
        //By incrementing a memory address, we get the next memory location in the array. This is possible because the elements of an array are stored in adjacent spaces in memory.
        cout << "p1 + 1 stores address " << p1+1 << ", " << (p1+1 == &a1[1]) << endl;
        
        cout << "p2 stores address " << p2 << ", " << (p2 == &a2[0]) << endl;
        cout << "p2 + 1 stores address " << p2+1 << ", " << (p2+1 == &a2[1]) << endl;
        cout << "p2 + 2 stores address " << p2+2 << ", " << (p2+2 == &a2[2]) << endl;
        cout << "p2 + 3 stores address " << p2+3 << ", " << (p2+3 == &a2[3]) << endl;
        
        //You should always initialize pointers, or set them to null
        int* pnull = NULL;
        
        /*
         cout << p1+4 << endl;
         cout << *(p1+4) << endl;
        p1 + 4 refers to a specific address and the computer is trying to interpret this binary information as an int. It probably was not intended to be interpreted as an int, so doing this makes no sense.
         */
        
        //Traditional way of printing out an array
        for (size_t i = 0; i < size; ++i){
            cout << a1[i] << " ";
        }
        cout << endl;
        //We can use pointers to iterate through containers (an array is a container)
        for (size_t i = 0; i < size; ++i){
            cout << *(p1+i) << " ";
        }
        cout << endl;
        
        //a2 was implicitly given its size, 5
        for (size_t i = 0; i < sizeof(a2)/8; ++i){
            cout << a2[i] << " ";
        }
        cout << endl;
        for (size_t i = 0; i < sizeof(a2)/8; ++i){
            cout << *(p2+i) << " ";
        }
        cout << endl;
    }
    
    {
        /* Intro to stack and heap
         Large objects are stored in heaps, and smaller objects in stacks.
         Heaps are slower, stacks are faster --> heap memory is not as safe.
         Arrays/vectors (that can tend to become very large) are stored in heaps, while pointers are stored in the stack.
         */
    }
}

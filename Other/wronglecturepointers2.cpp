//
//  pointers2.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/27/23.
//

#include <iostream>

using namespace std;

int main(){
    {
        //Pointers review
        double d = 67;
        //declare pointer to store the memory address of d
        double* p = &d; //declaring pointer p that stores the memory address of the double d
        cout << "The memory address of d is " << &d << endl; //stores in hexdecimal
        cout << "The value of p is " << p << endl;
        cout << "The value of *p is " << *p << endl; //*p is the dereferencing operator
        
        //Pointers are a data type that stores memory addresses, but they themselves also have memory addresses.
        int x = 0;
        int* px = &x;
        
        cout << "x = " << x << endl;
        cout << "px = " << px << endl;
        cout << "*px = " << *px << endl;
        //Pointer px also has its own memory address
        cout << "&px = " << &px << endl;
        
    }
    
    cout << endl;
    
    {
        //Arrays and pointers
        
        const size_t size = 4;
        int arr1[size] = {2,4,6,8};
        double arr2[] = {6.1, 8.7, 9.0, 0.6, 5.5}; //implicitly gives array its size (initializes array implicity), number of elements can't be changed afterwards
        
        for (size_t i = 0; i < size; i++){
            cout << arr1[i] << " ";
        }
        cout << endl;
        
        //how much memory does an int or a double take up?
        cout << "An int needs " << sizeof(int) << " bytes." << endl;
        cout << "A double needs " << sizeof(double) << " bytes." << endl;
        
        //The memory needed for an array is the number of elements times the memory required for that type
        cout << "The length of arr1 is " << sizeof(arr1)/4 << endl;
        cout << "The length of arr2 is " << sizeof(arr2)/4 << endl;
        
        //Introduce pointers that refer to the memory addresses of each of these arrays
        int* p1 = &arr1[0]; //p1 will store the memory address of the first element of arr1
        double* p2 = &arr2[0]; //p2 will store the memory address of the first element of arr2
        
        cout << "p1 stores memory address " << p1 << endl;
        cout << "p1 stores memory address " << &p1 << endl;
        cout << "p1 stores memory address " << &arr1[0] << endl;
        cout << "p1 has value " << *p1 << endl;
        
        //printing the value held by p1 and also checking that it's the tsame as the address of the 0th element of arr1
    
        cout << boolalpha << "p1 + 1 stores memory address " << p1+1 << ", " << (p1+1 == &arr1[1]) << endl;
        cout << "p1 + 2 stores memory address " << p1+2 << ", " << (p1+2 == &arr1[2]) << endl;
        cout << "p1 + 3 stores memory address " << p1+3 << ", " << (p1+3 == &arr1[3]) << endl;
        
        //there is a difference of 4 between the memory address of adjacent elements, this is because each element is an int and takes up 4 bytes
        
        cout << "p2 stores memory address " << p2 << ", " << (p2 == &arr2[0]) << endl;
        cout << "p2 + 1 stores memory address " << p2+1 << ", " << (p2+1 == &arr2[1]) << endl;
        cout << "p2 + 2 stores memory address " << p2+2 << ", " << (p2+2 == &arr2[2]) << endl;
        cout << "p2 + 3 stores memory address " << p2+3 << ", " << (p2+3 == &arr2[3]) << endl;
        
        for(size_t i = 0; i < size; i++){
            cout << *(p1+i) << " " << arr1[i] << endl;
        }
        /*
         Dereferencing *(p1+i) does the same thing here as arr[i].
         p1+i is the memory address of the ith element of arr, using the asterisk gives us the value stored at that memory location
        */
        cout << endl;
        
        //arr1 is of size 4, its addresses are p1, p1+1, p1+2, p1+3 --> what if we do p1+4
        cout << "The value of p1+4 is " << p1+4 << endl;
        /* Sometimes when you do this, you get the memory address of the next array to ebb declared after arr1.
         You should not try to dereference p1+4, i.e. memory address beyond the length of the array --> won't give you sensible answers
         */
        cout << *(p1+4) << endl;
        //We can't interpret the values stored at the next location properly because we don't know what type it is. For example, ints and doubles are stored in binary form very differently, and trying to interpret a double as an int won't make sense.
        
  
    }
    
    
    return 0;
}

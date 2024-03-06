//
//  arrays-pointers-2-original.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 12/7/23.
//


/*
 AGENDA:
 - Recap of pointers
 - A quick note on hexadecimal
 - Accessing elements of arrays via pointers
*/
#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <string> // Allows certain string operations
#include <cmath> // Includes a load of useful math related functions like round,max etc.
#include <vector>// allows us to use the vector class
using namespace std; // Tells computer where to look for various functions


void print_s1(const char* p){
    while (*p != '\0'){
        cout << *p << " ";
        p++;
    }
    cout << endl;
}
int main(){
    /*
    For this class we will need to recall the following:
    - ints require 4 bytes
    - doubles require 8 bytes
    - memory address are written in hexadecimal!
    Quick recap of hexadecimal:
    In hexadecimal we have 16 symols which we can use to represent numbers. We
    assign
    numbers sequences of symbols in a manner analagous to how we do it for
    decimal.
    Decimal: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20...
    Hexadecimal: 1 2 3 4 5 6 7 8 9 a b c e f 10 12 13 14 15 16 ...
    Once we run out of symbols, then for the next number we assign 1 then all
    zeros.
    Important for what follows:
    - The least significant digit of multiples of 4 have the sequence 0, 4, c, 8,
    0, 4, c, 8,...
    - The least significant digit of multiples of 8 have the sequence 0, 8, 0,
    8,...
     */
    {
        // Let us introduce two arrays, one double one pointer
        size_t const SIZE = 4;
        int ai[SIZE] = {1,2,3,4};
        double ad[] = {1.1, 2.2, 3.3, 4.4};
        // The sizeof command can be used to determine how much memory in bytes an object of a certain data type requires
        cout << boolalpha << "An int needs " << sizeof(int) << " bytes.\n";
        cout << "A double needs " << sizeof(double) << " bytes.\n";
        
        // Now, we create two pointers
        int* pi = &ai[0];
        double* pd = & ad[0];
        cout << "pi stores address " << pi << ", " << (pi == &ai[0]) << "\n";
        cout << "pi+1 stores address " << pi + 1 << ", " << (pi+1 == &ai[1]) << "\n";
        cout << "pi+2 stores address " << pi + 2 << ", " << (pi+2 == &ai[2]) << "\n";
        cout << "pi+3 stores address " << pi + 3 << ", " << (pi+3 == &ai[3]) << "\n";
        // Conclusion, adding an integer i to a pointer returns a pointer with memory address += i*sizeof(type)! Observe have increased last digit by 4! See if also holds true for doubles...
        cout << "\n";
        cout << "pd stores address " << pd << ", " << (pd == &ad[0]) << "\n";
        cout << "pd+1 stores address " << pd + 1 << ", " << (pd+1 == &ad[1]) << "\n";
        cout << "pd+2 stores address " << pd + 2 << ", " << (pd+2 == &ad[2]) << "\n";
        cout << "pd+3 stores address " << pd + 3 << ", " << (pd+3 == &ad[3]) << "\n";
        // The same is true for doubles, see memory address incremented by 8, which is size of a double.
        cout << "\n";
        
        
        // We can therefore use pointers to iterate through containers!
        for(size_t i = 0; i < 4; ++i){
            cout << *(pi+i) << " " << pi[i];
        }
        cout << "\n";
        
        // In fact, if p is a pointer and i is of type size_t then p[i] is an abbreviation for *(p+i)
        // Let us look at something interesting.
        cout << "pd+4 stores address " << pd + 4 << ", pi stores address " << pi << "\n";
        // Looks like they are both the same! Seems like Xcode stored ai after ad. The following won't work though:
//        cout << (pd+4 == pi); // Won't let us build because these are different types of pointers! Why does it matter though, they both can hold the same address? Need to think about derefencing operator.
        cout << "\n";
        cout << "*(pd+4) returns " << *(pd+4) << "\n";
        cout << "*pi returns " << *pi << "\n";
        // What has happened here? Well in the first case we took essentially the bits stored in memories pointed to by pi and pi +1, concatenated the binary strings and then interepreted this string as a double In the second we took just the bits stored in memory location pointed at by pi and intereted these as a (signed) integer. This further illustrates that manipulation at the level of memory addresses can let you do odd things and needs to be done with care!
    }
    {
        /*
        Intro to stack and Heap:
        Something you will learn in 10B is that big things are stored on the heap and small things on the stack (stack is fast!). Vectors are stored on the heap as can be very large!
        */
        vector<int> v={1,2,3,4};
        cout << &v[0] << "\n";
        // Let us now resize!
        v.resize(256);
        // Observe the memory address of v[0] has changed! This is because your computer needed to find a larger contiguous chunck of memory store this bigger vector.
        cout << &v[0] << "\n";
        
    }
    {
        vector<int> x3 = {1,2,3};
        vector<int> x2 {3,4,5};
        int x = 5;
        cout << sizeof(x) << sizeof(x3) << sizeof(x2) << endl;
        
        const char z[] = "hello!";
        print_s1(z);
    }
    
    return 0;
}


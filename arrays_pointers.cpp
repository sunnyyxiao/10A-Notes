//
//  arrays_pointers.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/27/23.
//

/*
 AGENDA:
 - Declaring C style arrays
 - Initializing C style arrays
 - Pointers!
 */

#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <string> // Allows certain string operations
#include <cmath> // Includes a load of useful math related functions like round, max etc.
#include <vector>// allows us to use the vector class
//#include "defaults.hpp"
using namespace std; // "Tells computer where to look for various functions"



int main(){
    
    {
        //C STYLEARRAYS
        // Arrays are containers similar to vectors, however, unlike vectors, their size in terms of memory cannot be reallocated or changed after initialization! To declare and initialize an array we need to declare both its type and size.
        
//        int a1[100]; We could also do it like this
        const size_t sizeA = 10; // An array has constant size, therefore the
        int a1[sizeA];
        
        // The following illustrates that before initialization the values of the elements of the array are random. To be clear, all we have done is assign a set of contiguous memory locations as representing our array object. The bits in each of these memory locations are random to us as they are probably leftover from something our computer was doing before!
        for (size_t i = 0; i<sizeA; ++i){
            cout << a1[i] << " ";
        }
        cout << "\n";
        
        // FIRST WAY TO INITIALIZE ARRAYS: we can assign or initialize the elements of the array as follows:
        
        for (size_t i = 0; i<sizeA; ++i){
                a1[i] = int(i); // convert size_t to int
                cout << a1[i] << " "; // print just to see has changed
            }
            cout << "\n";
        
        // SECOND WAY TO INITIALIZE ARRAYS: direct assignment via {}
        int a2[sizeA] = {1,2,3}; // same as doing {1,2,3,0,0,0,0,0,0,0}
        for (size_t i = 0; i<sizeA; ++i){
            cout << a2[i] << " ";
        }
        cout << "\n";
        // If we use direct assignment then we assign the values or arguments inside the {} brackets to the elements in order left to right. If there are fewer arguments than array elements all remaining array elements are given 0. If there are excess arguments then the code won't build!
    }
    
    
    {
        // INTRODUCING POINTERS
        // Variables are names or identifiers for us as the programmer to use to refer to specific memory locations. How can we actually access these memory addresses?
        cout << "\n";
        int x = 10;
        cout << "The value of x is " << x << "\n";
        cout << "The memory location x refers to is " << &x << "\n"; // Note memory address are numbers written in hexadecimal.
        
        // Note we used & before to declare a reference! Here we are using to access the memory location of a variable, which sort of makes sense, think of the following reference declaration as saying give the memory location of x a new name r as a way of justifying this mixed usage of &.
        int& r = x;
        
        // Now let us introduce pointers. Pointers are a specific type, i.e., a memory location or box, used to store the memory addresses of other variables! They are declared using an *.
        int* p = &x;
        
        // Above, p is a pointer, i.e., p is the identifier for a memory location in which is stored the memory location identified by the name x. If I try and print p now I just get the memory address of x.
        cout << "The value of p is " << p << "\n";
        
        // What about if we do *p?
        cout << "The value of *p is " << *p << "\n";
        // This gives 10! Why? Well * is called the dereferncing operator. It is asked what is stored at memory address with value x!
        
        // Why do we call these things pointers? Well because of the dereferencing operator we can imagine p in this case as 'pointing' to the value of x
    }
        
    {
        // DECLUTTERING THE USAGE OF & and *
        cout << "\n";
        int x = 10; // Just used so that following makes sense
        
        // DECLARATIONS:
        int& r = x; // "int&" is a type: 'reference to an int'
        int* p; //  "int*" is a type: 'pointer to an int'
        
        // REFERENCING:
        // *p is the dereferencing operator, asks for the value at the address of value the variable p
        // &x asks for the memory location of p
        p = &x;
        // Note calling &p just gives you the memory address stored in p, not the location of p.
        cout << "p has value " << p << "\n";
        cout << "&p has value " << &p << "\n";
        
    }
    
    {
        // POINTERS TO POINTERS AND NULLPOINTERS
        // It is not a good idea to declare and don't initialize a pointer... Why? Well if our pointer happens to point to some random location which is storing something important we may inadvertantly overwrite some important piece of information...
        cout << "\n";
        int x = 10;
        int y = 12;
        int* p1  = &x;
        int* p2 = nullptr; // special memory address which makes sure that if you derefence then will throw an error
        //*p2 = 3; // throws a runtime error this is much safer!
        
        // YOU SHOULD ALWAYS INITIALIZE YOUR POINTERS WHEN YOU CREATE THEM
        
        // Let us now assign one pointer to another...
        p2 = p1;
        // This has the effect of meaning that both p1 and p2 now point to the same thing, in this case x!
        cout << "p1 has value " << p1 << "\n";
        cout << "p2 has value " << p2 << "\n";
        cout << "*p1 has value " << *p1 << "\n";
        cout << "*p2 has value " << *p2 << "\n";
        
        cout << "\n";
        
        // Note that we are free to reassign our pointers seperatly, if we reassign p1 then p2 is left unchanged.
        p1 = &y;
        cout << "p1 has value " << p1 << "\n";
        cout << "p2 has value " << p2 << "\n";
        cout << "*p1 has value " << *p1 << "\n";
        cout << "*p2 has value " << *p2 << "\n";
        
    }
    
    {
        cout << "\n";
        // CONST POINTERS
        double d1 = 1.5;
        double d2 = 10.5;
        
        double* p1 = &d1;         // 'pointer to type double'
        const double* p2 = &d1;   // 'pointer to type const double' (read from right to left in some sense)
        double* const p3 = &d1;   // 'const pointer to type double' (read from right to left in some sense)
        
        // All of these pointers point to the same place in memory currently, i.e., d1
        cout << "p1 has value " << p1 << "\n";
        cout << "p2 has value " << p2 << "\n";
        cout << "p3 has value " << p3 << "\n";
        
        // We can reassign p1 and p2 but not p3
        p1 = &d2;
        p2 = &d2;
        //p3 = &d2; // Is a const pointer, it cannot be reassigned to point at a different memory location!
        
        // Think of constant pointers as being fixed to a single memory location.
        
        // We can change the value of x by using the derefencing operator on p1 and p3, but not p2!
        *p1 = 3;
        cout << "The value of d2 is now " << d2 << "\n";
        *p3 = 6;
        cout << "The value of d1 is now " << d1 << "\n";
//            *p2 = 12;
//            cout << "The value of x is now " << x << "\n";
        
        // Think of pointers to const type as being read only, a bit like const references are read only
        // A reference is a const pointer  which is automatically dereferenced, i.e., we don't have to use *
        
    }
    
    {
        // POINTERS TO CLASSES
        // You can create pointers to any class, including ones you write yourself! We will do more on this next time...
        string s("Hello!");
        string* p= &s;
        cout << "s has value " << s << "\n";
        cout << "s has memory location " << &s << "\n";
        cout << "s has length " << s.length() << "\n";
        cout << "s has length " << (*p).length() << "\n"; // can also do it like this!
        cout << "s has length " << p->length() << "\n"; // and shorthand like this! Cool right?
        
    }
    
    
}


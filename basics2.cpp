//
//  Lec3.cpp
//  Project
//
//  Created by Sunny Xiao on 10/4/23.
//
/*
AGENDA FOR CLASS
- Announcements
- Variables in C++
- Calculating with variables
- Fundamental data types in C++
- Booleans in more detail
*/

#include <iostream> // Allows us to use cout and cin to read and write via the console
//#include <stdio.h> // Sometimes you may see this, is the input-output library for C
#include <string> // Allows certain string operations, for later in the course
#include <cmath> // Includes a load of useful functions like round that we will demonstrate
using namespace std; // "Tells computer where to look for various functions"
int main(){
    // 1) VARIABLES IN C++
    // Variables in C++ are essentially shortcuts names for pieces of memory (i.e., boxes)
    // Declaring a variable reserves a piece of memory or box
    int x;
    //cout << x; // currently x dosn't really have a value right now, so will throw a warning
    // Initializing a variable involves giving it or assigning it a value for the first time.
    x = 3; // Put the integer object 5 in the memory location with name x
    cout << "x has value " << x << "\n";
 /*
     '=' is the assignment operator, 'x = 5' puts the integer object 5 in the
     memory location
     or box which has been given the name x. It is not the same as equals!
     */

    int y = 2; // We can declare and initalize on the same line.
    //y = x; // Equals is not the same as assignment!
    cout << "The value of x is " << x<< ", the value of y is " << y << "\n";
    //int x = 4 // Once a variable has been declared it can't be re-declared as this would lead to ambiguity
    // It is useful to name your variables so that they are easy to read
    int my_number = 1; //Underscores
    int MyNumber = 1; //Camelback notation
    //Note that caps etc matter, the variable X and x are different for example
    // Constant variables: make program easier to debug and more robust
    const int INCHES_PER_FEET = 12; // capitalize by convention
    //const int INCHES_PER_FEET; // Have to be initialized when declared
    // INCHES_PER_FEET = 10; Can't be changed once initialized
    // 2) CALCULATING WITH VARIABLES
    float z = x + y; //x*y, y-x etc...
    cout << "z has value " << z << "\n"; // note is a float even though x and y are integers
    z = x/y; // Think about what value this will have...
    cout << "z has value " << z << "\n";
/*
    z = 3/2 breakdown, first 3/2 is calculated, this is the integer 1, then the
    integer 1 is put in
    a box for floats, i.e., is given a bunch of decimal points which are all 0.
    These aren't always displayed... We will
    cover this later in the course.
    */
    // Integer division should be avoided unless you explictly want to use it! There are some use cases

    int digits = 123;
    cout<< "The hundreds digit is " << digits/100 << "\n";
    // Mode computes the remainder
    cout << digits % 2 << "\n"; // Test if digits is an even number
    // Note x %y is the remainder, so x%y = x - (x/y)*y for x and y integers % not defined if x, y not integral, careful with combining negatives

    cout << (-10)%(-3) << "\n"; // Example
    cout << "The hundreds digit is " << digits/100 << ", the tens digits is " << (digits/10)%10 << ", the ones digit is " << (digits%100)%10 << "\n";
    // Demonstration of cmath
    cout << round(3.8) << "\n";
    // 3) FUNDAMENTAL DATA TYPES IN C++
    // We have already encountered ints and doubles
    int an_integer = 6;// integer values, great for counting and indexing
    double a_double = 2.77215; // great for doing calculations with
    char a_character = '$'; //Individual characters on your keyboard
    string a_name = "Michael James Murray"; // We will talk a lot more about these later on...
    cout << an_integer << " " << a_double << " " << a_character << " " << a_name <<
    "\n";
    // 4) BOOLEANS
    // Booleans variables can either be true or false, this is often represented on your computer as 1 or 0
    
    bool a_bool = true;
    cout << a_bool << boolalpha << a_bool << "\n"; //boolalpha prints as true and false instead of 1 and 0.
    // Arithmetic with Booleans allows us to perform logical operations AND and OR
    bool p = true; // e.g., My name is Michael
    bool q = false; // e.g., I speak fluent French
    // One way to implement logic using arithmetic..
    bool p_and_q = p*q;
    bool p_or_q = p+q;
    cout << "p and q: " << p_and_q << ", p or q: " << p_or_q<< ", not q:" <<
    bool(true-q) << "\n";
    // C++ does this for us though already through logical operators, will look at this in future
    return 0;
}


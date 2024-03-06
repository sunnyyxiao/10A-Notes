//
//  init_con_demo.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/27/23.
//

/*
 AGENDA: in this short demonstration we will look at why constructors and initializer lists are a
 good idea!
 Notes (not done in-class)
 */


#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <string> // Allows certain string operations
#include <cmath> // Includes a load of useful math related functions like round, max etc.
#include <vector>// allows us to use the vector class
using namespace std; // "Tells computer where to look for various functions"


// ----------------------------------------------------------------------------
// Let's consider two structs, the first of which A is really to just demonstrate

struct A{
    A()             {cout << "First Constructor\n";}
    A(int x)        {cout << "Second Constructor\n";}
    A(int x, int y) {cout << "Third Constructor\n";}
};


struct B{
    A a1, a2, a3; // Member variables are always created in the order in which they are declared!
    
    B()                                    {}
    B(int x)        : a2(0), a1(), a3(0,0) {}
    B(int x, int y) : a2(0), a3(0,0), a1() {}
};


int main(){
    
    // An interesting observation from the output of the following: the order of the initializer
    // list is not the order in which the objects are created!
    B b2(0);
    B b3(0,0);
    cout << "\n";
//    // Perhaps more interesting is the output of the following! When no initializer list is specified each of the member variables is constructed using the default constructor of A
    B b1;
    /*
     Observation: if you don't specify an initializer list then the default constructor for each
     object will be used to construct it. This can be problematic though! In particular, if there
     is no default constructor then you won't be able to build!
     
     Conclusions:
     Always initialize your member variables using an initializer list. If you don't then in some
     sense an implict initializer list is used where the default construct for each member
     variable is called. This has two downsides
     
     1) Regardless of how you assign values to your member variables inside of your function
     call, they will first be constructed and initialized using the default constructor. This
     isn't obvious, and could lead to unanticipated consequences.
     
     2) If the type of the member variable dosn't have a default constructor, as some might not,
     then this will not allow your program to build! For instance, if we replaced the default
     constructor of A with default values then this code wouldn't build.
     
     Some tips for best practice:
     - Generally better to define and use multiple, explicit constructors than default values
     - Always initialize member variables using an initializer list
     */
    
}


//
//  class1.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/22/23.
//

#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <string> // Allows certain string operations
#include <cmath> // Includes a load of useful math related functions like round, max etc.
#include <vector>// allows us to use the vector class
#include "Frac.hpp"
using namespace std; // "Tells computer where to look for various functions"

//Class vs struct
class A{
    int x;
    A(int _x):x(_x){}
    void print(){
        cout << "x has value " << x << "\n";
    }
};

struct B{
    int x;
    B(int _x):x(_x){}
    void print(){
        cout << "x has value " << x << "\n";
    }
};

int main(){
    Tracker t(3);
    //can't update count through this method
//    t.x = 1;
//    t.x = 3;
//    t.x = 4;
//    cout << t.x << " " << t.count << endl;
    t.mutate_x(4);
    t.mutate_x(-1);
    t.mutate_x(12);
    
    cout << t.get_x() << " " << t.get_count() << endl;
    
    /*
     Structs vs classes
     A class and a struct are exactly the same aside from one important difference, by defuault. A member of a struct is public, while a member of a class is private.
     */
    
    /*
     Testing class vs struct
     A a(0);
     a.x +=1; // not allowed as private by default
     a.print(); // not allowed as private by default
     */
//    B b(0);
//    b.x+=1;
//    b.print();
    
    {
        /*
         Let us now work through and write an example, building a class for Fractions! Requirements
         1) Constructors: three constructors, for two inputs, integers and 0. Should clean and simplify fraction representation!
         2) Print a fraction
         3) Check if two fractions are equal
         4) add
         5) multiply (two, one for fraction, one for integer)
         6) invert
         */
        Frac x(1,2);
        Frac y(1,6);
        cout << boolalpha << x.is_equal_to(y) << endl;
        Frac z = x.add(y);
        z.print();
        x.add_update(y);
        x.print();
        Frac a = x.multiply(y);
        a.print();
        a.invert();
        a.print();
    }
    
    return 0;
}

#include <stdio.h>

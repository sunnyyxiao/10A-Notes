//
//  header_demo.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/1/23.
//

#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <string> // Allows certain string operations
#include <cmath> // Includes a load of useful math related functions like round, max etc.
using namespace std;

#include "functions.hpp"

int main(){
    /*
     Two functions
     - greet
     - add two doubles
     */
    greet("Mike");
    cout << add_doubles(2.5,1.5) << endl;
    return 0;
}


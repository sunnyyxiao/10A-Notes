//
//  Lec12.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 10/25/23.
//

//FUNCTIONS

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/* Function declaration and definition involves following:
 - writing a function signature
 - writing a docstring describing purpose of function, inputs, output variables
 - write body of function (Sequence of instructions)
 - returning a value (maybe)
 
 type_returned function_name(type1 arg1, type2 arg2...)
 {
    Docstring
    Function body or definition
 }
 */

//Example: my_max function, returns the bigger of two doubles
double my_max(double x, double y){
    /**
    Function compares two doubles and returns the larger of them
     @params double x and y are to be compared
     @returns biggest of x and y!
     */
    if (x>y){
        return x;
    }
    return y;
}

//Example: prob_bday function: assume birthdays are independently and uniformly distributed across the year, given an integer number of students return the probability it is someone's birthday
double prob_bday(int n){
    return 1-pow(364/365.0,n);
}

//Implement a procedure (void)
void hb_song_procedure(string name){
    cout << "Happy birthday to you!\n";
    cout << "Happy birthday to you!\n";
    cout << "Happy birthday dear " << name << "!\n";
    cout << "Happy birthday to you!\n";
}

//implemented as a pure

string hb_song_pure(string name){
    string s1 = "Happy birthday to you!\n";
    string s2 = "Happy birthday dear " + name + "!\n";
    string hbd_song = s1 + s1 + s2 + s1;
    return hbd_song;
}

int my_pow(int x, int exponent){
    /**
     Computes and returns x to the power of the exponent
        @param x int storing the value of the base
     @param exponent int strong the value of the exponent
     @returns int of x to the power exponent
     */
    double power = x;
    for (int i = 1; i<exponent; ++i){
        power*=x;
    }
    cout << x << " to the power of " << exponent << " is " << power << "\n";
    return power;
}

int main(){
    //functions we've seen before, square root and power
    
//    int i = 4; double x = 2, y = 1/2.0;
//    cout << pow(x,y);
    //if y = 1/2, y = 0, so pow (x,y) = 1
    
    int a=1,b=3;
    cout << my_max(a,b) << " is the larger number\n";
    
    int c = 60;
    cout << prob_bday(c) << " is the probability of having a birthday today";
    
    string name = "Mike";
    cout << "Procedure: \n";
    hb_song_procedure(name);
    
    cout << "Pure: \n";
    cout << hb_song_pure(name);
    
    cout << my_pow(2,3) << "\n";
    
/* The main function acts as a hub for calling other functions to perform certain tasks and operations. This helps break down the code into small, reusable pieces, each performing a specific task, with a consistent interface. This makes code a lot more efficient to write, easier to comprehend and therefore debug.
    C++ doesn't support declaration and definition of local functions, so we can't write a function typically inside another pair of {}
 */
    
    /* Procedures versus pure functions
     We can write a function to output the happy birthday song anytime it's someone's birthday
     - first way is to output to the console inside the function and return nothing, functions like this are often referred to as procedures
     - a second way might be to construct an appropriate string for the song happy birthday inside the function, return it to the main function and then output to console there; this is often referred to as a pure function
     
     */
    return 0;
}

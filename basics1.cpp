//
//  Lec2.cpp
//  pic10A
//
//  Created by Sunny Xiao on 10/02/23.
//

// For the first few weeks of this course I recommend you use this file as the basis for your code! Just add instructions to the main function!

// Note that we will cover header files in more detail further down the line
#include <iostream> // iostream stands for standard input output stream, is a library that supports our program in reading and writing to the console!

// A scope is basically a construct used to isolate groups of variable and function names. This allows one to reuse certain variable and function names in different contexts, which can be very useful. Don't worry about it too much for now! We will look at them a bit more later in the course!

using namespace std; // means we can just write "cout<<..." instead of "std::cout<<...", more on this later!

// Note tabs and whitespaces are ignored by the compiler!

// All C++ programs need a main function: this acts as the entry point and central building block of your program from which other routines are called. For historical reasons main is expected to to return an integer, hence by contention we return 0 at the end! Exit code 0 means your code has run.
int main(){
    // Your code goes in here
    cout<<"Hello World!\n"; // print Hello PIC10A
    
    // Performing calculations in C++
    cout << "2 + 5 is " << 2 + 5<< "\n";
    cout << "2*5 is " << 2*5<< "\n";
    cout << "3/2 is " << 3/2 << "\n"; // Integer division returns an integer! Does floor operation
    cout << 3/2.0 <<"\n"; // To represent fractions we need to use floats, i.e., 2.0 instead of 2
    
    // To a computer, and just like everything else, numbers are represented as sequences of bits. Representations of different types of numbers (e.g., integers vs rationals) vary based on the number of bits (typically 32 or 64 bits) and the way in which the sequence of bits is interpreted. In C++ integers are represented differently to rationals, which instead use a floating point. Floats are floating point representations of numbers with 32 bits, while doubles are floating point representations of numbers with 64 bits. As a rule of thumb, floats give you 7 decimal points of accuracy while doubles give you 15. This subject will be covered in more detail in your next discussion session.
    
    // Tip: when doing calculations use brackets to avoid confusion! What is the output of the following?
    cout << 4*5/10 << 3.0/2*4 << 2/3*3 << "\n";
    
    // Remainder operator is %
    cout << "10/3 is " << 10/3<< " remainder "<< 10%3<< "\n";
    
    // Calculating with variables
    int x = 2; // Declares a variable x and gives it the value 2
    float y = 0.5; // Declares a variable y and gives it the value 0.5
    int z = x + y;// Declares a variable z and gives it the value x+y
    cout << "z is " << z << "\n";
    
    // Variables can also hold indiviual characters, and sequences or strings of characters
    string my_string = "The hitchhiker's guide to the galax";
    char my_char = 'y';
    cout << my_string << my_char << "\n";
    
    // We will cover variables in C++ along with the fundamental data-types in the next lecture. To finish off lets look at console in. This is the analog of cout, but instead of the computer giving us text via the console, it allows us to give the computer text via the console.
    
    // Demonstrate input via cin: case 1, string
    cout << "What is your name? ";
    string name;
    cin >> name;
    cout << "Hi " << name << "!\n";

    //  Use cin to double a user inputted number
    cout << "Enter an integer: ";
    float numb;
    cin >> numb;
    cout << "Doubling " << numb<< " gives " << 2*numb << "\n";
    
    // You can also input multuple things at the same time
    cout << "Enter three integers: ";
    int i1, i2, i3; // Note here we have declared three variables but we haven't initialised them yet as want the user to!
    cin >> i1 >> i2 >> i3;
    cout << i1 + 1 << " " << i2 + 1 << " " << i3 + 1 << "\n";
    
    
    return 0; // If int main returns 0 then implies the code has run, meaning 0 errors!
}


//
//  datatypes1.cpp
//  pic10A
//
//  Created by Sunny Xiao on 10/06/23.
//

/*
 Agenda
 1) Comparison operators and booleans
 2) Exploring the bit representations of objects of different types
 3) Casting between types
 */

#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <cmath> // Includes a load of useful functions like round that we will demonstrate
#include <iomanip> // Include so as to be able to change the way numbers are represented
using namespace std; // "Tells computer where to look for various functions"

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/* Don't worry about understanding this! Is here purely to allow me to print out binary representation of an object. */

#include <bitset>
#include <climits>

// This piece of code allows us to inspect the binary sequences stored in memory! You shouldn't really need to use it outside this class, is just to demonstrate what is actually being stored in the memory location of a variable.
template<typename T>
void show_binrep(const T& a){
    const char* beg = reinterpret_cast<const char*>(&a);
    const char* end = beg + sizeof(a);
    while(beg != end){
        cout << std::bitset<CHAR_BIT>(*beg++) << ' ';
        cout << '\n';
    }
}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int main(){
    
    
    /*
     1) Wrapping up with booleans
        - comparison statements return booleans! https://en.cppreference.com/w/cpp/language/operator_comparison
        - common pitfalls when using comparison operators
            - aside: using setprecision (decimal precision displayed on console https://cplusplus.com/reference/iomanip/setprecision/) and scientific
            - integer division
            - approximation errors, e.g., 6/5.0 - 1 - 1/5.0
            
        - Logical operators `&&` (logical AND), `||` (Logical OR) and `!` (Logical NOT) [Draw out logic table]. Can also use `and`, `or` and `not`. Note, distinct from bitwise operations we won't discuss here
     */
    
    {
        /*
         Comparison operators you should think of as functions, they have two parameters, a left and a right hand (hence they are called binary operators) and return a boolean.
         - `<` and `>` are strictly less than or greater than respectively.
         - `<=` and `>=` are less than or equal and greater than or equal respectively.
         - `==` and `!=` are equal or not equal respectively
         */
        
        // The following example returns true
        cout << boolalpha <<  (3<=5) << "\n";
        // Note: boolalpha just means when we output to the console we see true or false instead of 1 and 0
        cout << boolalpha << ('a' == 'b') << "\n";
        
        
        // You also need to be careful of approximation errors with floats and doubles! The following is false as the left hand argument is just very small instead of exactly 0
        bool b = (6/5.0 - 1 - 1/5.0==0);
        cout <<  b << "\n";
        cout << (6/5.0 - 1 - 1/5.0<0) << "\n";
        
    
        // Setprecision without scientific sets the number of digits to be displayed, with scientific it is the number of digits after the decimal point.
        cout << setprecision(2) << scientific << 123456*pow(10,-5) << "\n";
    }
        
        /*
         We also have logical operators
         - `&&` or `and` for Logical AND (true if and only if both arguments are true)
         - `||` or `or` for Logical OR (false if and only if both arguments are false)
         - `!` for Logical not (true if and only if argument is false), note this is a unitary operator, meaning applies to one thing not two
         */
    {
        // Examples
        int x = 5;
        bool b1 = (x>2)and(x==5);
        
        // We can combine boolean expressions
        bool b2 = !((4>3)&&(3/2==1))||(x%2 == 1);
        cout << b1 << " " << b2 << "\n";
    }
    
    /*
     2) Demonstrating show_binrep: objects versus bit sequences!
        - demo show_binrep
        - booleans
        - ints and unsigned ints: in particular -1 and 2^32
        - doubles and size_t
        - floats,
        - characters and the ASCII table https://www.asciitable.com/
     */
    
    /*
     Non-examinable: explaining bit representation of floats
     Floats have the same number of bits (32) as integers, but they are again interepreted differently. One commone approach to map bits to floats is as follows
    i) Like an int the most significant bit is interpreted as the sign.
    ii) The next 8 bits represent the exponent and work like an 8 bit int (e.g., 00000111 = 7)
    iii) The remaining 23 bits are called the fraction, for instance 1100...0 = 1*2^-1 + 1*2^-2 + 0*... = 0.75
    These three values are combined as follows be interpreted as ratios
    -1^(sign) * 2^(exponent - 127) * (1+fraction)
     */
    {
        
        
        /*
         Some observations:
         - a is a char, chars only need 8 bits, one byte!
         - booleans are also represented with only one byte, note byte is the smallest piece of addressable memory. True has same value as integer one and false the same value as integer 0
         - ints use 32 bits
         - a is given the binary string that also represents integer 97
         - binary representations for 97 as a float and 97 as an int are completely different! This is because they map binary sequences to numbers in very different ways, see notes on floats below.
         */
        int x = 97;
        char a = 'a';
        bool b = true;
        float f = -97;
        show_binrep(b);
        cout << "\n";
        show_binrep(x);
        cout << "\n";
        show_binrep(a);
        cout << "\n";
        show_binrep(f);
        cout << "\n";
    }
    
    /*
     3) Casting between types
     - type casting: converting an expression from one thing to another
     - Explicit (static) casting with static_cast<type>(arg) versus assignment to variables.
        (Note: static means is done at the time of compilation, not runtime!)
     - Moving between integers and chars: 'a' versus 97
     - Exercise: capitalize a character using arithmetic of characters
     - Type casting dosn't always preserve the binary sequence, think float to integer. We label floats with a completely different scheme so the bit strings for the same underlying number, e.g., 3, look very differet!
     */
     
    {
        // Examples of implicit cast
        int x = 3.5; // float to an integer when initializing variable
        int b1 = (6 == 6.5); // First casts integer 6 to a float, then does equivalance operator between two floats and returns a bool, then casts the integer to a bool
        cout << b1 << "\n";
    
        // Also get implicit casts when you do arithmetic with characters, whats happening in the following?
        char new_char = 'a' + 2;
        cout << new_char << "\n";
        
        // Challenge: try and capitalize the character a using only arithmetic between different characters!
        char new_char2 = 'a' - ' ';
        cout << new_char2 << "\n";
        
        // You can also explicitly cast using static_cast<target_type>(argument), for example
        cout << static_cast<bool>(0) << "\n";
    }

    return 0;
}


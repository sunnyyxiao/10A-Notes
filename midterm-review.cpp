//
//  midterm-review.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/3/23.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
/*
 Agenda: we have looked at functions quite recently, so will focus on topics
 earlier on in the quarter.
 - What is a type, what is a literal?
 - Review of some basic operations we can do in C++ on different types (arithmetic, comparison, logical)
 - What are variables and references in C++, what are the rules are declaring, initializing and using them?
 - What is a scope, and how do you identify the scope of a variable?
 - How do we interact with our program via the console? How does the input buffer work? What are the rules of cin >> ..., cin.fail(), cin.peek() and cin.get()?
 - Control flow: conditional statements and the three types of loop
*/
int main(){
    /*
     1) What is a type, what is a literal?
        - A type in C++ determines how a piece of data is stored (e.g., amount of memory), interepreted (e.g., the same bit string for a float and integer represent very diffent numbers!) as well as the set of operations that can be applied to it. To date we have seen a number of types, e.g., bool, int, float, double, char
        - A literal is a particular sequence of bits along with a type. For example 5 is a int literal. The value of a literal is fixed and cannot be changed, in particular we cannot assign to a literal! There are five types of literal we have encountered
            i) boolean literals: true and false (1, or 0)
            ii) integer literals: represent a range of integers
            iii) float literals: represent rational numbers or decimals up to some finite level of precision
            iv) character literals: represent characters on your keyboard
            v) string literals: hold a sequence of character literals
     */
    /*
     2) Review of some basic operations we can do in C++ on different types
     */
    {
        /*
         floats and integers
         - arithmetic operations behave sort of as expected...
         - watch out for integer division! Chops of the decimal points
         - operations resolved first according to BODMAS (Brackets, Orders, Division, Multiplication, Addition, Subtraction), when there is a tie then left to right
         */
        // 10 or 14?
        cout << 2*3+4 << endl;
        // 14 or 24
        cout << 2+3*4 << endl;
        // 1 or 0.25 or 0?
        cout << 5/10/2 << endl;
        // 1 or 0.25 or 0?
        cout << 5.0/10/2 << endl;
    }
    {
        /*
         Booleans and comparison operators:
         - comparison operators take two objects (ints, floats, chars ....) and return a boolean. Generally the types of the object should be the same otherwise will result in error or implicit conversion. Examples <=, =>, ==, !=
         - boolean or logical operators take in two booleans and return a boolean: &&,||,!
         */
        // Comparison operators
        cout << boolalpha << (4 == 3) << endl;
        cout << (10.5 >=6 ) << endl;
        cout << ('a' == 97) << endl; // implict conversion between two types! Look at ASCII table
        // Logical operators
        cout << (true && false) << endl;
        cout << (true || false) << endl;
        cout << !true << endl;
        cout << (4> 4.0) << " " << endl;
        cout << (abs(4.0-4)<pow(10,-10)) << " " << endl;
        
        cout << boolalpha << ((true) || (false)) << endl;
        cout << boolalpha << !true << endl;
    }
    /*
     3) Variables and references
    */
    {
        /*
         Variables are reserved pieces of memory, identified by a specifc name or identifier, which can be used to store data of a certain type. We declare (create) a variable as follows, type identifier; We can also initialize at the same time as declaring either through assignment or by calling a constructor with parantheses
         type identifier = value;
         type identifier(value);
         */
        // Declaring and initializing
        int x = 5;
        double y(6);
        char c = 'f';
        string s = "abc123";
        /* Assigning to a variable copies or writes new data into its memory location.
         - Assigning a literal to a variable stores the value of the literal in the memory location
         - Assigning a variable to another variable stores the value of the right hand variable in the memory location of the variable on the left.
        */
        x = x+5+y; // computes x+5+y and then stores in the memory location of x
        // A variable cannot be redeclared once it has been declared and the type of a variable cannot be changed
        //int x = 10; // uncomment and will not run
        // We cannot have two variables with the same name in the same scope...this will be     interpreted as an attempt to define / declare it!
        // char x = 'a';
        // const variables are read only, we can access the data they hold but cannot write over the    data / assign to the variable
        const int z = 2;
        // z = 5; // will result in an error
    }
    {
        /*
        References are aliases (alternative names or identifiers) for existing
        variables.
        - they must be initialized (bound) to an existing variable when declared
        - for the rest of the runtime of the program a referene remains bound to the same variable (cannot be bound to an alternative variable)
        - In particular, assignment to a reference copies new data to the memory location the reference is bound to.
         */
        int x = 2;
        int& r = x; //r is now another name for x
        r = 4; // x now holds the value 4
        // A const reference is a read only or alias for an existing variable
        const int& q = x;
        // q = 10; // will result in an error
    }
        /*
        4) Scope: a pair of braces {} delimits a scope: inside these braces we can define local variables which exist only for the runtime of the instructions between the braces. Conditional statements, loops and functions all have their own scope
        */
    { // Scope 1
        int x = 2; // this is a variable local to scope 1!
        double y = 3;
        {
            int x = 3; // This is a variable local to scope 2! This x and the x in scope 1 are not the same
            // this returns 5 not 6 as we use the scope 2 x (this is the x in the current scope) and the scope 1 y (there is not variable y in scope 2 so we look in the encompassing scope which is scope 2)
            cout << x+ y << endl;
            char y = 'a';
            {
                bool x = true;
                cout << x << " " << y << endl;
            }
        }
    }
        /*
        5. Interaction with our programs through the console. We output data from our program to the terminal or console using cout. We input data usng cin. cout is easy to use, but cin can be a bit tricky.
         */
    {
        /*
        The input buffer stores a sequence of characters in the order we type them When we cin >> something the following occurs,
        1. If there is nothing in the buffer, allow the user to enter input. As the user types an input each character is stored in order in the input buffer, a sequence of bytes in memory, the user is allowed to keep typing until they hit enter, at this stage the '\n' character is added and then proceed to step 2.
        2. The tracker or arrow of the input buffer moves past all whitespace (spaces, tabs, '\n').
        3. Steps 1 and 2 are repeated until a character that is not whitespace is encountered.
        4. When possible, interpret the largest subsequence of non-whitespace characters as something of the same type as the type of the variable being assigned to by cin, assign this data to the variable, and strip it from the buffer. However,never move past whitespace in this step.
         */
//        cout << "Enter something: " << endl;
//        int i; char c; string s;
//        cin >> i >> c >> s;
//        cout << s << " " << c << " " << i << endl;
        // Note you can clear the input buffer using the following command
        // cin.ignore(std::numeric_limits<int>::max(),'\n');
    }
    {
        /* If you try and cin something to a variable which cannot be assigned to said variable then it can break. If this occurs for instance with cin >> var then
         - 0 is assigned to var
         - cin.fail() returns true
         - no further cin >>... will have any effect
         */
        // int x = 4;
        // cout << "Enter a character: " << endl;
        // cin >> x;
        // cout << cin.fail() << " " << x << endl;
        // cin.ignore(std::numeric_limits<int>::max(),'\n');
    }
    {
        /*
        cin.peek() looks at the next value still left in the the input buffer. Note all inputs are treated as chars, but cin.peek() returns the integer of said character corresponding from the ASCII table
         */
         cout << "Enter a digit: " << endl;
        int x;
        cin >> x;
         cout << cin.peek() << endl;
        // cin.ignore(std::numeric_limits<int>::max(),'\n');
        /*
        cin.ignore() removes the next character in the input buffer
         */
        // cout << "Enter three digits seperated by space: " << endl;
        // int a,b; cin >> a;
        // cin.ignore();
        // cin >> b;
        // cout << b << " " << a << endl;
        // cin.ignore(std::numeric_limits<int>::max(),'\n');
    }
        /*
        6. Conditional statements and the three types of loop
        - if, else if and else statements are used to perform branching (run different blocks of code depending on various conditions)
        - for loops are used to run a block of code a predefined number of times
        - while loops are useful for running a block of code a number of times which is unknown to the programmer at the time of writing.
        - do while loops are the same as while loops but always run the loop once.
         */
    {
        /*
         Example 1: Fibonacci numbers, print the odd ones larger than 1 but smaller than 80.
         */
        int prev = 0;
        int curr = 1;
        int next;
        do{
            next = prev + curr;
            if (next%2!=0){
                cout << next << endl;
            }
            prev = curr;
            curr = next;
        }while(prev + curr <80);
        /*
         Example 2: we can for loop on non-integers values
         */
        string s = "a";
        for (;s.length()<=10; s+=s){
            cout << s << endl;
        }
    }
        return 0;
}



//
//  Lec14.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 10/30/23.
//

/*
AGENDA
- recap of swap
- references
- pass by reference versus pass by value
- file scope and global variables
- introduction to header files
*/

#include <iostream> // Allows us to use cout and cin to read and write via the console

#include <string> // Allows certain string operations

#include <cmath> // Includes a load of useful math related functions like round, max etc.
using namespace std; // "Tells computer where to look for various functions"

// If you want to use global variables you can put them normally at the top here. You should only really use const global variables.
const double g_pi = 3.14;

// ---------------------- Our bad version of integer swap ---------------------

void my_bad_swap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}

// ---------------------- Our version of integer swap ---------------------

void my_swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

// ---------------------- A meaningless function, but useful for checking our understanding of references! ---------------------
void meaningless(int& a, int b, int& c){
    int d = 5;
    a += b + c -d;
    b = a*c;
    c = 2*a +b;
}
int main(){
    /* 1. Recap of swap
     Recall from last lecture we tried to implement a swap function but it failed.
     i) First, we can only return one object from a function, and we need to update
     two variables back in main. Therefore we couldn't implement swap as a pure
     function.
     ii) Second, when we tried to implement swap by writing the function as a
     procedure (has implicit effects) we found that this also didn't work as all our
     operations inside the function only apply to the local variables inside of the
     function.
     */
    // Reimplement our procedure implementation of swap
    //    {
    //    // Test my_swap function
    //        int a = 1; int b = 10;
    //        my_bad_swap(a,b);
    //        cout << a << " " << b << "\n";
    //    }
    //    {
    //    // Simulate my_swap in main
    //        int a = 1; int b = 10;
    //        {
    //            int x = a;
    //            int y = b;
    //            int temp = x;
    //            x = y;
    //            y = temp;
    //        }
    //        cout << a << " " << b << "\n";
    //    }
    // We can solve this issue using references, these act as local names for a variable back in the main function!
    /* 2. References:
     A reference is best thought of as an alternative name or alias for an existing
     object. Initializing and declaring a reference looks very similar to what we do for
     a variable, we just put an & between the type and the variable name. There are
     however some additional rules.
     
     i) A reference just like a variable has a type. This makes sense, a reference acts as an alterantive interface to a piece of memory and we need to know the type in order to interpret the bits stored there correctly properly.
     
     ii) A reference has to be declared and initialized at the same time.
     
     iii) It isn't possible to assign a literal to a reference. It is best to think of a reference as an alternative name for an existing variable.
     
     iv) References cannot be reassigned, for the rest of the time they are in scope they are bound to the variable they were initialized to. We can use either the variable name or the reference to interface with the data. In particular, at initialization the assignment operation binds the reference or alias to a variable. After that assignments to a reference are just copying data into the location the reference is bound to!
     
     v) A reference can be bound to a const type object. But references themselves can also be const! A const reference is a reference which has read priveledges on the data it is bound to, but not write priveldges.
     */
    //    {
    //    double d1 = 10.6;
    //    const double d2 = 10.6;
    //   /* const*/ double& r1 = d1;
    //
    //    d1 = 2*d2;
    //    r1 = d1 - 1.2;
    //    cout << d1 << " " << r1 << " " << d2 << "\n";
    //
    //    int i = 3, j = 45;
    //    int& r = i;
    //    cout << "The value of i is " << i << ", the value of r is " << r <<"\n";
    //    i = 6;
    //    cout << "The value of i is " << i << ", the value of r is " << r <<"\n";
    //    r = 5;
    //    cout << "The value of i is " << i << ", the value of r is " << r <<"\n";
    //    r = j;
    //    cout << "The value of i is " << i << ", the value of r is " << r <<"\n";
    //    }
    // References can be useful ways of mutating or changing data stored in global variables
    //    {
    //    // Nested scope example with references
    //        int a = 1;
    //        int b = 10;
    //        {
    //            int&r = a;
    //            r *= 2+b;
    //            int b = 24;
    //        }
    //        cout << a << " " << b;
    //    }
    /* 3. Pass by reference versus pass by value
     The first thing we do when we call a function is assign arguments to parameters. Recall
     - An argument is some literal value the function recieves from main. Sometimes we pass the function a gloval variable as an argument, recall when we assign one variable to another we just copy its literal or value over.
     - A parameter is a local variable, created inside the local scope of the function call.
     - Arguments are assigned to parameters based on their order. In effect then we send information into a function by copying it into local variables. This is called pass by value! If instead of using local variables we use local references as our function parameters, then these act as local names for variables back in main. Using references we can therefore implement our swap function!
     */
    {
        // Check new swap function works
        int a = 1; int b = 2;
        my_swap(a,b);
        cout << a << " " << b << "\n";
    }
    {
        //Stimulate new swap function
        int a = 1, b = 2;
        {
            int&x = a;
            int&y = b;
            int temp = x;
            x = y;
            y = temp;
        }
        cout << a << " " << b << "\n";
    }
    
    // Let us now look at rather meaningless function to better check and our understanding of how to use references. Predict the outcome of the following (we'll also draw a diagram in class.)
    {
        int yellow = 5;
        {
            int x =1, y =2, z = 3;
            cout << "Before meaningless has run the value of x is " << x << ", the value of y is " << y << " and the value of z is " << z << "\n";
            meaningless(y,y,y);
            cout << "After meaningless has run the value of x is " << x << ", the value of y is " << y << " and the value of z is " << z << "\n";
            cout << yellow;
        }
    }
    /* 4. File scope and global variables
     When we define functions we typically write them above main, note if we write them below then when we call them in main we won't have declared them yet so an error is thrown.
     some_greeting_function("Mike"); // This won't run as function hasn't been declared yet!
     Some general points:
     - Any name (function, variable, reference) can only be called or referenced once it has been declared. In particular, you can only call/reference a name on program lines below the line / after the point the name in question has been declared!
     - The scope of a name are the parts of a program in which the name is recognized. To identify this region first identify the enclosing pair of curly brackets in which the name is declared. The name in question can then be successfully referenced between the point after it is declared and the relevant closing curly bracket.
     - Once a program reaches a closing bracket all associated variables are destroyed
     - If a name is not declared between a pair of opening/closing brackets then it has file scope, i.e., can be referenced successfully anytime after it is declared. Such names have global or file scope. Remember main() is a special function we can view as being called as soon as we run our program.
     - The functions we have written so far, including main, have file or global scope as they are defined outside any pair of enclosing curly brackets. Note, you cannot define functions locally in C++.
     - We can also define global variables outside of main, but this is not a good idea unless they are const... global variables are created at the start of program runtime and are destroyed at the end. They can be accessed from anywhere in your program after they are declared!
     - Instead of using arguments to pass data into functions, we could in theory use global variables... this is a bad idea though, mainly because then the function we write becomes dependent on where ever it being ran having the same global variable. Its also a much less safe way of writing code as the behaviour of this main variable can become hard to predict if it is used inside many functions.
     */
    {
        // Demonstration of points on file scope
        // cout << g_pi << endl; // Global constant variable is in scope
        // cout << greet("Mike"); // Function is out of scope as is declared below main
    }
    /* 5. Header files
     
     We will now introduce and discuss otherways of storing and including our functions than just simply declaring and defining them above int main(). Lets implement two functions.
     - an add function (write as a pure)
     - a greet function like below (write as a procedure)
     We will see there are three options
     i) Write function declarations and definitons all in the cpp file in which int main() is.
     ii) Write function declarations above int main() but write their definitions
     in another cpp file which we include in the build
     iii) Include another cpp in our program file in which functions are declared
     and defined. Note if we include we should't also have this other file in the build.
     iv) Use a header file and another cpp file!
     */
    return 0;
}

      // Don't put functions below main as you won't be able to call them in main! Recall, you can call a name or identifier before it has been declared.


    void greet(string name){
      cout << "Hi " << name << "!\n";
    }


//
//  struct1.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/15/23.
//

/*
AGENDA:
- An overloaded function for calculating the area of different shapes
- Motivating object orientated programming
- A first look at structs
*/

#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <string> // Allows certain string operations
#include <cmath> // Includes a load of useful math related functions like round, max etc.
#include <vector>// allows us to use the vector class
using namespace std; // "Tells computer where to look for various functions"

// ---------------------- Global variable ----------------------
const double pi = 3.14159265358979323846;

// ---------------------- Overloaded functions: procedural ----------------------

//Need to move below once using structs
// Area of rectangle
//double area(double l, double h){
//    return l*h;
//}

// Area of square
//double area(double l){
//    return l*l;
//}

// Area of circle
//double area_C(double r){
//    return pi*r*r;
//}

// ---------------------- Struct definitions just with attributes ----------------------
// Square struct
//struct Square {
//    double l;
//};
//
//// Rectangle struct
//struct Rectangle{
//    double l;
//    double h;
//};
//
//// Circle struct
//struct Circle{
//    double r;
//};

// ---------------------- Overloaded functions: OOP ----------------------
// Area of rectangle
//double area(Square s){
//    return s.l*s.l;
//}
//// Area of square
//double area(Rectangle r){
//    return r.l*r.h;
//}
//
//// Area of circle
//double area(Circle c){
//    return pi*c.r*c.r;
//}

// ---------------------- Struct definitions full ----------------------
// Square struct
struct Square{
    double l;
    
    //no parameters because it is a local function, can only access in the context of a specific instance of a square
    double area(){
        return l*l;
    }
};

// Rectangle struct
struct Rectangle{
    double l;
    double h;
    double area(){
        return l*h;
    }
};
// Circle struct
struct Circle{
    double r;
    double area(){
        return pi*r*r;
    }
};

/*
A note on variable resolution here. In the case of circle, then when we reference a variable r
1) we first look in the member function scope
2) we then look inside the enclosing pair {}, this corresponds to the struct definition so encompasses the object variables!
*/

/* Struct for a Cat object
  - color
  - hungry?
  - pet member function
  - feed member function: updates hungry variable
 */
struct Cat{
    string name;
    string color;
    bool hungry;
    void pet(){
        cout << "Meow!" << endl;
    }
    void feed(){
        hungry = false;
        cout << "Purr" << endl;
    }
    void steal_food_from(Cat& other){
        hungry = false;
        other.hungry = true;
        cout << "Hiss" << endl;
    }
};

/* Struct for a Car object
 - brand
 - miles_done
 - drive(miles) member function: updates miles_done and prints to console
 
 */
struct Car{
    string brand;
    size_t miles_done;
    void drive(){
        cout << ++miles_done << endl;
    }
};

/* Struct for customer
 - name
 - average monthly spend
 - frequency of visits
 */
struct Customer{
    string name;
    size_t average_monthly_spend;
    size_t frequency_of_visits;
};


int main(){
    {
        /*
         From last time, we can compute the area of many different types of shape, but the formula in each case is different. One way to implement this is via overloading, however we run into an issue that to compute the area of both a circle and a square we need just a single double. From last lecture you should appreciate that this will lead to ambiguity.
         */
        // Definitions used to define geometry of various shapes
        
        double r1 = 1;
        double rh = 2;
        double s1 = 1;
        double cr = 1;
        
//        cout << "The area of my circle is " << area_C(cr) << endl;

        //      customer Mike;
        
        //Customer information
        string customer1_name = "Mike";
        double customer1_spend_to_date = 4;
        double customer1_freq = 5;
        
    }
    /*
     In the above we have this messy jumble of variables, subsets of which impliclty represent the properties of certain objects, shapes in our case. We also struggle to implement an area in all cases due to the aforementioned ambiguity. One way to resolve this is to think about our code EXPLICITLY as interactions and behaviours of objects, rather than these objects being IMPLICITLY represented through the transformation of individual variables with function calls. The approach I am referring to is helpfully called object orientated programming (OOP), whereas so far we have mostly designed our programs from a procedural programming mindset (our code is a sequence of function calls manipulating variables).
     */
    {
        // STRUCTS
        /*
         We now introduce the notion of a struct in C++. A struct is a template or set of instructions for how to build something. A struct essentially allows you to bundle variables (object attributes, e.g., color or size of a dog) together! We can think of strings as similar to structs in that they are also in some sense a bundle of variables, i.e., characters.
         */
        // Define instances of objects: to understand a struct vs an instance of a struct think design for a car vs a particular physical example of a car, e.g., your car! We will draw some pictures to help understand what is going on in what follows
        
        //Declare structs, instances of each
        Square my_square;
        Square my_other_square;
        Rectangle my_rec; // Declare instance of a rectangle
        Circle my_circle; // Declare instance of a circle
        
        //We can now also read the value of various object or member variables using the '.' operator
        my_square.l = 2;
        my_other_square.l = 4;
        my_rec.l = 1; my_rec.h = 2;
        my_circle.r = 1;

        //Arguments work on particular objects, expecting particular parameters
//      cout << area(my_square) << " " << area (my_circle) << " " << area(my_rec) << endl;
        
        //Easier to define the function as a member function, inside struct (don't need to overload)
        
        cout << my_rec.area() << " " << my_circle.area() << " " << my_square.area() << endl;
        
        Cat c1;
        c1.name = "Delilah"; c1.color = "tortoise"; c1.hungry = false;
        
        Cat c2;
        c2.name = "Augustus"; c2.hungry = true;; c2.color = "ginger";
        
        c1.pet(); c2.pet();
        c2.steal_food_from(c1);
        cout << boolalpha << c1.hungry << " " << c2.hungry << endl;
        
        //General template
        /*
         struct Name{
         member variables...
         member functions...
         }
         */
    }
    return 0;
}


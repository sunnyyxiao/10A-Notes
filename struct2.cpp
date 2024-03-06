//
//  struct2.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/17/23.
//

#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <string> // Allows certain string operations
#include <cmath> // Includes a load of useful math related functions like round, max etc.
#include <vector>// allows us to use the vector class
using namespace std; // "Tells computer where to look for various functions"

/*
 AGENDA:
 - recap of structs from last time
 - where should we define member functions? Introducing the scoping operator ::
 - constructors
 - const instances of a struct objects
 */

// ---------------------- Global variable ----------------------
const double pi = 3.14159265358979323846;


// ---------------------- Struct definitions ----------------------
// Rectangle struct: declared and defined inside
struct Rectangle{
    double l;
    double h;
    /*
     A CONSTRUCTOR is a special member function called when an object of this struct type is
     declared and is used to initialize it.
     - It dosn't return anything, which makes sense as it is really just initializing the
     thing you just created...
     - It always has the same name as the struct
     - It can have parameters, which you can then use to assign to member variables
     -
     */
    Rectangle();
    Rectangle(double _l);
    Rectangle(double _l,double _h);
    double area() const;
    void stretch(double factor);
//    Rectangle(){
//        l = 1;
//        h = 1;
//    }
//    Rectangle(double _l){
//        l = _l;
//        h = _l;
//    }
//
//    Rectangle(double _l, double _h){
//        l = _l;
//        h = _h;
//    }
//    double area(){
//        return l*h;
//    }
//    void stretch(double factor){
//        l*=factor;
//        h*=factor;
//    }
};

Rectangle::Rectangle():l(1),h(1){}
Rectangle::Rectangle(double _l):l(_l),h(_l){}
Rectangle::Rectangle(double _l,double _h):l(_l),h(_h){}
double Rectangle::area() const {return l*h;}
void Rectangle::stretch(double factor){
    l*=factor;
    h*=factor;
}
    
//Circle struct declaration

//put this into structs hpp file
struct ColorCircle{
    double r;
    string color;
    
    ColorCircle();
    ColorCircle(double _r, string _c);
//    ColorCircle():r(1),color("blue"){}
//    ColorCircle(double _r, string _c):r(_r),color(_c){}
    
    double area();
    void stretch(double factor);
    void paint (string _c);
//    double area(){return pi*r*r};
//    void stretch(double factor){r*=factor};
//    void paint(string _c){color = _c};
};

//put this into "structs" cpp file:
ColorCircle::ColorCircle():r(1), color("blue"){}
ColorCircle::ColorCircle(double _r, string _c): r(_r), color(_c){}
double ColorCircle::area(){return pi*r*r;}
void ColorCircle::stretch(double factor){r*=factor;}
void ColorCircle::paint(string _c){color = _c;}

//    Rectangle(double _l1, double _l2){
//        l1= _l1;
//        l2 = _l2;
//        assert((l1>=0)&&(l1>=0));// Ensures that constructing a valid rectangle
//        // Assert checks the condition in paranthesis: if is True then nothing happens, if False then throws an exception and program stops running!
//    }
//    
//    // We can also overload constructor to initialize depending on input parameters
//    // 1 parameter case maybe we want to initialize as a square
//    Rectangle(double l){
//        l1 = l;
//        l2 = l;
//        assert((l>=0));
//    }
//    
//    // No parameters, set to 0, no parameter case is known as the default
//    Rectangle(){
//        l1 = 0;
//        l2 = 0;
//    }
//    
//    
//};


/*
 Below we define the area function for Circle objects. The area function we are explitly referencing (i.e., rectangle or circle) is controlled using the :: scoping operator. It basically says I am referring to the area() function inside the Circle struct definition. Basically we can think of identifiers in any program we write as being organized into certain groups, e.g., scopes. As we have seen already we might have the same identifier in multiple groups. So to expliclity refer to a specific object we use the notation group_name::identifier
 */
//double Circle::area(){return pi*r*r;}
/*
 Why might we do this? Again it comes down to how we organize our code. If we want to share our struct definitions across multiple programs, then for the same reasons as we gave for functions we probably want to use header files. For long, complicated structs with many complicated member functions, its better to declare and define them in a .cpp file, but include them in other cpp files using a header file which only has declarations.
 */

// Like other member functions can declare and define later/ do definition in another file.
//Circle::Circle(double _r): r(_r){assert(r>=0);}
//Circle::Circle():r(0){}


int main(){
    
    /* Recap from last time
    - structs are templates for building instances of objects with custom novel properties, think of them a bit like a custom data type
    - they allow you to create objects which bundle togethre member variables and member functions, often providing a more natural way to write code which involves the manipulation of ceertain abstracted objects
     */
    {
        // Creating an instance of a rectangle
        Rectangle r1;
        r1.l = 1;
        r1.h = 2;
        cout << "Area pre-stretch is " << r1.area() << endl;
        r1.stretch(2);
        cout << "Area post-stretch is " << r1.area() << endl;
        
        /* Key points:
         - structs are templates for building instances of objects with custom with novel properties, think of them a bit like a custom data type!
         - they allow you to create objects which bundle together member variables and member functions, often providing a more natural way to write code which involves the manipulation of certain abstracted objects. For example, instead of thinking about seperate collections of wallets, products, names and purchasing recommendations, why don't we instead think about a single collection of customers?
         */
    }
    /*
     Constructors and initializer lists
     So far when we create a struct object we then have to go ahead and manually make assignments to its member variables... for things like strings and vectors we didn't need to do this, instead we could declare and intiialize at the same time
     */
    //Example of declaring and initializing struct like objects at the same time
//    string s = "Mike";
//    cout << s << endl;
//    vector<int> v(10,1); //10 elements, each is going to be 1
//    for (int i = 0; i<=v.size()-1;i++){
//        cout << v[i] << " ";
    /*
     A constructor is a type of member function which initializes member variables. If you don't declare one then a default one is used. Constructors have the following prpoerties:
     - they have the same name as the class
     - they can be overloaded like any other function, this allows you to initialize a struct object in multiple different ways
     - assignment can be carried out either by assignment inside function or through an intiializer list
     */
    
    //Let us now write three different constructors for the rectangle class
    Rectangle r1;
    Rectangle r2(5);
    Rectangle r3(2,3);
    
    cout << r1.l << " " << r1.h << " " << r1.area() << endl;
    cout << r2.l << " " << r2.h << " " << r2.area() << endl;
    cout << r3.l << " " << r3.h << " " << r3.area() << endl;
    
    //An initializer list is initialized after the parameter
    {
        ColorCircle c1;
        ColorCircle c2(3, "green");
        cout << c1.r << " " << c1.area() << endl;
        cout << c2.r << " " << c2.area() << endl;
        c1.stretch(2);
        c1.paint("red");
        cout << c1.area() << " " << c1.color << endl;
    }
    
    // Scope operator
    {
        // We can actually define our member functions inside (as per Rectangle) or outside (as per Circle). We do this via the scoping operator :: (see above)
    }
    
    //Const instances of a struct
    const Rectangle r5;
    Rectangle r4(1,2);
    cout << r5.l << " " << r4.l << endl;
//    r5.l = 5;
    cout << r4.area() << endl;
    cout << r5.area(); //compiler does not check if the member function changes any variables if you try to call a member function --> write all functions as const
  /*
         Why do we observe this behaviour? The const basically tells the compiler that the implicit argument, i.e., the parameter holding the object itself (r1) in this case is constant. If a given instance of rectangle, like r1, is constant, then if inside of Rectangle::area() we perform mutations on the member variables this is contradictory: we can't both change the member variables and have them fixed. Even if we don't change the member variables the compiler can't be bothered to check, so we should resolve this as follows.
         
        - Any functions which do not mutate member variables we should ensure have the const so that they can be used by constant instances
        - We should not call any functions which mutate member variables for const instances!
         */
    
    return 0;
}


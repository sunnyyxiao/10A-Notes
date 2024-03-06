//
//  struct3.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/20/23.
//

/*
 AGENDA:
 - Structs on structs
    In this lecture we will create a Triangle struct. Unlike the rectangle, square and circle structs we created in previous lectures, in this example position and orientation in the 2D plane matter. To this end we will need to first create a struct for 2D data points. Our overall goal will be to build a Triangle struct enabling us to initialize triangles using either 3 2D points or 6 doubles (default should be a single point), and a member type function allowing us to compute a triangle's perimeter.
 
 - Public vs private members!
 */


#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <string> // Allows certain string operations
#include <cmath> // Includes a load of useful math related functions like round, max etc.
#include <vector>// allows us to use the vector class
using namespace std; // "Tells computer where to look for various functions"

/* Things to think about while desiging structs
- What member variables do we need and what is the most natural choice of type for each?
- What are the different ways we want to initialize/ construct objects?
- What operations do we want to perform on these objects and how can we capture these
 operations using member functions?
- Which member functions should be const?
*/

/* Struct for 2D points and a member type funcction to compute distances to other 2D points. Define and declare in the same place
 - x and y coordinate
 - two constructors, default is origin
 - compute euclidean distance between one point to another
 */

struct Point2D{
    
    // These member variables define the location of point in the 2D plane
    double x; // x coordinate of point
    double y; // y coordinate of point
    
    // Constructors, initializer list
    Point2D():x(0), y(0){}
    Point2D(double _x, double _y):x(_x), y(_y){}
    
    //second const allows this function to be used on constant members
    double euclidean_dist(const Point2D& other) const{
        return sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));
    }

};

/* Struct for triangles embedded in a 2D plane:
 - triangle has 3 vertices
 - three constructors: default (unit triangle from origin), one for 6 doubles, one for 3 points
 - calculate perimtere functions
 */
struct Triangle{
    Point2D a;
    Point2D b;
    Point2D c;
    
    //copy constructor issue?
    Triangle():a(0,0), b(0,1), c(1,0){}
    Triangle(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y):a(a_x, a_y), b(b_x, b_y), c(c_x, c_y){}
    Triangle(Point2D _a,Point2D _b,Point2D _c):a(_a.x, _a.y), b(_b.x, _b.y), c(_c.x, _c.y){}
    
    double perimeter()const {
        return a.euclidean_dist(b)+b.euclidean_dist(c)+c.euclidean_dist(a);
    }
};

/*Struct to illustrate public vs private:
- contains a double member variable, everytime double is changed a counter is updated to track how many times changes are made!
 - we don't want it to be possible to mutate the count variable outside of it being icremented when x is changed..., we do want to be able to print out the vallue of x and the count though!
 - idea: one can control read and write access to variables through the use of private and public keywords
 public: member variables and functions that are declared as public can be accessed from outside the struct using the '.' operator, they can also be called and accessed within the struct
 
 private: member variables and functions that are declared as private can only be accessed or called inside of the struct
// This struct stores a double x and a double y and has a member function that prints out their values
// This functions however also aims to keep track of how many times x is changed after initialization.
// We don't want the count variable to be changed potentially or mutated outside of a time when x is updated...
// We want to be able to see the number of times x has been mutated
 */
struct Tracker{
public:
    double y;
    void assign_x(double _x){
        x = _x;
        count++;
    }
    Tracker(double _x): count(0), x(_x){}
    
    int read_count(){return count;}
    double read_x(){return x;}
    
private:
    double x;
    int count;
    
};
    

int main(){
    
    {
        // Example data points illustrating different ways to construct
        Point2D a(0,2);
        Point2D b(0,0);
        
        cout << a.x << " " << a.y << endl;
        cout << a.euclidean_dist(b) << endl;
    }
    {
        Point2D a(0,3);
        Point2D b(4,0);
        Point2D c(0,0);
        
        Triangle t1(a,b,c);
        cout << t1.a.x << " " << t1.a.y << endl;
        
        Triangle t2;
        Triangle t3(0,0,0,2,1,0);
        
        cout << t1.perimeter() << " " << t2.perimeter() << " " << t3.perimeter() << endl;
        
    }
    {
        Tracker d(2);
        d.assign_x(4);
        d.assign_x(10);
        d.assign_x(10);
        d.assign_x(10);
        d.assign_x(10);
        cout << d.read_x() << " " << d.read_count() << endl;
    }
    return 0;
}

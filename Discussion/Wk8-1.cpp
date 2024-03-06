//
//  Wk8-1.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/21/23.
//
#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

int pow2(int n){
//    assert(n>=0);
    int result = 1;
    for (int i = 0; i<n; ++i){
        result*=2;
    }
    return result;
}

struct Point2D{
    double x, y;
    
    Point2D(){};
    Point2D(double r,double theta);
};

Point2D::Point2D(double r, double theta){
    assert(r >= 0);
    x = r + cos(theta);
    y = r + sin(theta);
}

//explicit version, the type Point2D does not appear as an implicit parameter but rather as an implicit return type
Point2D explicit_constructor(double r,double theta){
    Point2D implicit;
    implicit.x = r + cos(theta);
    implicit.y = r + sin(theta);
    //double implicit.a, implicit.y
    return implicit;
}

struct Point2DAlt{
    Point2DAlt(){}
    
    Point2DAlt(double r,double theta);
    double x,y;
};

Point2DAlt::Point2DAlt(double r,double theta):x(r+cos(theta)),y(r+sin(theta)){
    assert (r>=0);
}

//Explicit version of Point2DAlt
/*
 Point2DAlt alt_explicit_constructor(double r, double theta){
     
     //Field initializer list
     Point2DAlt implicit;
     double implicit.x(r+cos(theta));
     double implicit.y(r+sin(theta));
     
     //Body
     assert(r >= 0);
 }
 */

struct Circle{
    Circle(double x, double y, double r): center(x,y), radius(r){}
    
    //Point2D implicit.center(x,y)
    //double implicit.radius(r)
    //center is initialized with an explicit constructor, radius is initiailized by copying a double
    
    Point2D center;
    double radius;
};

int main(){
    cout << pow2(-1) << endl;
    
    //explicitly call the constructor
    Point2D p0;
    p0 = Point2D(1,0);
    
    //More frequently:initializing the variable using a constructor
    Point2D p1(2,0);
    
    //copy constructor created automatically
    Point2D p2(p0);
    assert(p1.x == 2 && p1.y == 0);
    p1.x = 4;
    
    //The same syntax can be used for initializing variables of basic types
    int a(2);
    
    return 0;
}

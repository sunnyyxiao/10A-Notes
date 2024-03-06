//
//  frac.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/22/23.
//

#include <iostream>
#include <cassert>
#include <cmath>
#include "frac.hpp"

Tracker::Tracker():x(0),count(0){}
Tracker::Tracker(double _x): x(_x),count(0){}

double Tracker::get_x()const {return x;}
int Tracker::get_count() const {return count;}
void Tracker::mutate_x(double _x){
    x = _x;
    count++;
}

//-------------------------------

Frac::Frac():num(0),den(0){}//can also have semicolon
Frac::Frac(int _num):num(_num),den(1){}
Frac::Frac(int _num, int _den):num(_num),den(_den){
    clean();
    simplify();
};
void Frac::clean(){
    if (den<0){den *=-1;num*=-1;} // make sure negative is on numerator (convention)
    if (num == 0){den = 1;} // If frac represents 0 then put 1 on the bottom!
}
void Frac::simplify(){
    // Run Euclidean algorithm to write fraction in simplest form
    int a = abs(num);
    int b = den;
    // Find largest common denominator!
    while (b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    num/=a;
    den/=a;
}


void Frac::print() const{
    cout << num;
    if (den != 1){
        cout << "/" << den << endl;
    }
}

bool Frac::is_equal_to(Frac other) const {
    return ((num == other.num)&&(den == other.den));
}

Frac Frac::add(Frac other) const{
    int _num = num*other.den + other.num*den;
    int _den = den*other.den;
    return Frac(_num,_den);
}

void Frac::add_update(Frac other){
    num = num*other.den + other.num*den;
    den = den*other.den;
    clean();
    simplify();
}

Frac Frac::multiply(Frac other) const{
    int _num = num*other.num;
    int _den = den*other.den;
    return Frac(_num,_den);
}

void Frac::invert(){
    int _num = num;
    num = den;
    den = _num;
}

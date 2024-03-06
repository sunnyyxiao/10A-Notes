//
//  frac.hpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/22/23.
//

#ifndef frac_hpp
#define frac_hpp
using namespace std;

//Tracker class declaration
struct Tracker{
private:
    double x;
    int count;
public:
    Tracker();
    Tracker(double _x);
    double get_x() const;
    int get_count() const;
    void mutate_x(double _x);
    
};

/*
 Frac class declaration: which members should be
 */

class Frac{
private:
    int num;
    int den;
    void clean();
    void simplify();
    
public:
    Frac();
    Frac(int _num, int _den);
    Frac(int _num);
    
    void print() const;
    bool is_equal_to(Frac other) const;
    Frac add(Frac other) const;
    void add_update(Frac other);
    Frac multiply(Frac other) const;
    void invert();
    
};

#endif /* frac_hpp */

//
//  cintest.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/1/23.
//
#include <iostream>
#include <string>

using namespace std;

struct Ex{
    int x;
    int y;
    Ex(){}
};

class character{
public:
    character() : magic_power("nothing"){cout << "default constructor";}
    character(string& _magic_power) : magic_power(_magic_power){cout << "parse reference"; _magic_power = "4";}
    character(const int& _n) : n(_n) {}
    void query(){cout << magic_power << endl;}

private:
    string magic_power;
    int n;
};

struct Circle{
    int x;
    Circle(int _x){x = _x;}
    double const get_circle(int z1) {int z2 = z1; return z2;}
};

void overload(const int& a){
    cout << "int" << endl;
}

void overload(double& a){
    cout << "double" << endl;
}

void tricky(int a, int& b, int& c) {
    a *= 3;
    cout << b << " " << c << endl;
    c += a;
    cout << b << " " << c << endl;
    b /= 3;
    cout << a << " " << b << " " << c << endl;
}

void print_vec(const vector<int>& v){
    for (size_t i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int a = 20;
    int b = 13;
    int c = 22;
    cout << a << " " << b << " " << c << endl;
    tricky(b, b, b);
    cout << a << " " << b << " " << c << endl;
    
    cout << endl;
    
    int d = 3;
    const int& d1 = d;
    int& d2 = d;
    
    d = 4;
    cout << d << d1 << d2;
    
    vector<int> v = {1,2,5,8,9,4,7};
    print_vec(v);
    
    vector<int> v2 (10,3);
    print_vec(v2);
    
    const int e = 3;
    int f = 4;
    
    overload(f);
    
    const Ex myEx;
    cout << myEx.y << endl;
    
    int A[5];
    
    for (size_t i = 0; i < (sizeof(A)/sizeof(int)); i++){
        A[i] = i;
        cout << A[i] << " ";
    }
    
    
    return 0;
}

//int main(){
//    int y = 2;
//    Circle my_circle(3);
//    cout << my_circle.x << endl;
//    
//    string n = "nothing";
//    
//    character myCharacter(n);
//    character myC(4);
//    myCharacter.query();
//    cout << n;
//    
//    
//    
//    
//    return 0;
//}

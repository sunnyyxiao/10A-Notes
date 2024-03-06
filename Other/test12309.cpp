//
//  test12309.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/29/23.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Overloading test
//void overload(int a,double b){
//    cout << "double" << endl;
//}
//void overload(int a, int b){
//    cout << "char" << endl;
//}

void double_int(int& p){
    cout << p*2;
}

double triple_int(const int& x){
    return x*3;
}

struct Demo{
    double x;
    double y;
    double area() const;
};

double Demo::area() const{
    return x*y;
}

//Q24
void tricky(int a, int& b, int& c) {
    a *= 3;
    b /= 3;
    c += a;
    cout << a << " " << b << " " << c << endl;
}

//Q23
void print_arr(int* p){
    for (size_t i = 0; i < 6; i++){
        cout << *(p+i) << " ";
    }
    cout << endl;
}

//Q21
struct EX{
    const int val1;
    int val2;

    //EX() : val2(0) {}
    EX() : val1(0) {}
    //EX(int _val1, int _val2) : val1(_val1), val2(_val2) {}
    EX(int _val1, int _val2) : val1(_val1) {val2 = val1;}
};

class character{
public:
    character() : magic_power("nothing"){}
    character(const string& _magic_power) : magic_power(_magic_power){}
    void query(){cout << magic_power << endl;}

private:
    string magic_power;
};

int main(){
    {
        //Q23
        int i[] = {1,2,3,4,5,6};
        double d[4];
        double* p = &d[0];
        *(p + 4) = 1.234;
        *(p + 6) = 1.234;
        
        cout << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << " " << i[4] << " " << i[5] << endl;
        print_arr(i);
    }
    
    {
        double A[5] = {5, 5};
        cout << A[2] << endl;
    }
    
    {
        char a[2] {'a', 'b'};
        cout << a << endl;
    }
    
    {
        //Q24
        int a = 20;
        int b = 13;
        int c = 22;
        cout << a << " " << b << " " << c << endl;
        tricky(b, b, b);
        cout << a << " " << b << " " << c << endl;
    }
    
    {
        int a = 5;
        int b = 7;
        int& a1 = a;
        const int& a2 = a;
        int* a3 = &a;
        const int* a4 = &a;
        int* const a5 = &a;
        a1 = 6;
        a4 = &b;
        *a5 = 3;
        
        cout << a << " " << a1 << " " << a2 << endl;
        cout << *a3 << " " << *a4 << " " << *a5 << endl;
        
    }
    
    {
        int _x = 3;
        double_int(triple_int(_x));
    }
    cout << endl;

    return 0;
}



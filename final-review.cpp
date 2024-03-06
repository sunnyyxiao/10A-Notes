//
//  final-review.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 12/8/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class character{
public:
    character() : magic_power("nothing"){}
    character(const string& _magic_power) : magic_power(_magic_power){}
    void query(){cout << magic_power << endl;}

private:
    string magic_power;
};

void change_int_to_zero(int& r){
    r = 0;
}

int int_vector_max(const vector<int>& v){
    int max = v[0];
    size_t N = v.size();
    for (size_t i = 1; i < N; ++i){
        if (max<v[i]){
            max = v[i];
        }
    }
    return max;
}

void overload1(char c){
    cout << "Overload 1" << endl;
}

void overload1(char c, int i){
    cout << "Overload 2" << endl;
}

void overload1(int i, char c){
    cout << "Overload 3" << endl;
}

struct USD{
    USD(size_t _dollars, size_t _cents):cents(_dollars*100+_cents){}
    USD():cents(0){}
    size_t read_cents();
    void read_wallet()const {
        cout << (cents/100) << "." << cents%100 << endl;
    }
    
private:
    size_t cents;
};
//Out of line member declaration
size_t USD::read_cents(){
    return cents;
}


int main(){
    
//1. Vectors: store things in a contiguous chunk of space
    {
        {
            //Different ways to declare and initialize vectors
            vector<float> v(10,1); //10 consecutive ones
            cout << v[0] << " " << v[8] << endl; //index operator will not break down if you go out of bounds (will just give you garbage)
            cout << v.at(0) << " " << v.at(8) << endl; //better, will throw exception if you go out of bounds
            
            size_t n_elements = 10;
            int val = 1;
            vector<float> v2(n_elements, val);
            cout << v2[1] << " " << v2[3] << endl;
            
            vector<double> vd {1,2,3,4};
            cout << vd[0] << " " << vd[1] << endl;
            
            vector<double> vd2 = {1,2,3,4};
            cout << vd2[0] << " " << vd2[1] << endl;
        }
        {
            //Vector member access operators
            vector<int> v {1,2,3};
            //cout << v.at(3) << endl;
            
            cout << v.size() << " " << v.capacity() << endl;
            v.pop_back();
            cout << v.size() << " " << v.capacity() << endl;
            
            v.push_back(10);
            v.push_back(11); //capacity doubles, contents of vector are reallocated to new location
            v.push_back(12);
            cout << v.size() << " " << v.capacity() << endl;
        }
       
        
        //Reallocation in order to increase capacity
    }

//2. Functions
    {
        {
            //Pass by value versus reference versus const reference?
            /*
             1. Pass by value if memory requirement is small and don't want to mutate.
             2. Pass by reference if want to mutate.
             3. Pass by const reference if memory requirement is large and don't want to mutate.
             */
            vector<int> v {1,5,3};
            cout << int_vector_max(v) << endl;
            
            int x = 5;
            change_int_to_zero(x);
            cout << x << endl;
        }
        {
            //Demonstrate function overloading, resolution, role of coercions
            /*
             A function overload is when you have multiple functions with the same name, the compiler distinguishes between them based on the number and type of parameters, in particular the compiler tries to choose the function whose parameters best match the arguments given in terms of the number of coercions (type coercions in order that argument can be assigned to parameter). If coercions are tied, the code will not run as it cannot disambiguate functions.
             */
            
            overload1(2);
            overload1(2,'a');
            overload1('a',2);
            //overload1('b','a');
        }
    }
//3. OOP
    {
        {
            //Basics: syntax struct versus class, access of private and public members
            USD my_wallet(10000,10000);
            USD no_money; //no need for parentheses
            cout << my_wallet.read_cents() << endl;
            my_wallet.read_wallet();
            
            const USD my_wallet_2(1000,10000);
            my_wallet_2.read_wallet();
            
            //Const instances cannot call functions unless your functions are const
        }
    }
//4. Pointers
    {
        {
            //Memory access operator &
            int x = 1;
            cout << &x << endl;
        }
        
        {
            //Pointer basics: A pointer is a variable which stores memory addresses containing objects of a particular type
            int x = 1;
            int* p = &x;
            cout << p << " " << *p << " " << &p << endl;
            
            *p = 5;
            cout << x << endl;
        }
        
        {
            //Const pointers versus pointers to const
            int x = 1;
            int y = 2;
            const int* p = &x;
            cout << *p << endl;
            //*p = 5;
            p = &y;
            
//            int const* pd = &x;
//            *pd = 3;
            
            int* const pc = &x;
            *pc = 3;
            //pc = &y;
        }

    }
    
//5. C-style array
    {
        {
            //Ways to declare an array
            int A[] = {1,2,3};
            int B[3] = {1,2,3};
            const size_t N = 3;
            //size_t N = 3;
            int C[N] = {1,2,3};
        }
        
        {
            //Indexing operator and sizeof
            int A[] {1,2,3};
            cout << A[1] << endl;
            cout << sizeof(A) << endl;
        }
        
        {
            //If A is a C style array, what do A, *A, &A return?
            int A[] {1,2,3};
            cout << boolalpha << (*A == A[0]) << " " << (*(A+1) == A[1]) << endl;
            int* p = A;
            cout << *p << " " << *(p+2) << endl;
            cout << A << " " << &A << " " << &(A[0]) << " " << p << " " << &p << endl;
        }
        
        {
            //Array to pointer decay and functions, e.g. max function over integer array

        }
    }
    
    return 0;
}


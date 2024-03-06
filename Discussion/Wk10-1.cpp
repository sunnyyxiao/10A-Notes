//
//  Wk10-1.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 12/5/23.
//
#include <string>
#include <iostream>
#include <set>

using namespace std;

void greet(string name = "you", int age = 0){
    cout << "Hello, " << name << "! You are " << age << " years old." << endl;
}

set<int> primes_up_to(int n){
    set<int> primes;
    //insert all numbers less than or equal to n
    for (int i = 2; i <= n; i++){
        primes.insert(i);
    }
    //Remove composite numbers
    int p = 2;
    while (p < sqrt(n)){
        //Q is multiple of p
        int q = 2*p;
        while (q<=n){
            primes.erase(q);
            q+=p;
        }
        ++p;
        while (primes.count(p) == 0 && (p*p)<=n){
            ++p;
        }
    }
//    for (int i : primes){
//        bool isPrime = true;
//        for (int i2 = 2; i2<=i; i++){
//            if (i%i2 == 0){
//                isPrime = false;
//                break;
//            }
//        }
//        if (isPrime == false){
//            primes.erase(i);
//        }
//    }
    return primes;
}

int main(){
    greet();
    greet("Alice");
    greet("Bob",30);
    
    int x[] = {2,4,6,8};
    int y = 7;
    int* z = &y; //7
    *z *= *(x+1); //y = 28
    cout << y << endl; //28
    *(x+2) += *z; //34
    cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl; //2 4 34 8
    
//    Code should go through and uppercase all the values in the set --> print BAT
//    set <char> s = {'b','a','t'};
//    for (char val : s){
//        val += 'A' - 'a';
//    }
//    for(char val: s){
//        cout << val;
//    }
//    cout << endl;

    for (int val : primes_up_to(20)){
        cout << val << " ";
    }
    
    return 0;
}

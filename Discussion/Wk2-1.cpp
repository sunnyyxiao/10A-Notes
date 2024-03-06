//
//  Wk2-1.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 10/11/23.
//

#include <iostream>
#include <string>
using namespace std;
int main() {
    int a = -1;
    double b = 0.84;
    // Convert int into double
    double c = a;
    cout << "c = " << c << endl;
    // Convert double into int
    a = b;
    // Implicitly, the above line has a static cast, so it is equivalent to the
    // following line
    a = static_cast<int>(b);
    cout << "a = " << a << endl;
    
    
    // Even though it is assigned to double, 5 / 3 uses integer
    // division because both components are integers
    double d = 5 / 3;
    cout << "d = " << d << endl;
    // To calculate double 5/3, you need to convert one of the
    // components into a double
    d = 5.0 / 3;
    cout << "d = " << d << endl;
    
    // Remainder modulo 2 tells you whether a number is even or odd
    cout << "Even: " << 0 % 2 << 18 % 2 << 6 % 2 << 100 % 2 << endl;
    cout << "Odd: " << 1 % 2 << 11 % 2 << 101 % 2 << -9 % 2 << endl;
    // Remainder is zero when the first number is a multiple of the second
    cout << "Multiples: " << 6 % 3 << 16 % 4 << endl;
    // Remainder modulo 10 gives you the last digit of a number
    a = 147;
    cout << "a = " << a << endl;
    cout << "a % 10 = " << a % 10 << endl;
    cout << "a / 10 = " << a / 10 << endl;
    cout << "Second-to-last digit: " << (a / 10) % 10 << endl;
    cout << "a % 100 = " << a % 100 << endl;
    // string - piece of text
    string s0 = "Hello";
    cout << s0 << endl;
    // Indices start at 0, 0 is first element, 1 is the second element
    cout << s0[1] << endl;
    string s1;
    cout << "What is your full name? ";
    // Reads one word, until the space
    //cin >> s1;
    // Reads until the end of the line
    getline(cin, s1);
    cout << "Hello, " << s1 << endl;
    return 0;
}


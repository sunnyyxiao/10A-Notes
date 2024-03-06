//
//  Lec6.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 10/11/23.
//

#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <string> // Ensures we can use certain string operations
#include <cmath> // Includes a load of useful functions like round, max etc.
#include <iomanip> // Include so as to be able to change the way numbers are represented
using namespace std; // "Tells computer where to look for various functions"

int main(){
    string s1("Pic10A "), s2("is"), s3(" great\n");
    string s4 = s1 + s2 + s3;
    cout << s4;
    cout << s1 + s2 + " great\n";
    
//    int x(3);
//    cout << 2*x << endl;
//    int x;
//    cout << "Enter an integer to double: ";
//    cin >> x; //cin ignores white space
//    cout << 2*x << endl;
//    
//    string s;
//    cout << "Enter your name: ";
//    cin >> s;
//    cout << s << endl;
    
//    int i1,i2,i3;
//    cout << "Enter three integers: \n";
//    cin >> i1 >> i2 >> i3;
//    cout << i1+1 << " " << i2 + 2 << " " << i3 + 3 << endl;
    
//    cout << "Enter your first and second name: ";
//    string first, second;
//    cin >> first;
//    cout << "Your first name is " << first << "\n";
//    cin >> second;
//    cout << "Your second name is " << second << "\n";
    
    cout << "Enter the course you teach: ";
    string s; int i; char c4;
    cin >> s >> i >> c4;
    cout << s <<"\n" << i << "\n" << c4 << endl;
    return 0;
}

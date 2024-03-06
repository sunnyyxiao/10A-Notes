//
//  Lec9.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 10/18/23.
//

#include <iostream>
using namespace std;
int main(){
    /*
     Variable scope
     Having two variables with the same name is ambiguous. Try declaring two variables with the same name i) within the same pair of brackets and ii) outside the same pair of curly brackets.
     */
    //    int x(2);
    //    {
    //        double x(2.5);
    //        cout << x;
    //    }
    
    /*A pair of curly brackets delimits a block or local scope:" any variable delared within it is accessible only within that block and the blocks enclosed by it, and only after the point of declaration. Indeed once a block finishes execution then the memory reserved for its local variables is released.
     */
    
    //    int x=1, y=2, z=3;
    //    cout << "Outer brace: x=" << x << ", y=" << y << ", z=" << z << "\n";
    //    {
    //        int y = 20, z = 30;
    //        cout << "Middle brace: x=" << x << ", y=" << y << ", z=" << z << "\n";
    //        {
    //            int z = 300;
    //            cout<< "Inner brace: x=" << x << ", y=" << y << ", z=" << z <<"\n";
    //        }
    //
    //    }
    
    int x = 1;
    int y = 2;
    {
        int x = 10;
        y = x+y;
        x = x+y;
    }
    cout << "x=" <<x<<", y="<<y<<"\n";
    
    //if you have an int y = 2, then if you assign to y you don't refer to the one outside the curly brackets
    
    
    /* Overview of looping
     In many cases, we may want to run a set of instructions more than once. In C++ we can achieve this through the use of loops, which, as their name suggests, loop back up round to a previous line to run a set of instructions again.
     */
    
//    size_t counter = 1;
//    while (counter<=10) {
//        cout <<counter;
//        counter = counter+1;
//    }
    
//    char input = 'y';
//    while (input == 'y'){
//        cout << "Hello! Do you want to be greeted again [y/n]? ";
//        cin >> input;
//    }
    
//    for(size_t i = 1; i <=20; i+=1){
//        cout << i <<" ";
//    }
    
    string s = "Hello and welcome to pic10A!";
    for (size_t i = 0; i <=s.length()-1; ++i){
        cout << s[i] << " ";
    }

    
//    for (double d = 100; d>10; d=d/2){
//        cout << d << " ";
//    }
//    
//    for (string s = "a"; s != "aaaa"; s= s + "a"){
//        cout << s << " ";
//    }
    
    //Output the first 10 powers of 2 starting from 1
    
//    for(size_t i = 1; i<=10; i+=1){
//        cout << pow(2,i) << " ";
//    }
    
    //Output all the even powers( starting from 2) of a user inputted integer less than 1000
    
//    cout << "Enter an integer: ";
//    size_t x;
//    size_t y = 2;
//    cin >> x;
//    size_t p = pow(x,y);
//    while (p < 1000){
//        p = pow(x,y);
//        cout << p << " ";
//        y = y + 2;
//    }
    
    
//    for (size_t p = pow(x,y); p<1000; y+=2){
//        p = pow(x,y);
//        cout << p << " ";
//    }
    //Double a user input, if it is larger than 100 then output the doubled value, otherwise keep doubling until it is larger than output that value

//    cout << "Enter an integer: ";
//    size_t r;
//    cin >> r;
//    size_t s = r;
//    while (s <=100){
//        s = 2*s;
//    }
//    cout << s;
//    
//    cout << "Enter a number: \n";
//    double d2; cin >> d2;
//    do {
//        d2 *=2;
//    } while(d2 <100);
//    cout << d2 << "\n";
    
    return 0;
}

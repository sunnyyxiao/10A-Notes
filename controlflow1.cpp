//
//  controlflow1.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 10/16/23.
//

#include <iostream>
using namespace std;
int main(){
    //    bool b = false;
    //    if (b) {
    //        cout <<"b is true\n";
    //        cout << "this line also runs";
    //    }
    
    //    cout << "Do you speak English? ";
    //    string s; cin >> s;
    //    if (s == "yes"){
    //        cout << "Great I also speak English\n";
    //    }
    //    cout << "Kanst du Deutsch sprechen?\n";
    //    cin >> s;
    //    if (s == "ja"){
    //        cout << "Ja ich kann ein bisschen Deutsch sprechen\n";
    //    }
    //
    //    cout << "Enter a number: ";
    //    int i; cin >> i;
    //    if (i%2 == 0){
    //        cout << "Your integer is even.";
    //    }
    //    if (i%2 != 0){
    //        cout << "Your integer is odd.";
    //        }
    //
    //    if (i%2 == 0){
    //        cout << "Your integer is even.";
    //    }
    //    else cout << "Your integer is odd.";
//    cout << "Enter a number: ";
//    int i; cin >> i;
//    if (i > 0){
//        cout << "I is positive";
//    }
//    else if (i==0){
//        cout << "I is equal to 0";
//    }
//    else cout << "I is negative";
    
    cout << "Enter grade.\n";
    int i; cin >> i;
    if (i >=90){
        cout << "Your grade is an A.";
    }
    else if (i >=80){
        cout << "Your grade is a B.";
    }
    else if (i >=70){
        cout << "Your grade is a C.";
    }
    else if (i >=60){
        cout << "Your grade is a D.";
    }
    else if (i < 60){
        cout << "Your grade is an F.";
    }
    return 0;
}

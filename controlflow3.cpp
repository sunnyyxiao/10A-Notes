//
//  controlflow3.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 10/20/23.
//

#include <iostream>
#include <string>

using namespace std;
int main(){
//    
    /* 1. pre versus post increment
     Pre and post increment operators are best thought of as functions which add 1 to a variable before/after or after returning the value of the variable for pre/post increment respectively
     */
//    int i = 1;
//    int j = 1;
//    //++i and i++ are equivalent to i+=1
//    cout << "++i returns " << ++i << ", i is now " << i << "\n";
//    cout << "j++ returns " << j++ <<", j is now " << j << "\n";
    
//    int i = 1;
//    cout << 10*i++ << " " << 10*++i << "\n";
    //i becomes 2 after first print, before next print it becomes 3

    /* Equivalence of for and while
     Use while loops when you don't know how many iterations you need to run, and for loops when you do.
     */
    
    //Write this for loop as a while
//    for (size_t i = 0; i <=4; i++){
//        cout << "hello!\n";
//    }
    //for loop has a "for" scope and a local iteration scope, the i above is only defined in the larger scope (for scope), but not outside of it
    
    //with for loops, you can declare the variable outside the for loop and it should still be okay
//    size_t i = 0;
//    while (i<=4){
//        cout << "Hello!\n";
//        i++;
//    }
    
    //print out the numbers 1 to 10 with both a for and while loop
//    size_t i = 1;
//    while (i<=10){
//        cout << i++ << "\n";
//    }
//    
//    for (size_t i = 1; i <=10; i++){
//        cout << i;
//    }
    
    //greet until a user types n with before a for and while loop
    
//    char i;
//    while (i != 'n'){
//        cout << "Hello, again? ";
//        cin >> i;
//    }
    
//    char i;
//    do {
//        cout << "Hello, again? ";
//        cin >> i;
//    } while (i == 'y');
    
    //for 1 through booleans
    
//    char j = 'y';
//    for (;j == 'y';){
//        cout << "Hello, again? ";
//        cin >> j;
//    }
//    
    //for 2, using break
    
//    for (;;){
//        cout << "Hello, again? ";
//        char j; cin>> j;
//        if (j != 'y') break;
//    }
    // ^^same as while true
    
    /*
     Above we introduced a mysterious function called break. This is a goto statement (the other example is continue). Break terminates a loop entirely, skipping over all future potential iterations. Continue terminates only the current iteration
     */

    // A challenge for you in your own time perhaps... write a function which prompts a user to enter integers one at a time and then averages them, rather than requiring them to enter as a list. This will give you the chance to use both break and continue!
    
    char cont = 'y';
    int numTimes = 0;
    int x;
    double avg, tot;
    tot = 0;
    for(;;){
        cout << "Enter an integer: ";
        cin >> x;
        numTimes++;
        tot +=x;
        avg = tot/numTimes;
        cout << "Do you want to continue to enter another integer? [y/n] ";
        if(cont == 'n') break;
        
        cout << "The average of your integer(s) is " << avg << ". \n";
        cin >> cont;
        if(cont == 'y') continue;
    }
    
    return 0;
}

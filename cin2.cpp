//
//  cin2.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 10/13/23.
//

/*
 Agenda
 - Recap of cin
 - Breaking and repairing cin
 - Clearing/ignoring the existing contents in the input stream
 - Introducing getline()
 */

#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <string> // Ensures we can use certain string operations
using namespace std; // "Tells computer where to look for various functions"

//int main(){
//    /* The characters you hit on your keyboard are stored in order in the input buffer as a sequence of chars. The cin command processes this buffer, assigning parts of this sequence of characters to a variable. The rules for how this is done are as follows.
//     
//     Recap of rules of cin:
//     1. If there is nothing in the buffer, allow the user to enter input. When user is prompted for input, the user presses keys and the symbols are stored as a seuqnece of chars in teh input buffer. When user hits enter, this step ceases.
//     
//     2. Move past all whitespace (spaces, tabs, '\n')
//     
//     3. Repeat steps 1 and 2 unitl something thati s not whitespace is encountered
//     4. When possible, interprt the largest subsequence of non-whitespace characters as something of the same type as the type of variable, assign this to the variable, and strip it from the buffer. However, never move past whitespace in this step.
//     
//     If at some point it is not possible to assign the current character(s) in the input buffer to the variable without performing some osrt of implicit conversion then the input stream will break. We can observe this by calling cin.fail(), this returns a boolean true or false if the input stream is broken.
//     */
//        cout << "Enter your stuff: ";
//        int i1; float f1; char c1; string s1; string s2;
//        //Enter [ENTER][TAB]987.123hello, [SPCE]PIC10A![ENTER]
//        cin >> i1 >> f1 >> c1 >> s1 >> s2;
//        cout << i1 << "\n" << f1 << "\n" << c1 << "\n" << s1 << "\n" << s2 << "\n";
//    return 0;
//}
//int main(){
//    
//    //    Repairing broken cin using cin.clear()
//    int i1 = 1;
//    float i2 = 2;
//    double d1 = -1;
//    int i3 = 3;
//    string s1 = "initial";
//    cout << "Enter stuff: ";
//    cin >> i1 >> i2 >> s1;
//    cout << boolalpha << cin.fail() << "\n";
//    cout << i1 << "\n" << i2 << "\n" << d1 << "\n" << i3 << "\n" << s1 << "\n";
//    //Once it breaks, it stops assigning to later variables.
//    
//    cout << cin.fail() << endl;
//    cin.clear();
//    cout << cin.fail() << endl;
//    cin >> d1 >> s1;
//    cout << i1 << "\n" << i2 << "\n" << d1 << "\n" << s1 << "\n";
//    
//    return 0;
//}
int main(){
    /*Clearing the input buffer and removing characters
     - cin.ignore(n, delim) is a member function of cin will ignore up to either nth character or until hit delim character where n is the maximum number of characters to ignore and delim is the character to remove up to (inclusive)
     - cin.ignore() will just skip over or ignore one character
     
     */
    cout << "Enter something: ";
    string s1, s2, s3, s4;
    cin >> s1;
    cin.ignore();
    cin.ignore(10, ' ');
    cin.ignore(10, ' ');
    cin >> s2 >> s3 >> s4;
    cout << s1 << " " << s2 << " " << s3 << " " << s4;
    return 0;
}

//int main(){
//    //Getline(stream, string_variable, delimiter) extracts characters from an input stream which for us will be cin, could also be a text file, and assigns them to a string variable called string_variable until the delim character is found, or the new line '\n' is found. The delimiter is also extracted
//    cout << "Enter an address: ";
//    int zip; string address;
//    cin >> zip;
//    getline(cin, address);
//    //includes the white spaces
//    cout << zip << "\n" << address;
//    return 0;
//}


//
//  Lec5.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 10/9/23.
//

/*
 Agenda
 - Announcements
 - Introduction to containers and classes in C++ with the string class
 - String class object vs. string literal
 - String class object construction
 - Indexing
 - size_t
 - Examples of string class member functions
 - Concatenating strings
 */

#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <string> // Ensures we can use certain string operations
#include <cmath> // Includes a load of useful functions like round, max etc.
#include <iomanip> // Include so as to be able to change the way numbers are represented
using namespace std; // "Tells computer where to look for various functions"

int main()
{
    /*
     1) LITERALS: in the below example
     - x is the program identifier or name for a variable, a reserved piece of memory,
     - float is the type of x, i.e., the way we interpret the bits stored at the memory location referred to by x in our program,
     - 2.5 is a literal, a raw piece of data representing an object, in this case the number 2.5.
     */
    
    float x = 2.5;
    bool b = true;
    char c = 'a';
    int y = 8;
    string s = "lsadficsn";
    // cout << -1u = 2^32 - 1, -1lu = up to 2^64 now
    
    /*
     Literals are also sometimes called literal constants, they refer exlicitly to a single object or thing and are immutable, meaning the symbols we use to represent them cannot be redefined or assigned to refer to something else. e.g., we can't make a now refer to b, or 5 refer to 6.
     - you cannot assign to literals
     - you certainly can assign literals to variables (without literals how would you request certain things to be stored in memory?)
     - literals have a type, in fact there are five types of literals: int, float/double, char, string, bool.
     - prefixes and suffixes can be used to customize a literal. For example with an integer literal the prefix defines gives one the base, while the suffix gives a modifier.
     https://en.cppreference.com/w/cpp/language/integer_literal
     */
    {
    // What do we get out of the following?
        cout << -1u << "\n" << -1ul << "\n";
    // suffix u means unsigned integer, l stands for long
    
    // What do we get out of the following?
    cout<< 012 << "\n" << 0x10 << "\n" << 0b101 << "\n";
    // 0 is base octal, 0x or 0X is hexadecimal, 0b is binary
    
    // Literals, and more generally string literals, are sequences of characters. They come in two forms, raw and non-raw. Raw strings do no escape characters.
    cout << R"(Hello,\nhello!\n)";
    cout << "Hello, \nhello!\n";
    // cppreference for string_literals https://en.cppreference.com/w/cpp/language/string_literal
}
    
    /*
     2) INTRO TO STRING TYPE OBJECTS
     String literals can be assigned to variables of type string. A string type is not a primitive type like an int, float or char however. Indeed, whereas variables of a primitive type we can think of primarily of as data containers, a string type variable is an example of a class object. Class objects not only store data but have a variety of methods associated with them
     
     . We will explore and create our own classes later on in the course!
     - initializing strings
     - indexing, size_t versus int
     - getting the length of a string with .length()
     */

    {
        /*
         In what follows we use endl instead of \n, endl first flushes the output buffer (we will cover this soon) and then
         */
        
        // Initialization: we will present two ways, you will learn about constructors in 10B.
        string s1 = "abc"; // default construct then assign
        
        string s2("def"); int x(0); // call constructor directly
        cout << s1 << s2 << x << endl;
        
        // Length of a string, returns the number of bytes, as each character is a single byte this gives us the number of characters.
        cout << s1.length() << endl;
    }

    /*
     3) INDEXING STRING OBJECTS
     The string s1 above holds three characters, we can access individual characters using the [] operator. Note indexing starts from 0.
     - access first character
     - access last character
     - assigning characters
     - what happens if we go beyond the last index?
     - safe indexing with the .at method
     - using size_t versus ints
     */
    {
        string s1 = "pic10A is awesome";
        cout << s1[0] << " " << s1[1] << " " << s1[2] << endl;
        cout << "pic10A is awesome"[3] << endl;
        
        // To access the last character we can use length
        cout << s1[s1.length() -1] << endl;
        
        // We can also assign characters, can think of s1[i] as a char variable.
        s1[0] = s1[0] - ' ';
        s1[1] = 'I';
        s1[2] = 'C';
        s1[6] = '-';
        cout << s1 << endl;
        
        // If we go beyong the last index then we are accessing pieces of memory that have nothing to do with the string... we can still try and interpret bytes as characters but more often that not these binary sequences will be mapped just to void, when we output void to the console we see nothing.
        cout << "Characters after the end: " << s1[s1.length()] << " " << s1[s1.length()+1]<< endl;
        
        // Accidentally going outside a string or other container can cause issues, its safer to use the .at() method. This raises an exception and stops the code running if you go outside the container.
           cout << s1.at(s1.length()-1) << endl;
        
        // Recall size_t is a type with 64 bits used to store integers. The largest integer it can represent is (2^64)-1. Suppose that we had a very, very long array of characters, say 2^50. Then if we tried to use an int or even unsigned int we wouldn't actually access the correct elements.
        // With integers, 2^31 - 1 is the max you can represent. With unsigned integers, max is 2^32 - 1. With size_t it's 2^64 - 1.
        int p = 50;
        int i = pow(2,p);
        cout << i << endl;
        
        unsigned int iu = pow(2,p);
        cout << iu << endl;
        
        size_t it = pow(2,p);
        cout << it << endl;
    }

    /*
     Other string methods
     - find() returns index where object (substring) first found starting from the left
     - rfind() returns index where object (substring) first found starting from the right
     - popback() removes last character
     - erase(x,y) erases all characters between xth inclusive and yth exlcusive indices.
     - push_back('a') or appends a character to the end of s1
     - substr(x,y) returns a subset of characters starting from index x for length y

     For other methods see the following
     https://www.cplusplus.com/reference/string/string/.
     
     (*note if substring not found then retun npos)
     */
    {
        string s1 = "abcd hello PIC10A";
        cout << s1.find('l') << "\n";
        cout << s1.rfind('l') << "\n";
        cout << s1.find("PIC") << "\n";
        cout << s1.rfind("PIC") << "\n";
        cout << s1.find("PIC16") << "\n";
        
        
        cout << boolalpha <<  (string::npos == s1.find("PIC16")) << "\n";
        
        s1.pop_back();
        s1.pop_back(); //two characters at end removed
        cout << s1 << "\n";
        
        s1.erase(0,4);
        cout << s1 << "\n";
        
        s1.push_back('A');
        cout << s1 << "\n";
        
        cout << s1.substr(1,5) << "\n";
    }



    /*
     Concatenating strings:
        -You can concatenate strings using the plus operator (example of an overoaded operator)
        - You can also concatenate strings with string literals as long as there is at least one string object in the first pair on the left
     */
    {
        string s1("PIC10A "), s2("is"), s3(" great\n");
        cout << s1 + s2 + " great\n"; // works fine
        cout << s1 + "is" + " great\n"; // also works fine
        cout << "PIC10A " +  s2 + " great\n"; // also works fine
        // cout << "PIC10 " +  " is " + s3; // Does not work!
    }
return 0;
}


//
//  string_literals.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 12/1/23.
//

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;

/*
 - Recap from last time
 - Pointers in functions (decaying an array to a pointer)
 - Unordered sets, range-based for loops
 - string literals
 */

void print_sl(const char* p){
    while (*p != '\0'){
        cout << *p;
        ++p;
    }
    cout << endl;
}

int main(){
    
    //String literals
    {
        //So far we have been referring to string literals as characters enclosed by "", we use them to initialize string objects
        //string s = "hello"; initializes through direct assignment
        string s("hello"); //assigning string literal "hello" to a member variable of the class
        
        //The above variable s is not a string literal, and is rather a string class object with a literal string member function...what then is a string literal? It's an array of const chars
        
        const char array_const_chars[] = "PIC10A!";
        size_t n_bytes = sizeof(array_const_chars); //number of bytes to store string literal
        size_t n = n_bytes/sizeof(const char); //divide number of bytes by characters per byte
        cout << "Number of elements in array_const_chars is " << n << "\n";
        
        for(size_t i = 0; i < n; ++i){
            cout << array_const_chars[i];
            if (array_const_chars[i] == '\0'){
                cout << boolalpha << (array_const_chars[i] == '\0');
            }
        }
        cout << endl;
        
        //When we assign to an array using a string literal, a null character always gets added to the end
        //This can be useful, say for instance if we need a stopping condition for iterating through the array
        
        const char* p = array_const_chars; //same thing as initializing as char* p = &a[0]
        //Checking to make sure the above initialization is consistent
        cout << (p == &array_const_chars[0]) << "\n";
        
        print_sl(p);
    }
    
    {
        /*
         Range based for loops and unordered sets
         Range-based for loops are another way to iterate over containers, especially useful if an object is "iterable" but can't necessarily be indexed
         */
        
        vector<int> v1 = {1,2,3,4};
        
        //Iterate over each val which is a member of v1 --> val becomes a new element of v1 each time you iterate through the loop
        for (int val : v1){
            cout << val << ' ';
        }
        cout << endl;
        
        int p1 = 3;
        int* p2 = &p1;
        int*& p3 = p2;
        *p3 = 41;
        
        cout << p1 << " " << p2 << " " << *p2 << " " << p3 << " " << *p3 << endl;
        
        /*
         Unordered sets are containers, i.e. groups or collections of elements that cannot be stored in order. Instead, each element is accessed by its value alone. Elements of a set must be unique! Thus, elements are also immutable, but can be inserted and removed. Duplicate elements are simply removed.
         */
        
        unordered_set<char> c1 = {'a','d','b','g'};
        unordered_set<int> i1 = {1, 3, 5, 6, 2};
        for (char c2 : c1){
            cout << c2 << " ";
        }
        cout << endl;
        for (int val : i1){
            cout << val << " ";
        }
        cout << endl;
        
        //order of elements is in reverse, accessed last in first out
        
    }
    
    {
        //Passing arrays to functions by decaying them to a pointer
        
        int a[] = {1,2,3,4,5};
        
    }
    
    return 0;
}

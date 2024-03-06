//
//  sets-other2.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 12/6/23.
//

#include <iostream>
#include <unordered_set>

using namespace std;

//function for printing an unordered set

void print_int_set(unordered_set<int> u){
    for (int k : u){
        cout << k << " ";
    }
    cout << endl;
}
/**
 Function that prints the values of an unordered set
 @param u is the unordered set being parsed in
 */

size_t factorial_iterative(size_t n){
    size_t k = 1;
    for (size_t i = n; i > 0; --i){
        k *= i;
    }
    return k;
}

size_t factorial_recursive(size_t n){
    if (n>1){
        return n*factorial_recursive(n-1);
    }else {
        return 1;
    }
}

size_t fib_iterative(size_t n){
    size_t prev = 0;
    size_t curr = 1;
    size_t next = 1;
    for (size_t i = 1; i <= n; ++i){
        next = prev+curr;
        prev = curr;
        curr = next;
        
    }
    return next;
}

size_t fib_recursive(size_t n){
    if (n == 0){
        return 0;
    } else if (n == 1){
        return 1;
    } else {
        return fib_recursive(n-1) + fib_recursive(n-2);
    }
}

int main(){
    {
        //Sets recap
        
        unordered_set<int> u1;
        u1 = {0, 1, 2, 5, 89, 0, 1, 11};
        
        //Writing the print code as a function because it makes the code cleaner, and we don't need to rewrite the same chunk of code many times
        print_int_set(u1);
        
        //The size of a set is the number of unique elements in it
        cout << "u1 has " << u1.size() << " unique elements." << endl;
        
        u1.insert(12);
        cout << "Inserting 12...u1 has " << u1.size() << " unique elements." << endl;
        
        u1.erase(0);
        cout << "Erasing 0...u1 has " << u1.size() << " unique elements." << endl;
        
        cout << "The elements of the set are now ";
        print_int_set(u1);
        
        /*
         One way to check that a specific element is in a set
         - There is a count function for containers, it returns the number of elements of a specific value in a container. The count function is also for arrays and vectors. For sets, because all elements are unique, we either have 1 or 0 of each value.
         */
         
        int lookup = 2;
        cout << "Checking if " << lookup << " is in the set...";
        //if lookup is in the set, the number one will be interpreted as a boolean, true.
        if (u1.count(lookup)){
            cout << lookup << " is in the set." << endl;
        } else cout << lookup << " is not in the set." << endl;
        
        //Memory addresses in elements in sets
        cout << "Printing the values in the set and their memory addresses: " << endl;
        /*
         We must iterate over cost ints because unordered sets are stored in a special way that doesn't let you change the value of the number by accessing the address, and C++ doesn't want you to mess it up
         We pass by reference (&) because we want to look at the actual address of the value in the set, not the address of a copy of the value
         Notice that the memory addresses do not go up in 4s (an int is 4 bytes). Thus, values of sets are not stored adjacent to one another.
         Some of the useful operations that we did using pointer to iterate over arrays probably won't work here.
         */
        for (const int& num : u1){
            cout << num << " is stored at address " << &num << endl;
        }
//        for (const size_t num : u1){
//            cout << num << " is stored at address " << &num << endl;
//        }
    }
    
    {
        /*
         A recursion in math and computer science means the repeated application of a specific procedure to a quantity. For some problems though recursion offers a very elegant if not the best solution certainly in terms of compactness of your code. Lets consider the simple example of computing a factorial. For a positive integer n define n! = 1x2x3...n. We could solve this using an iterative approach as below
        */
        
        cout << "Iterative factorial method: " << endl;
        cout << "1! = " << factorial_iterative(1) << "\n";
        cout << "2! = " << factorial_iterative(2) << "\n";
        cout << "3! = " << factorial_iterative(3) << "\n";
        cout << "4! = " << factorial_iterative(4) << "\n";
        cout << "5! = " << factorial_iterative(5) << "\n";
        
        cout << "Recursive factorial method: " << endl;
        cout << "1! = " << factorial_recursive(1) << "\n";
        cout << "2! = " << factorial_recursive(2) << "\n";
        cout << "3! = " << factorial_recursive(3) << "\n";
        cout << "4! = " << factorial_recursive(4) << "\n";
        cout << "5! = " << factorial_recursive(5) << "\n";
        
        cout << fib_iterative(1) << "\n";
        cout << fib_iterative(2) << "\n";
        cout << fib_iterative(3) << "\n";
        cout << fib_iterative(4) << "\n";
        cout << fib_iterative(5) << "\n";
        
        cout << fib_recursive(1) << "\n";
        cout << fib_recursive(2) << "\n";
        cout << fib_recursive(3) << "\n";
        cout << fib_recursive(4) << "\n";
        cout << fib_recursive(5) << "\n";
    }
    return 0;
}

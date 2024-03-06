//
//  overloaded.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/13/23.
//

/*
 AGENDA:
 - Review from last time
 - Motivating function overloading
 - Examples of function overloading
 - How overloaded function resolution works
 - A brief look at templated functions
 */

#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <string> // Allows certain string operations
#include <cmath> // Includes a load of useful math related functions like round, max etc.
#include <vector>// allows us to use the vector class
using namespace std; // "Tells computer where to look for various functions"


// These two functions do almost exactly the same thing... it is kind of annoying that we have to give them different names

//int_vector_print
void print_int_vec(vector<int> v){
    size_t N = v.size()-1;
    for (size_t i = 0; i<=N; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

//float_vector_print
void print_float_vec(vector<float> v){
    size_t N = v.size()-1;
    for (size_t i = 0; i<=N; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

// ---------------------------------------------------------------------------------------
// Motivation: We can in fact just give them the same name and take advantage of function overloading!

// Two functions with the same name to print a vector
// Called print_vec
void print_vec(const vector<float> v){
    for (size_t i = 0, N = v.size(); i<N; ++i){
        cout << v[i] << " ";
    }
    cout << "\n";
}

// Also called print_vec... Look in main to see behaviour!
void print_vec(const vector<int> v){
    for (size_t i = 0, N = v.size(); i<N; ++i){
        cout << v[i] << " ";
    }
    cout << "\n";
}

//Example 2: overload a function which finds biggest element in a vector of ints and a vector of double, max_element
int max_element(vector<int> v){
    size_t N = v.size()-1;
    int max = v[0];
    for (size_t i = 1; i<=N; i++){
        if (v[i]>max){
            max=v[i];
        }
    }
    return max;
}

double max_element(vector<double> v){
    size_t N = v.size()-1;
    double max = v[0];
    for (size_t i = 1; i<=N; i++){
        if (v[i]>max){
            max=v[i];
        }
    }
    return max;
}
// Two functions with the same name to add two vectors
// Called add_vec

vector<int> add_vecs(const vector<int>& v1, const vector<int>& v2){
    vector<int> v3;
    for (size_t i = 0, N = v1.size(); i<N; ++i){
        v3.push_back(v1[i]+v2[i]);
    }
    return v3;
}

vector<double> add_vecs(const vector<double>& v1, const vector<double>& v2){
    vector<double> v3;
    for (size_t i = 0, N = v1.size(); i<N; ++i){
        v3.push_back(v1[i]+v2[i]);
    }
    return v3;
}
    
// ---------------------------------------------------------------------------------------
// Meaningless functions we are using just to get a better handle on overloading

// Example 1: easy
int overload_ex1(){return 1;}
int overload_ex1(int x){return 2*x;}
double overload_ex1(double x){return 3*x;}

// Example 2: trickier, we comment out two on purpose an explore what happens when we have a mixed input
void overload_ex2(int a, int b){cout <<       "int    int\n";}
void overload_ex2(double a, double b){cout << "double double\n";}
void overload_ex2(int a, double b){cout << "double int\n";}

// Example 3: more tricky
void overload_ex3(int a, int b, double c){cout <<    "int int    double\n";}
void overload_ex3(int a, double b, double c){cout << "int double double\n";}

//Practice exercises
//1
int absolute(int x){
    return x;
}
double absolute(double x){
    return x;
}
float absolute(float x){
    return x;
}
int absolute(){
    return 0;
}
//2
void print_elements(vector<char> v){
    size_t N = v.size()-1;
    for (size_t i = 0; i<=N; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void print_elements(string s){
    size_t N = s.length()-1;
    for (size_t i = 0; i<=N; i++){
        cout << s[i] << " ";
    }
    cout << endl;
}
//3
vector<char> combine_input(vector<char> a, vector<char> b){
    vector<char> v_result;
    size_t N = a.size()-1;
    for (size_t i = 0; i<=N; i++){
        v_result.push_back(a[i]);
    }
    N = b.size()-1;
    for (size_t i = 0; i<=N; i++){
        v_result.push_back(b[i]);
    }
    return v_result;
}

vector<char> combine_input(vector<char> a){
    vector<char> v_result;
    size_t N = a.size()-1;
    for (size_t i = 0; i<=N; i++){
        v_result.push_back(a[i]);
    }
    return v_result;
}

string combine_input(string s1,string s2, string s3){
    string s_total = s1 + s2 + s3;
    return s_total;
}
string combine_input(string s1,string s2){
    string s_total = s1 + s2;
    return s_total;
}
string combine_input(string s1){
    return s1;
}

int main(){
    
    // ---------------------------------------------------------------------------------------
    // Motivating overloading
    
    {
        // Demonstration print functions
        vector<int> v1 = {1,2,3};
        vector<float> v2 = {1,2,3,4,5};
//        print_int_vec(v1);
//        print_float_vec(v2);
        print_vec(v1);
        print_vec(v2);
    }
    /*
     Observations:
     - Code runs successfully and resolves which version to use, meaning we can print both integer and double vectors using the same function call
     - If you comment out one function, e.g., the int version then an error pops up saying no matching function call for print_vec when trying to print_vec an integer vector.
     */
    
    {
        // Demonstration that chooses the 'right' max_element each time
        cout << "Check if add_vec works:\n";
        vector<int> v1 = {1, 4, 3};
        vector<double> v2 = {0.8, 2.1, 0.7};
    
        cout << max_element(v1) << endl;
        cout << max_element(v2) << endl;
    
        }
        /*
         Observations:
         - Again code runs and successfully and resolves which version to use, meaning we can print both integer and double vectors using the same function call
         - If you comment out one function, e.g., the int version then an error pops up saying no matching function call for add_vec when trying to add_vec an integer vector.
         */
    
    // ---------------------------------------------------------------------------------------
    
        /*
         Rules for how C++ chooses which function to call
         - first find functions with the same name or identifier,
            - of these functions then find the subset with the right number of parameters,
                - finally of this subset find the function which has the best argument coercion comparison
    
         A few things to unpack...
         - argument coercion in C++ is when the compiler implictly converts the data type of an argument passed to a parameter
         - the best argument coercion comparison corresponds to the function which has the ore appropriate argument in every parameter. We will go through some examples to understand this better.
         */
    
    // ---------------------------------------------------------------------------------------
        {
            // Predict the output of the following.
            cout << "Understanding overloading example 1:\n";
            cout << overload_ex1() << " " << overload_ex1(1) << " " << overload_ex1(1.5) << "\n";
    
            /*
             Taking each function call above in order:
            - there are three functions with the name overload_ex1, but only one with no parameters,
            - there are two functions with the name overload_ex1 AND one parameter, but the integer version requires no coercion,
            - there are two functions with the name overload_ex1 AND one parameter, but the double version requires no coercion.
             */
        }
    
        {
            // Let us now consider a trickier example
            cout << "Understanding overloading example 2:\n";
            overload_ex2(1,2);
            overload_ex2(1.0,2.0); //one coercion for double int when double double is commented out
            overload_ex2(1,2.0); //one coercion for int int when double double is commented out
            //when double double is not commented out, error "call to overload_ex2 is ambiguous" because there are equal number of coercions
        }
    
        {
            // Final example: predict the output of this, note that all arguments are doubles
            cout << "Understanding overloading example 3:\n";
            overload_ex3(1.5, 2.5, 3.5);
            overload_ex3(1, 2, 3.5);
            overload_ex3(1.5, 2, 3.5);
            /*
             Taking each function call above in order:
            - there are two functions with the name overload_ex3 AND have three parameters, the int double double involves one coercion on the first parameter, the int int double requires a coercion on the first and second. Therefore int double double is used as is at least as good if not better than the other on all three parameters
            -  there are two functions with the name overload_ex3 AND have three parameters, the int double double involves two coercions on the first and second parameters, the int int double requires a single coercion on the first. Therefore int int double is used as is at least as good if not better than the other on all three parameters
            - finally on the third call, int int double is selected as again requires at least a few coercions.
             */
        }
    
    
        /*
         Takeaways:
         - handy to name functions doing the same thing with the same identifier...
         - to resolve function calls make decisions based on (in order) first name, then number of parameters, then optimizing number of coercions.
         - you should not write your code really based on coercion optimization, this is liable to make errors, still good to be aware of it though!
         - const references also impact resolution: recall can't assign a const reference to a non-const reference
         - Template functions are a way of getting around having to define functions over and over again, won't touch on them in this course. But useful!
         */
    
        /*Practice Exercises
         - write an absolute function which takes in floats, ints, doubles and returns the absolute value. If no input is entered then returns 0
         - write a function which consoles out all the elements in a vector of characters or a string
         - write a function which takes up to two vectors of characters or three strings and either returns a single vector containing all the vector arguments or a single string containing all the string arguments
         */
    
    return 0;
}

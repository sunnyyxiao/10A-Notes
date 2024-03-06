//
//  vectors2.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/8/23.
//

#include <iostream> // Allows us to use cout and cin to read and write via the console
#include <string> // Allows certain string operations
#include <cmath> // Includes a load of useful math related functions like round, max etc.
#include <vector>// NEW: allows us to use the vector class
using namespace std; // "Tells computer where to look for various functions"



// Should we pass by value here (copy) or pass by reference? Const reference is best option as avoid expensive copy but also avoid mutations!]
void print_int_vec(vector<int>& v){
    size_t N = v.size()-1;
    for (size_t i = 0; i <= N; ++i){
        cout << v[i] << " ";
    }
    cout << "\n";
}

//Sum_vec_bad: assume that both have the same size
// Should we pass by value here (copy) or pass by reference or by const reference? Passing by value is expensive, while passing by reference introduces unwanted mutations. Experiment with different parameters 'vector<int> v' or 'vector<int>& v'.
vector<int> add_vecs_bad (vector<int>& v1, vector<int>& v2){
    size_t N = v1.size()-1;
    for (size_t i = 0; i <= N; ++i){
        v1[i]+= v2[i];
    }
    return v1;
}

vector<int> add_vecs (const vector<int>& v1, const vector<int>& v2){
    size_t N = v1.size()-1;
    vector<int> v3;
    for (size_t i = 0; i <= N; ++i){
        v3.push_back(v1[i]+v2[i]);
//        v3[i] = v1[i] + v2[i];
    }
    return v3;
}

int max_vec_element(vector<int>& v){
    int max = v[0];
    size_t N = v.size()-1;
    for (size_t i = 1; i<=N; i++){
        if (max<v[i]){
            max = v[i];
        }
    }
    return max;
}

//error if this is constant,the other is not constant
void print_max_element(vector<int>& v){
    cout << "Max element is " << max_vec_element(v);
}

//int sum_vec_bad(vector<int>& v){
//    for (size_t i = 1, N = v.size(); i<N; ++i){
//        v[i] += v[i-1];
//    }
//    return v[v.size()-1];
//}
//
//// This is generally a much better, clearer solution!
//int sum_vec(const vector<int>& v){
//    int total = 0;
//    for (size_t i = 0, N = v.size(); i<N; ++i){
//        total += v[i];
//    }
//    return total;
//}
//
//
void argument_choice(bool mutate, bool large){
    if (mutate){
        cout << "As you want to mutate your argument you need to pass by reference.\n";
    }
    else{
        if (large){
            cout << "Your argument is large, therefore you don't want to pass by value (copy). At the same time you don't want to risk mutating your argument. Therefore you should pass by const reference!\n";
        }
        else{
            cout << "As your argument variable is small and you don't want to mutate it then you can pass by value without signigicant memory or computational overhead.\n";
        }
    }
}

// Print sum function is pass by value but is calling a function which is a const reference! Compiler won't like this!
//void print_vec_sum(vector<int>& v){
//    cout << "Sum of vector elements is " << sum_vec(v) << "\n";
//}



int main(){
    // Last lecture we introduced vectors and started thinking about how to manage functions on vectors. Vectors like strings are class objects, and perhaps more significantly are containers for potentially a large number of elements. In particular each element of a container might need a lot of memory, copying such objects into new memory locations might then be expensive... Passing by reference is therefore a natural choice for these big objects! But this carries risks, if we pass by reference we might accidently perform some mutation which we don't intend...
    {
        // Illustration of value vs reference:
        vector<int> v1 = {1,2,3};
        vector<int> v2 = {1,1,1};
        vector<int> v3 = add_vecs(v1,v2);
        print_int_vec(v3);
        print_int_vec(v1);
        
//        cout << v.size() << " " << v.capacity() << endl;
        
        //reassigning the vector copies it to another location, memory address (different from variables)
//        v.push_back(6);
//        cout << v.size() << " " << v.capacity() << endl;
//        v.pop_back();
//        cout << v.size() << " " << v.capacity() << endl;
//        v.pop_back();
//        v.pop_back();
//        
//        size_t N = v.size();
//        for(size_t i = 0; i<=N; i++){
//            cout << v[i] << endl;
//        }
        
        //introducing const references
//        int i = 2;
//        int& r1 = i;
//        const int& r2 = i;
//        
//        r1 = -1;
//        cout << i << " " << r1 << " " << r2 << endl;
        
        //References can't be bound to a literal, but const references can be
//        int& r3 = 89;
        const int& r4 = 89;
    }
    
    {
        /* How should you choose how to pass an argument (i.e., choose the parameter type)? Two things to consider:
         1) Do we actually want to perform a mutation on the argument, i.e., do we want to change the value of the argument by calling a function?
         2) Is the argument variable large in terms of memory? In particular fundamental types we covered at the start are perhaps at most 64 bits or 8 bytes. This is not expensive to copy. On the other hand containers, like vectors or maybe even strings, could in theory take up a lot of memory and therefore be expensive to copy.
         
         There are 4 options arising from value vs reference and constant vs non-constant. Consider tree diagram wwe'll look at in class. We can also write this as code using if and else statements. We can even wrap this in a procedure which you can use in the future!
         */
//        bool large = false;
//        bool mutate = false;
//        argument_choice(mutate, large);
        
        int i = 2;
        const int& r1 = i;
        //cannot bind a reference to a const reference
//      const int& r2 = r1;
    }
    vector<int> v = {1,2,3};
    print_max_element(v);
    
    return 0;
}

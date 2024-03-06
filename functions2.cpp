//
//  Lec13.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 10/27/23.
//

#include <iostream>

using namespace std;

/*
 Exploring the return statement
 A function xists as soon as it hits a return statement. It acts like a goto instruction to make our code more efficient
 We will consider writing an absolute function
 */

//Approach A: using two if statements, this is fine in theory but compiler may complain

double my_abs(double x){
    if (x>0){
        return x;
    }
//    if (x<=y){
//        return y
//    }
    //cannot use above because the compiler isn't smart enough to understand it covers all possibilities
    return -x;
    //don't need else above
}

double my_max(double x, double y){
    if (x>y){
        return x;
    }
    return y;
}

int my_pos_pow(int base, unsigned int exp){
    /**
     Computes a positive power of an integer
     @param exp is a positive integer
    @param base is an integer with which we compute the power
     @return base^exponent
     */
    int pow=1;
    for(unsigned int t = 1; t<=exp;t++){
        pow*=base;
    }
    return pow;
}

void my_swap (int x, int y){
    int z = x;
    x = y;
    y = z;
    cout << x << " " << y;
}

int main(){
    /*
     What happens when a function is called
     1) A local function scope is created
     2) The arguments (variables in main) are copied to function parameters (local variables)
     3) We run the body of the function
     4) When we return, we first assign the value back to a variable in main (if we assign by calling the function) then we exit/go to the end of the local scope
     */
    cout << my_abs(-2) << "\n";
    
    double bigger = my_max(1,10);
    cout << bigger << "\n";
    
    cout << my_pos_pow(2,4) << "\n";
    
    //Write a swap function that swaps x and y
    my_swap(2,4);
    
    return 0;
}

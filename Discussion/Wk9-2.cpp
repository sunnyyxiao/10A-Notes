//
//  Wk9-2.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/30/23.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
   int x = 0;
   int a[4] = {10, 20, 30, 40};
   int y = 3;
    
   int* p = &x;
   cout << p << endl;
   cout << *p << endl;
    
   *p = y;
   cout << p << endl;
   cout << *p << endl;
   cout << x << " " << y << endl;
   
   int z = 4;
   //Changing value of *p and thus x
   *p = z;
   cout << *p << endl;
   cout << x << " " << y << " " << z << endl;
   
   *p = -2;
   cout << x << " " << y << " " << z << endl;
   
   p = &y;
   cout << *p << " " << p << endl;
   cout << x << " " << y << " " << z << endl;
   
   int& ref = x;
   ref = y;
   cout << x << " " << y << endl;
   ref = z;
   cout << x << " " << y << " " << z << endl;
   
   p = &a[0];
   for (int i = 0; i < 4; ++i){
      a[i] += 1;
//      *(p+i) += 1;
      cout << a[i] << " ";
   }
   cout << endl;
   while (p<=&a[3]){
      ++*p;
      for (int i = 0; i < 4; ++i){
         cout << a[i] << " ";
      }
      cout << endl;
      ++p;
      cout << p << endl;
   }
   
   int x0 = 0, x1 = 2;
   const int y0 = 1, y1 = 3;
  
   const int* p1 = &y0; //cannot change the value, can change the location it binds to
   //above is same as intc const* p1
   int* const p2 = &x0; //cannot change the location it binds to
   const int* const p3 = &y0; //combination of both
   
   p1 = &y1;
   //cannot change the value of y1 while p1 is pointing to it
   //*p1 = -1;
   *p2 += 2;
   //p2 = &x1;


   /*
    Pointers and References
    - You cannot initialize either with a literal UNLESS it's a constant reference (constant pointer stil does not work)
    - Existing pointers and reference can be assigned to a literal --> this changes the value of the variable tied to each, respectively
    - Assignment to a literal does not change the location referred to by the pointer (variable does not change)
    - Pointers can be reassigned to bind a new location, unlike references, which changes the location referred to by the pointer
    */
   
    return 0;
}

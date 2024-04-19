//
//  controlflow4.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 10/23/23.
//

#include <iostream>

using namespace std;
int main(){
//    {
//        int i = 1, j = 2, k = 3;
//        {
//            int j = 20, k = 30;
//            {
//                int k = 200;
//                cout << i << ' ' << j << ' ' << k << endl;
//            }
//        }
//    }
//    
//    int sum;
//    for (int i = 1; i <=10; ++i){
//        sum = 0;
//        for (int j = 1; j <=10; ++j){
//            sum+=j;
//        }
//    }
//    cout << "The sum of the first 10 numbers is: " << sum << endl;
    
//    string s = "HI UCLA!! We are learning C++ and we love it.";
//    size_t size_s = s.length()-1; //largest index that a character has
//    
//    for (size_t i = 0; i<= size_s; ++i){
//        cout << s.at(i); //safer than [] notation, if incorrectly index.at() will give you an error, which means that it's easier to debug your code
//    }
    //print out certain characters of string
//    for (size_t i = 0; i<= size_s; ++i){
//        char c = s.at(i);
//        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A'){
//            cout << c;
//        }
//    }
//    cout << endl;
//    
//    for (size_t i = size_s; i!= -1; --i){
//        cout << s.at(i); //safer than [] notation, if incorrectly index.at() will give you an error, which means that it's easier to debug your code
//    }
    
    //Example: Find all primes below a specific positive integer.
    
    cout << "Please enter a positive integer: ";
    int i;
    cin >> i;
    cout << "Finding all primes below " << i << "\n";
    for (int x = 2; x<i; x++){
        bool prime = true;
        for (int y = 2; y <= x/2; y++){
            if (x%y == 0){
                prime = false;
            }
        }
        if (prime == true){
            cout << x << " ";
        }
    }
    
    
    return 0;
}

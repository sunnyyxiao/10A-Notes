//
//  abcdtest.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/1/23.
//

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void printInts(int a, int b, int c=10, int d=20, int e=30){
    std::cout << a << " " <<  b << " " << c << " "<< d << " " << e << "\n";
}

int main(){
//    int a, b;
//    cin >> a >> b;
//    
//    if (a == 0 and b == 0){
//        cout << "Hello world";
//    }
//    cout << setprecision(5) << (6/5.0)-1-(1/5.0);
//    cout << boolalpha << b;
    
//    cout << "Please enter something when prompted:";
//    string s1; cin >> s1;
//    cin.ignore();
//    cin.peek();
//    double d1; cin >> d1;
//    int a = cin.get();
//    char ch1; cin >> ch1;
//    string s2; getline(cin, s2);
//    cout << s1 << " " << d1 << " " << ch1 << " "<< s2 << " " << a;
    
//    int counter = 0;
//    
//    for (int i = 1; i <=4; i++){
//        cout << "Hello world ";
//        cout << counter << "\n";
//        counter++;
//    }
//    
//    counter = 0;
//    
//    for (int i = 1; i<=4; ++i){
//        cout << "Hello ";
//        cout << counter << "\n";
//        ++counter;
//    }
//        
        
    //    cout << cin.fail() << endl;
    //    cin.clear();
    //    cout << cin.fail() << endl;
    //    cin >> d1 >> s1;
    //    cout << i1 << "\n" << i2 << "\n" << d1 << "\n" << s1 << "\n";
    
//    int x = 1;
//    int y = 2;
//    
//    int& r = x;
//    
//    //pointer to constant
//    const int* p = &x;
//    cout << p << endl;
//    p = &y;
//    cout << x << " " << p << " " << *p << endl;
//    
//    r = 4;
//    cout << x << " " << r << endl;
//    
//    //constant pointer
//    int* const p2 = &x;
//    *p2 = 6;
//    
//    cout << y << " " << p2 << " " << *p2 << endl;
    
    printInts(1,2,3,4,5); // No default arguments
    printInts(1,2,3,4); // C++ assumes you are leaving out the furthest right parameter
    printInts(2,3,4); // C++ assumes you are leaving out the two furthest right parameters
    printInts(1,2);
    
    int i[] = {1,2,3,4,5,6};
    double d[4];
    double* p = &d[0];
    *(p + 4) = 1.234;
    *(p + 6) = 1.234;
    
    vector<int>s2 ();
    vector<int> s3 {};
    
    
    cout << i[0] << " " << i[1] <<" " << i[2] << " " << i[3] << " " << i[4] << " " << i[5] <<endl;

    
    return 0;
}

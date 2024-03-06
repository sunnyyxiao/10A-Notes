//
//  Wk7-1.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/14/23.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_vector(const vector<int>& v){
    for (size_t i = 0; i <v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}
void print_vector(const vector<double>& v){
    for (size_t i = 0; i <v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

void f(int x){
    cout << "i " << x << endl;
}

void f(double x){
    cout << "d " << x << endl;
}

void pushback(vector<int>& v, int i, int i2){
    cout << "int push back" << endl;
}

void pushback(vector<double>& v, double d, double d2){
    cout << "double push back" << endl;
}

void push_forward(double& d, double d2, double d3){
    cout << "double push forward" << endl;
}

void push_forward(int& d, int d2, int d3){
    cout << "int push forward" << endl;
}

//  1 3 3 1
// 1 4 6 4 1
//given a row of Pascal's triangle, get the next row
vector<int> next_row(const vector<int>& row){
    size_t N = row.size();
    vector<int> nextrow = {1};
    for (size_t i = 1; i<=N; i++){
        nextrow[i] = (row[i-1]+row[i]);
    }
    nextrow.push_back(1);
    return nextrow;
}
//vector<int> next_row_ex(const vector<int>& row){
//    vector<int> result ;
//    for(size_t i = 0; i<row.size()-1; ++i){
//        result.push_back(row[i] + row[i+1]);
//    }
//    return result;
//}

void print_pascal_triangle();

int main(){
    vector<int> vec_int = {1, 3, 5};
    vector<double> vec_double = {0.5, 1.5, 2.5};
    print_vector(vec_int);
    print_vector(vec_double);
    
    f(1);
    f(2.5);
    
    pushback(vec_int,10.3,10.3);
    pushback(vec_double,10,10);
    //can't coerce vectors into a different type
    //can't coerce references from one type to another
    
    int a = 10;
    push_forward(a, 10.2, 10.2);
    
    int N;
    cin >> N;
    vector<int> v = {1};
//    for (int i = 1; i<=N; i++){
//        for (int i = 0; i<=v.size();i++){
//            cout << v[i] << " ";
//        }
//        cout << endl;
//        v.push_back(v[i]);
//        v[i] =
//        
//    }
    
    vector<int> v2 = {1,3,3,1};
    print_vector(next_row(v2));
    
    
    return 0;
}

//
//  Wk6-1.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 11/7/23.
//

#include <iostream>
#include <string>

using namespace std;

vector<int> duplicate_entries(vector<int>vec){
    vector<int> result;
    for (int i = 0; i<=result.size()-1;i++){
        result.push_back(vec[i]);
        result.push_back(vec[i]);
    }
    return result;
}


int main(){
    vector<int> v1(5,1); // 5 elements initialized at 1
    vector<int> v2; //no entries, size zero
    vector<int> v3(5);
    cout << v1.size() << ' ' << v1[0] << endl; //5 1
    cout << v2.size() << ' ' << v2[0] << endl; //0
    cout << v3.size() << ' ' << v3[0] << endl; //5 0
    
    vector<int> v4 = duplicate_entries(v1);
    
}

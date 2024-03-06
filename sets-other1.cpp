//
//  sets-other1.cpp
//  Pic_10A
//
//  Created by Sunny Xiao on 12/4/23.
//

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
 Agenda
 - this pointer
 - the "->" operator
 - setting default parameters for functions
 */

class Friend{
public:
    Friend(string _name):name(_name),friend_list(),joke_count(0),heard_joke(false){}
    
//    void make_friend (Friend* f){
//        f->friend_list.insert(this);
//        friend_list.insert(f);
//    }
    void make_friend_with (Friend& f){
        friend_list.insert(&f);
        f.friend_list.insert(this);
    }
    
    void print_friends (){
        cout << name << "'s friends are: ";
        for (Friend* f :friend_list){
            cout << f->name << " ";
        }
        cout << endl;
    }
    void have_disagreement(Friend* f) {
        friend_list.erase(f);
        f->friend_list.erase(this);
    }
    
    void tell_joke_to(Friend* f){
        (f->joke_count)++;
        f->heard_joke = true;
        cout << f->name << " heard " << f->joke_count << " joke(s) and it is " << boolalpha << f->heard_joke << " that they have heard a joke. " << endl;
    }
    
    void print_jokes(){
        cout << name << " heard " << joke_count << " jokes." << endl;
    }
    
private:
    const string name;
    unordered_set<Friend*> friend_list; //this unordered set will hold pointers to other instances of the friend class that this person is friends with
    int joke_count;
    bool heard_joke;
    
};

//setting function default values

void print_ints(int x = 0);

void print_ints(int x){
    cout << "The value of the int is " << x << endl;
}

int main(){
//    {
//        Friend f1("Harry");
//        Friend f2("Alex");
//        Friend f3("Julie");
//        
//        f1.make_friend(&f2);
//        f1.make_friend(&f3);
//        f1.print_friends();
//        f2.print_friends();
//        f3.print_friends();
//        
//        f2.have_disagreement(&f1);
//        f1.print_friends();
//        f2.print_friends();
//        f3.print_friends();
//        
//        f1.tell_joke_to(&f3);
//        f2.tell_joke_to(&f3);
//        f1.tell_joke_to(&f3);
//        
//        f1.print_jokes();
//        f2.print_jokes();
//        f3.print_jokes();
//    }

    {
        //default values of functions
        
        int i1 = -1;
        print_ints(i1);
        
        cout << "Not giving a value to the first argument: " << endl;
        print_ints();
        
        //If we have a function with multiple arguments and some have defaults and some don't, the ones with defaults should be to the right of the ones without in the function signature
    }
    
    {
        int x[] = {1,2,3,4};
        int y = 5;
        int* z = &y;
        *z *= *(x+2); //*z = 15 = y
        z = x; //1
        *(z+1) = y; //15 = x[1]
        cout << "x now contains " << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << "\n";
        //1 15 3 4
        cout << "y now contains " << y << endl; //15
        
        vector<int> v = {1,2,3};
        vector<int>* pv = &v;
        cout << pv << endl;
        
        cout << pv << endl;
        for (size_t i = 0; i < v.size(); ++i){
            cout << &(v[i]) << " " << (*pv)[i] << endl;
            
        }
        

    }
    
    return 0;
}

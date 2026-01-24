#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> vec;
    cout<<"size="<<vec.size()<<endl;
    vec.push_back(25);
    vec.push_back(35);
    vec.push_back(45);
    vec.push_back(3);
    vec.push_back(5);

    cout<<"size="<<vec.size()<<endl;
    cout <<vec.front()<<endl;
    cout <<vec.back()<<endl;
    cout <<vec.at(1)<<endl;
    cout<<"size="<<vec.capacity()<<endl;
    // for (int val:vec){
    //     cout<<val<<endl;
    // }

    
return 0;
}
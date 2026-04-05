#include<iostream>
using namespace std;

int ntimes(int i,int n){
    if(i>n) return 0;
    cout<<" "<<"a";
    return ntimes(i+1,n);
}
int main(){
    ntimes(1,12);
    cout<<endl;
    return 0;
}
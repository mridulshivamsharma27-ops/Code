#include<iostream>
using namespace std;
int sum(int a,int b){
    return a+b;
}
int main(){
    int a,b;
    char comma;
    cout<<"Enter The Numbers: ";
    cin>>a>>comma>>b;
    cout<<"The Sum Of "<<a<<" & "<<b<<" = "<< sum(a,b);
return 0;
}
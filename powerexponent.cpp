#include<iostream>
using namespace std;
int main(){
    float x;
    int n;
    char comma;

    cout<<"Given Number(x) to Power(n): ";
    cin>>x>>comma>>n;
    if(x==1) return 1.0;
    if(x==0) return 0.0;
    if(n==0) return 1.0;
    if(x==-1)   {
        if(n%2==0)  return 1.0;
        if(n%2!=0)  return -1.0;
    }
    if(x<0)  x=1/x;  n=-n;


    
}
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter Number:";
    cin>>n;
    bool flag;
    for (int  i = 2; i < n; i++)
    {
        if((n%i)!=0)  flag=true;
        else flag =false;
    }
    if(flag==true) cout<<"Prime Number";
    else if(n==2) cout<<"Prime Number";
    else cout<<"Not A Prime Number";

    
return 0;
}
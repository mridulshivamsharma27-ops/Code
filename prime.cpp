#include<iostream>
using namespace std;

int primeno(int n){
    int count=0;
    for (int i = 1; i <=n; i++)
    {
        if(n%i==0){
            count++;
        }
    }
    return count;;
    
}

int main(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    int div=primeno(n);
    if(div==2){
        cout<<n<<" is a prime number."<<endl;
    }
    else{
        cout<<n<<" is not a prime number."<<endl;
    }
   return 0;
}
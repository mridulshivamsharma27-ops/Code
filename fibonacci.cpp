#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n==0 || n==1) return n;
    cout<<n<<"...";
    return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    cout<<"Fibonacci of "<<n<<" is: "<<fibonacci(n)<<endl;
   return 0;
}
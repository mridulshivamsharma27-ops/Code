#include<iostream>
using namespace std;

void printDivisors(int n){
    cout<<"Divisors of "<<n<<" are-> "<<endl;
    for (int i = 1; i <=n; i++)
    {
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    return;
    
}

int main(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    printDivisors(n);
   return 0;
}
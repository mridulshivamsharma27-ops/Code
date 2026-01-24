#include <iostream>
using namespace std;
int factorial(int n){
    if(n==0 or n==1) return 1;
    return n*factorial(n-1);
}
int Combination(int n,int r){
    return factorial(n)/(factorial(r)*factorial(n-r));
}

int main() {
    int n=12,r=7;
    cout<<Combination(n,r);
    return 0;
}
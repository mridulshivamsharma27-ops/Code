#include<iostream>
using namespace std;

int printreverse(int n){
    if(n==0) return 0;
    printreverse(n-1);
    cout<<n<<" ";
 
}
int main(){
    printreverse(12);
    cout<<endl;
    return 0;
}   
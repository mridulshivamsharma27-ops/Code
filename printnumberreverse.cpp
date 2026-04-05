#include<iostream>
using namespace std;

int printnumber(int n){
    if(n==0) return 0;
    return printnumber(n-1);
    cout<<n<<" ";

}
int main(){
    cout<<printnumber(12)<<endl;
    return 0;
}
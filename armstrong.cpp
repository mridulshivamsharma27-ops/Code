#include <iostream>
#include<math.h>
void armstrong(int n){
    int sum=0,temp=n;
    int digits=to_string(n).length();
    while(temp!=0){
        int r=temp%10;
        sum+=pow(r,digits);
        temp/=10;
    }
    if(sum==n){
        cout<<n<<" is an armstrong number.\n";
    }
    else{
        cout<<n<<" is not an armstrong number.\n";
    }
    return;

}
using namespace std;

int main() {
return 0;
}
#include<iostream>
using namespace std;
int sumOfdigit(int n){
    int sum=0;
    int temp=n;
    while (temp!=0)
    {
        int digit=temp%10;
        sum+=digit;
        temp/=10;
    }
    return sum;
    

}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Sum of digits of "<<n<<" is "<<sumOfdigit(n)<<endl;
    return 0;
}
#include<iostream>

using namespace std;

int reverseNumber(int n){
    int temp=n;
    int rev=0;
    while(temp!=0){
        int digit=temp%10;
        rev=rev*10+digit;
        temp/=10;
    }
    return (n>0)?rev:-rev;
}

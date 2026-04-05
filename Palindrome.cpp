#include<iostream>
using namespace std;


void reverse(int original){
    int temp=original;
    int rev=0;
    while(temp!=0){
        int digit=temp%10;
        rev=rev*10+digit;
        temp/=10;
    }
       if(original==rev){
        cout<<original<<" is a palindrome number.\n";
    }
    else{
        cout<<original<<" is not a palindrome number.\n";
    }
    return;
}
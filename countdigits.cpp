#include<iostream>
using namespace std;

int countdigit(int n){
    if (n==0) return 1;
    int count=0;
    int temp=n;
    while(temp!=0){
        temp/=10;
        count++;
    }
    return count;
}
int main(){
    
}
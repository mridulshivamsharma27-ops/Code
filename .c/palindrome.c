#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    int temp,rev=0,digit;
    if(x>=0){
        temp=x;
    }
    else
    {
        temp=-(x);
    }
    while(temp!=0){
        digit=temp%10;
        rev=rev*10+digit;
        temp=temp/10;
    }
    if(rev==x) return true;
    else return false;
}
int main() {
    int x=121;
    bool flag=isPalindrome(x);
    printf("%s",flag?"true":"false");
return 0;

}
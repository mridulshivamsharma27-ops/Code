#include <stdio.h>
#include <math.h>

int main() {
    int i=0;
    int digits[]={1,2,3};
    int n=sizeof(digits)/sizeof(digits[0]);
    int Digits=0;
    while (i<n)
    {
        Digits+=digits[i]*(pow(10,n-1-i));
        i++;
    }
    
    
    printf("%d",Digits);
return 0;
}
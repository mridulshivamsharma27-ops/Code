#include<iostream>
using namespace std;
int maximumconsecutiveones(int *arr,int n){
    int max1=0;
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            count++;
        }
        else{
            count=1;
        }
    max1=max(max1,count);
    }
    return max1;
}
int main(){
    int ar[]={1,1,0,1,1,1,0,1,1};
    int n = sizeof(ar) / sizeof(ar[0]);
    cout << "Maximum consecutive ones: " << maximumconsecutiveones(ar, n);
    return 0;
}
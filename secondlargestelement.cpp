#include<bits/stdc++.h>
using namespace std;
 int largestelement(int *arr,int size){
    int max1=arr[0];
    int max2 =arr[0];
    for (int i = 0; i < size; i++)
    {
        if(arr[i]>max1){
            max2=max1;
            max1 =arr[i];
        }
    }
    return max2;
 }
 int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Second Largest element in the array is "<<largestelement(arr,size)<<endl;
    return 0;   
 }
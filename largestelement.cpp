#include<bits/stdc++.h>
using namespace std;
 int largestelement(int *arr,int size){
    int max =arr[0];
    for (int i = 0; i < size; i++)
    {
        if(arr[i]>max){max =arr[i];}
    }
    return max;
 }
 int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Largest element in the array is "<<largestelement(arr,size)<<endl;
    return 0;   
 }
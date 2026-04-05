// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
int linearsearch(int *arr,int size,int target){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==target){
            return i;
        }

    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int target;
    cout<<"Enter the element to be searched: ";
    cin>>target;
    int result=linearsearch(arr,size,target);
    if(result==-1){
        cout<<"Element not found in the array"<<endl;
    }
    else{
        cout<<"Element found at index "<<result<<endl;
    }
    return 0;
}
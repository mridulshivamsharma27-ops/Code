#include <iostream>
using namespace std;
void brute(int *arr,int n,int x){
    x=x%n;
    int temp[n];
    int j=0;
    for(int i=0;i<x;i++){
        temp[i]=arr[i];
    }
    for(int i=x;i<n;i++){
    arr[i-x]=arr[i];
    }
    for (int i = n-x; i < n; i++)
    {
        arr[i]=temp[j++];
    }
    
    return ;
}


int main() {

    int n=7,x;
    int arr[n]={1,2,3,4,5,6,7};
    cout<<"Enter number of left rotations: ";
    cin>>x;
    brute(arr,n,x);
    cout<<"Array after left rotation by "<<x<<": ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}
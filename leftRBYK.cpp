#include <iostream>
#include<vector>
using namespace std;

void brute(vector <int> &arr,int x){
    vector <int> temp;
    temp.reserve(x);

    for(int i=0;i<x;i++){
        temp.push_back(arr[i]);
    }
    
    int n=arr.size();
    x=x%n;

    for(int i=x;i<n;i++){
    arr[i-x]=arr[i];
    }

    int j=0;
    for (int i = n-x; i < n; i++)
    {
        arr[i]=temp[j++];
    }
    
    return ;
}

int main() {
    vector <int> arr={1,2,3,4,5,6,7};
    int n=arr.size();
    int x;
    cout<<"Enter number of left rotations: ";
    cin>>x;
    brute(arr,x);
    cout<<"Array after left rotation by "<<x<<": ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}
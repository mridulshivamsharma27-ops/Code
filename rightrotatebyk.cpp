#include <iostream>
#include<vector>
using namespace std;

void bruterotate(vector <int> &arr,int x){
    vector<int> temp;
    temp.reserve(x);
    int n=arr.size();
    x=x%n;
    for(int i=n-x;i<n;i++){
        temp.push_back(arr[i]);
    } 
    for (int i = n-x-1; i >=0; i--)
    {
        arr[i+x]=arr[i];
    }
    for(int i=0;i<x;i++){
        arr[i]=temp[i];
    }
    
}
int main() {
    vector <int> arr={1,2,3,4,5,6,7};
    int n=arr.size();
    int x;
    cout<<"Enter number of right rotations: ";
    cin>>x;
    bruterotate(arr,x);
    cout<<"Array after right rotation by "<<x<<": ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
return 0;
}
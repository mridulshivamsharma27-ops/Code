#include<iostream>
#include<set>
using namespace std;

void removeduplicate(int *arr,int n){
    set <int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    cout<<"Array after removing duplicates: ";
    for(auto it:st){
        cout<<it<<" ";
    }
    return;
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    removeduplicate(arr,n);
    cout<<endl;
    return 0;
}
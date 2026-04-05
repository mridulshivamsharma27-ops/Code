
    /* Optimal */

#include<iostream>
using namespace std;
#define n 10
void moveZerosOptimal(int arr[], int p) {
    int j = 0;
    for(int i=0; i<p; i++) {
        if(arr[i] != 0) {
            arr[j++] = arr[i];
        }
    }
    while(j < p) {
        arr[j++] = 0;
    }
}
int main(){
    int arr[n]={1,0,2,3,2,0,0,4,5,1};
    cout<<"Before Movement"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ,";
    }
    cout<<endl;
    moveZerosOptimal(arr,n);
    cout<<"After Movement"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ,";
    }
    cout<<endl;
    return 0;
}
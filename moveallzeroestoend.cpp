
/* Brute */


#include<iostream>
# define n 10
using namespace std;
void moveallzeroestoend(int *arr,int size){
    int j=0;
    int temp[size]={0};
    /* Temporay Array Creation */
    for(int i=0;i<size;i++){
        if(arr[i]!=0){
        temp[j++]=arr[i];
}
    }
    /* Array relocate*/
    for(int i=0;i<size;i++){
        arr[i]=temp[i];
    }
    return;
}
int main(){
    int arr[n]={1,0,2,3,2,0,0,4,5,1};
    cout<<"Before Movement"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ,";
    }
    cout<<endl;
    moveallzeroestoend(arr,n);
    cout<<"After Movement"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ,";
    }
    cout<<endl;
    return 0;
}
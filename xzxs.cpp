#include<iostream>
using namespace std;
#define n 10
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void moveallzeroestoend(int *arr,int p){
    int j=-1;
    for(int i=0;i<p;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return;
    for(int i=j+1;i<p;i++){
        if(arr[i]!=0){
            swap(&arr[i],&arr[j]);
            j++;
        }
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
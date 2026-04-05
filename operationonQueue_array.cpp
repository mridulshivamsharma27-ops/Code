#include<iostream>
#define mysize 100

using namespace std;

struct Queue{
    int start=-1,end=-1;
    int arr[mysize];
/*--------------------------------------------------------------Operations---------------------------------------------------------------------*/
void push(int k){
    if(end>=mysize-1){
        cout<<"Queue overflow!\n";
        return;
    }
    if(start<0){
        start=0;

    }
    end++;
    arr[end]=k;
}
void pop(){
    if(start<0 ||start>end){
        cout<<"Error!\n";
    }
    else{
        start++;
        if(start>end){
            start=end=-1;
        }
    }
}
void display(){
    if(start<0 ||start>end){
        cout<<"Error!\n";
    }
    cout<<"Elements: ";
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}
int size(){
    if (start == -1 || start > end) return 0;
    return end-start+1;
}
int Front(){
    if(start>=0){
        return arr[start];
    }
    else{
        cout<<"Queue is empty!\n";
    }
    return -1;
}
};
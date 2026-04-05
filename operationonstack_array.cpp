#include<iostream>
#define mysize 100

using namespace std;

struct stack{
    int top=-1;
    int arr[mysize];
/*--------------------------------------------------------------Operations---------------------------------------------------------------------*/
void push(int k){
    if (top >= mysize - 1) {
        cout << "Stack Overflow! Cannot push " << k << endl;
        return;
    }
    top++;
    arr[top]=k;
}
void pop(){
    if (top>=0){
        top--;
        return ;
    }
    else{
        return ;
    }
}
void display(){
    cout<<"Elements: ";
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}
int size(){
    return top+1;
}
int Top(){
    if(top>=0){
        return arr[top];
    }
    else{
        cout<<"Stack is empty!\n";
    }
    return -1;
}
};
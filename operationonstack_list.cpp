#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    /* Constructor */
    Node(int data1,Node *next1=nullptr){
        data=data1;
        next=next1;
    }
};
struct stack{
    Node* Top=nullptr;
/*--------------------------------------------------------------Operations---------------------------------------------------------------------*/
void push(int k){
    Node* z=new Node(k,Top);
    Top=z;
    return;
}
int pop() {
        if (Top == nullptr) {
            return -1; 
        }
        Node *nodetodelete = Top;
        int val = nodetodelete->data; 
        Top = Top->next;
        delete nodetodelete;
        return val; 
}
int top(){
    if(Top==nullptr){
        cout<<"Stack is empty!\n";
        return -1;
    }
    else{
        return Top->data;
    }
}
int size(){
    if(Top==nullptr){
        cout<<"Stack is empty!\n";
        return -1;
    }
    Node* temp=Top;
    int i=0;
    while(temp!=nullptr){
        i++;
        temp=temp->next;
    }
    return i;

}
void Display(){
    if(Top!=nullptr){
        Node *temp=Top;
        cout<<"Elements: ";
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        return;
    }
    else{
        return;
    }
}
};
#include<iostream>
using namespace std;
struct node {
    int data;
    struct node *next;
};
struct node *s,*e;
int mysize=0;
void push(int n){
    struct node *temp=new node ();
    temp->data=n;
    if(s==NULL){
        s=e=temp;
    }
    else{
        e->next=temp;
    }
    mysize++;
    return;
}
void pop(){
struct node *temp=new node ();
    if(s==NULL){
    temp=s;
    s=s->next;
    delete temp;
}
    if(s>e){
        return ;
    }
    mysize--;
    return;
}
int top(){
    if(s!=NULL){
        return s->data;
    }
}
int size(){
    return mysize;
}
void display(){
    struct node *temp=new node();
    temp=s;
    if(e==NULL){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"Elements-> ";
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}
int main(){
    push(20);
    push(30);
    cout<<"Top-> "<<top()<<endl;
    display();
    return 0;
}
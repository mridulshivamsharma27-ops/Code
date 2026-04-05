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
struct queue{
    Node* start=nullptr;
    Node* end=nullptr;
/*--------------------------------------------------------------Operations---------------------------------------------------------------------*/
void Enqueue(int k){
    Node* z=new Node(k,nullptr);
    if(start==nullptr){
        start=end=z;
        return;
    }
    end->next=z;
    end=z;
}
int Dequeue() {
    if (start == nullptr) {
        cout << "Queue is empty!\n";
        return -1;
    }
    Node *nodetodelete = start;
    int val = nodetodelete->data; 
    start = start->next;
    if (start == nullptr) {
        end = nullptr;
    }
    delete nodetodelete;
    return val; 
}
int Front(){
    if(start==nullptr){
        cout<<"Stack is empty!\n";
        return -1;
    }
    else{
        return start->data;
    }
}
void Display(){
    if(start!=nullptr){
        Node *temp=start;
        cout<<"Elements: ";
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        return;
    }
    else{
        return ;
    }
}
int size(){
    if(start==nullptr){
        cout<<"Stack is empty!\n";
        return -1;
    }
    Node* temp=start;
    int i=0;
    while(temp!=nullptr){
        i++;
        temp=temp->next;
    }
    return i;
}
};
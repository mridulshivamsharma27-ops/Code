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
        return 0;
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
/* Approach-1(not optimal) */
struct queue{
    stack a; 
    void enqueue(int x) {
        int s = a.size(); 
        a.push(x);     
        for (int i = 0; i < s; i++) {
            a.push(a.pop()); 
        }
    }
    void dequeue() {
        a.pop(); 
    }
    void displayQueue() {
        cout<<"Queue(Front to Rear):";
        a.Display();
    }
    int front(){
        return a.Top?a.Top->data:-1;
    }
};
    /* Approach-2(optimal) */
struct queue_optimal {
    stack s1; 
    stack s2; 
    void enqueue(int x) {
        s1.push(x);
    }
    int dequeue() {
        if (s2.Top == nullptr) {
            while (s1.Top != nullptr) {
                s2.push(s1.pop());
            }
        }
        if (s2.Top == nullptr) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return s2.pop();
    }
    int front() {
        if (s2.Top == nullptr) {
            while (s1.Top != nullptr) {
                s2.push(s1.pop());
            }
        }
        return (s2.Top != nullptr) ? s2.top() : -1;
    }
    bool empty() {
        return (s1.Top == nullptr && s2.Top == nullptr);
    }
};
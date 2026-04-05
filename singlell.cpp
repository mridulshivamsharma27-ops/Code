#include<iostream>
#include<vector>

using namespace std;
/* Node of a linkedlist */
struct Node{
    int data ;
    Node* next;

    /* Constructor */
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};
Node * linkedlist(vector<int> &nums){
Node *Head=nullptr;
Node *Tail=nullptr;

for(auto it:nums){
    Node *a=new Node(it,nullptr);
    if(Head==nullptr){
        Head=Tail=a;
    }
    else{
        Tail->next=a;
        Tail=a;
    }
    return Head;
}
}
int main(){
}

#include <iostream>
#include <vector>
#include<stack>
/* #include <span> */

using namespace std;
struct Node {
    int data;
    Node *next, *prev;
    /* Constructor */
    Node(int data1, Node *next1 = nullptr, Node *prev1 = nullptr) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* creationofDll(vector<int> vec) {
    if (vec.empty()) return nullptr; // Handle empty vector case
    Node* head = new Node(vec[0]);
    Node* tail = head;
    /*     for(int value:span(vec).subspan(1)){ 
         The line for (int value : span(vec).subspan(1)) is a modern C++ way to say: "Loop through every element of the vector, but skip the very first one." 
        Node *a=new Node(value,nullptr,tail);
        tail->next=a;
        tail=a;   
    */
    for (size_t i = 1; i < vec.size(); i++) {
        Node* newNode = new Node(vec[i], nullptr, tail);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}
void traverse(Node *&head, Node *&tail) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    string s;
    cout << "Which Way? (f = forward, b = backward): ";
    cin >> s;
    if (s == "f") {
        Node *temp = head;
        cout << "head <-> ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "tail" << endl;
    } else if (s == "b") {
        Node *temp = tail;
        cout << "tail <-> ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "head" << endl;
    }
}
Node *insertionof_fn(int value,Node *&head,Node *&tail){
    Node *a=new Node(value,nullptr,nullptr);
    if(head==nullptr){
        head=tail=a;
        return head;
    }
    else{
        tail->next=a;
        a->prev=tail;
        tail=a;

    }
    return head;
} 
Node *deletionof_fn(Node *&head,Node *&tail){
    if(head==nullptr) {
        cout<<"Linked list is empty\n";
        return head;
    }
    else if(head==tail){
        Node *temp=head;
        delete temp;
        head=tail=nullptr;
        cout<<"Linked list is empty\n";
        return head;
    }
    else{
        Node *temp=head;
        head=head->next;
        head->prev=nullptr;
        delete temp;
        return head;
    }
}
Node *insertionOf_lstnode(int value,Node *&head,Node *&tail){
if (head == nullptr) {
        head = tail = new Node(value);
    } else {
        Node *a = new Node(value, nullptr, tail);
        tail->next = a;
        tail = a;
    }
    return head;
}
Node *deletionof_lstnode(Node *&head,Node *&tail){
    if(head==nullptr){
        cout<<"The Linked List is empty.\n";
    }
    else if(head==tail){
        Node *temp=head;
        delete temp;
        head=tail=nullptr;
    }
    else{
        Node *temp=tail;
        tail=tail->prev;
        tail->next=nullptr;
        delete temp;
    }
    return head;
}
Node *inserionbeforehead(int value,Node *&head,Node *&tail){
    if(head==nullptr){
        Node *a=new Node(value,nullptr,nullptr);
        head=tail=a;
        cout<<"Linked list is empty.\n";
    }
    else{
        Node *a=new Node(value,head,nullptr);
        head->prev=a;
        head=head->prev;
    }
    return head;
}
int lengthofdll(Node *&head,Node *&tail){
    int count=0;
    Node *temp=head;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
} 
Node *insertionatkposition(int pos, int value, Node *&head, Node *&tail) {
    int n = lengthofdll(head, tail);
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid Position!\n";
        return head;
    }
    if (pos == 1) {
        return inserionbeforehead(value, head, tail);
    }
    if (pos == n+1) {
        return insertionOf_lstnode(value, head, tail);
    }
    Node *temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    Node *a = new Node(value, temp, temp->prev);
    temp->prev->next = a; 
    temp->prev = a;
    return head;
}
Node *deletionatkposition(int pos,Node *&head,Node *&tail){
    int n=lengthofdll(head,tail);
    if(pos<1 || pos>n+1){
        cout<<"Invalid Position!\n";
        return head;
    }
    if(pos==1){
        return deletionof_fn(head,tail);
    }
    if(pos==n){
        return deletionof_lstnode(head,tail);
    }
    Node *temp=head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    /* temp->prev=temp->next =nullptr; */
    delete temp;
    return head;
}
Node* reverseDll(Node *&head, Node *&tail) {
    /* Optimized Solution */
    if (head == nullptr || head == tail) return head; 
    Node *current = head;
    Node *temp = nullptr;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    temp = head;
    head = tail;
    tail = temp;
    return head;
}
Node *reversedlleay(Node *&head,Node *&tail){
    /* Brute Force */
    stack<int> stk;
    Node *temp=head;
    while(temp!=nullptr){
        stk.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        temp->data=stk.top();
        stk.pop();
        temp=temp->next;
    }
}
Node *DeleteOccurence(Node *&head,Node *&tail,int value){
    Node *temp;
    temp=head;
    while(temp!=nullptr){
        if(temp->data==value){
            Node *Nodedlete=temp;
            if(temp->prev!=nullptr){
                temp->prev->next=temp->next;
            }
            else{
                head=temp->next;
            }
            if(temp->next!=nullptr){
                temp->next->prev=temp->prev;
            }
            else{
                tail=temp->prev;
            }
            temp=temp->next;
            delete Nodedlete;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}
/* Node *RemoveOccurencefromsortedll(Node *&head,Node *&tail){
    if((!head)||(!tail)) return nullptr;
    Node *temp;
    temp=head;
    while(temp!=nullptr){
        if(temp->data ==temp->next->data){
            Node *Nodetodelete=temp->next;
            temp->next=temp->next->next;
            temp->next->next->prev=temp;
            temp=temp->next;
            delete Nodetodelete;
        }
    }
    return head;
} */
/* Correct code */
Node *RemoveDuplicates(Node *&head, Node *&tail) {
    if (!head) return nullptr;
    Node *temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        if (temp->data == temp->next->data) {
            Node *Nodetodelete = temp->next;
            temp->next = Nodetodelete->next;
            if (temp->next != nullptr) {
                temp->next->prev = temp;
            } else {
                tail = temp;
            }
            delete Nodetodelete;
        } 
        else {
            temp = temp->next;
        }
    }
    return head;
}
vector<vector<int>> Findairwithgivensum(Node *&head,Node *&tail,int target){
    vector<vector<int>> matrix;
    if((!head)||(!tail)) return matrix;
    Node *left=head;
    Node *right=tail;
    while(left != nullptr && right != nullptr && left != right && right->next != left){
        int sum=left->data+right->data;
        if(sum==target) {
            matrix.push_back({right->data,left->data});
            left=left->next;
            right=right->prev;
        }
        else if(sum>target){
            right=right->prev;
        }
        else if(sum<target){
            left=left->next;
        }
    }
    return matrix;
}
int main() {
    vector<int> v = {10, 20, 30};
    Node* head = creationofDll(v);
    Node* tail = head;
    if (tail) {
        while (tail->next != nullptr) tail = tail->next;
    }
    traverse(head, tail); 
    inserionbeforehead(5, head, tail);
    insertionOf_lstnode(40, head, tail);
    insertionatkposition(3, 25, head, tail);
    traverse(head, tail);
    deletionof_fn(head, tail);
    deletionof_lstnode(head, tail);
    deletionatkposition(2, head, tail);
    traverse(head, tail);
    return 0;
}
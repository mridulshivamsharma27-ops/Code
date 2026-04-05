#include<iostream>
#include<vector>
#include<stack>
#include<map>


using namespace std;

struct Node{
    int data;
    Node *next;

    /* constructor */
    Node(int data1,Node *next1){
        data=data1;
        next=next1;
    }
};
Node *head=nullptr;
Node *tail=nullptr;

Node *createlinkedlist(vector<int> &nums){
    for(auto it:nums){
        Node *a=new Node(it,nullptr);
        if(head==nullptr){
            head=tail=a;
        }
        else{
            tail->next=a;
            tail=a;
        }
    }
    return head;
}

Node *deletefirstnode(Node *& head,Node *& tail){
    Node *temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node *insertfirstnode(int value,Node *& head,Node *& tail){
    Node *a=new Node(value,nullptr);
    a->next=head;
    head=a;
    if(tail==nullptr) tail=a;
    return head;
}

Node *insertlastnode(int value,Node *& head,Node *& tail){
    Node *a=new Node(value,nullptr);
    if(head==nullptr) head=tail=a;
    else{
        tail->next=a;
        tail=a;
    }
    return head;

}

Node *deletelastnode(Node *& head,Node *& tail){
    if(head==nullptr) return nullptr;
    if(head==tail){
        delete head;
        cout<<"Linked list is Null."<<endl;
        head=tail=nullptr;
        return nullptr;
    }
    Node *temp=head;
    while((temp->next->next)!=nullptr){
        temp=temp->next;
        delete temp->next;
        temp->next=nullptr;
        tail=temp;
    }
    return head;
}

int lengthofll(Node *& head){
    int count=0;
    Node *temp=head;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}

int searchLL(Node *& head,int x){
    int idx=0;
    Node *temp=head;
    while(temp!=nullptr){
        if(temp->data==x){
            return idx;
        }
        idx++;
        temp=temp->next;
    }
    return -1;
}
/* Brute Force */
Node* middleofll(Node *&head,Node *&tail){
    int count=0;
    Node *temp=head;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    int middle =count/2;
    temp=head;
    for(int i=0;i<middle;i++){
        temp=temp->next;
    }
    return temp;
}
/* Optimized (Tortoise Hare method) */
Node *Tortoise_HareRun(Node *&head,Node *&tail){
    Node *Slow,*fast;
    Slow=fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        Slow=Slow->next;
        fast=fast->next->next;
    }
    return Slow;
}
/* int Tortoise_HareRunInt(Node *&head,Node *&tail){
    int index=0;
    Node *Slow,*fast;
    Slow=fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        Slow=Slow->next;
        fast=fast->next->next;
        index++;
    }
    return index;
} */
int findLengthOfLoop(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            int count = 1;
            Node *temp = slow;
            while (temp->next != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    return 0;
}
Node *floydcyclefinding(Node *&head,Node *&tail){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node * f,*s;
    f=s=head;
    while(f!=nullptr &&f->next!=nullptr){
        f=f->next->next;
        s=s->next;                  /* u can use f reducing entry variable by making f=head when f=s */
        if(s==f){
            Node *entry=head;
            while(entry!=s){
                s=s->next;
                entry=entry->next;
            }
            return entry;
        }
    }
    return nullptr;
}
Node* reverseofll(Node *&head,Node *&tail){
    Node *prev,*curr,*next;
    prev=next=nullptr;
    curr=head;
    while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
} 
    /*Efficient One  */
Node* deleteMiddle(Node *&head, Node *&tail) {
    if (head == nullptr || head->next == nullptr) {
        if (head != nullptr) delete head;
        head = tail = nullptr;
        return nullptr;
    }
    Node *slow = head, *fast = head, *prev = nullptr;
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    if (slow == tail) {
        tail = prev;
    }
    delete slow; 
    return head;
}
/*  Error: If the list has only two nodes (e.g., 1 -> 2), your prev pointer is never initialized before it is used (prev->next =         s->next). This will cause a crash.
Node* deleteMiddle(Node *&head,Node *&tail) {
    if(head!=nullptr && head->next!=nullptr){
        Node* s,*f,*prev; 
        s=f=head;
        while(f!=nullptr && f->next!=nullptr){
            prev=s;
            s=s->next;
            f=f->next->next;
        }
        prev->next=s->next;

        delete s;
        return head;
    }
    return nullptr;
} */
                /*Brute force*/
bool Palindrome(Node *&head,Node *&tail){
    if (!head || !head->next) return true;
    bool flag =true;
    stack<int> st;
    Node *temp=head;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(temp->data!=st.top()){
            flag=false;
            break;
        }
        st.pop();
        temp=temp->next;
    }
    return flag;
}
/*         Efficient Way
bool Palindrome1(Node *&head,Node *&tail){
    if(head==nullptr || head->next==nullptr) return true;
    Node *temp=head;
    Node *mid=Tortoise_HareRun(head,tail);
    Node *reverse=reverseofll(mid,tail);
    bool flag=true;
    while(reverse!=nullptr){
        if(temp->data!=reverse->data){
            flag=false;
            break;
        }
        temp=temp->next;    
        reverse=reverse->next;
    }
    return flag;
} */
/* Efficient Way ($O(1)$ Space) */
bool Palindrome1(Node *&head, Node *&tail) {
    if (head == nullptr || head->next == nullptr) return true;
    Node *mid = Tortoise_HareRun(head, tail);
    Node *revHead = reverseofll(mid, tail);
    Node *first = head;
    Node *second = revHead;
    bool flag = true;
    while (second != nullptr) {
        if (first->data != second->data) {
            flag = false;
            break;
        }
        first = first->next;
        second = second->next;
    }
    reverseofll(revHead, tail);
    return flag;
}
Node* removeNthFromEnd(Node*& head, int n) {
    Node* fast = head;
    Node* slow = head;
    for (int i = 0; i < n; i++) {
        if (fast == nullptr) return head; 
        fast = fast->next;
    }
    if (fast == nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    Node* nodeToDelete = slow->next; 
    slow->next = nodeToDelete->next; 
    delete nodeToDelete;
    return head;
}
        /* Brute force */
Node *Sortll0s1s2s(Node *&head, Node *&tail) {
    if (head == nullptr || head->next == nullptr) return head; 
    int count0 = 0, count1 = 0, count2 = 0;
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->data == 0) count0++;
        else if (temp->data == 1) count1++;
        else if (temp->data == 2) count2++;
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr) {
        if (count0 > 0) {
            temp->data = 0;
            count0--;
        } else if (count1 > 0) {
            temp->data = 1;
            count1--;
        } else {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
    return head;
}
Node* sortll0s1s2s(Node*& head, Node*& tail) {
    if (head == nullptr || head->next == nullptr) return head;
    Node* zeroHead = new Node(-1,nullptr);
    Node* oneHead = new Node(-1,nullptr);
    Node* twoHead = new Node(-1,nullptr);
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        } else if (temp->data == 1) {
            one->next = temp;
            one = one->next;
        } else {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next != nullptr) ? (oneHead->next) : (twoHead->next);
    one->next = twoHead->next;
    two->next = nullptr;
    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}
Node* sortllintooddeven(Node*& head, Node*& tail) {
    if (head == nullptr || head->next == nullptr) return head;
    Node* oddHead = new Node(-1, nullptr);
    Node* evenHead = new Node(-1, nullptr);
    Node* o = oddHead;
    Node* e = evenHead;
    Node* temp = head;
    while (temp != nullptr) {
        if ((temp->data) % 2 != 0) { 
            o->next = temp;   
            o = o->next;      
        } else {              
            e->next = temp;   
            e = e->next;      
        }
        temp = temp->next;
    }
    o->next = evenHead->next;
    e->next = nullptr;
    head = oddHead->next;
    tail = e; 
    delete oddHead;
    delete evenHead;
    return head;
}
/* Brute Approach */
Node *getintersectionnode(Node *&head1,Node *&head2){
    map<Node *,int> mp;
    Node *temp=head1;
    while(temp!=nullptr){
        mp[temp]=1;
        temp=temp->next;
    }
    temp=head2;
    while(temp!=nullptr){
        if(mp.find(temp)!=mp.end()){
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}
/* Efficient Approach -1*/
Node *getintersectionnode(Node *head1, Node *head2) {
    int l1 = lengthofll(head1);
    int l2 = lengthofll(head2);
    Node* p1 = head1;
    Node* p2 = head2;
    if (l1 > l2) {
        for (int i = 0; i < (l1 - l2); i++) p1 = p1->next;
    } else {
        for (int i = 0; i < (l2 - l1); i++) p2 = p2->next;
    }
    while (p1 != nullptr && p2 != nullptr) {
        if (p1 == p2) return p1; 
        p1 = p1->next;
        p2 = p2->next;
    }
    return nullptr;
}
/*Find Intersection of two linked list(Efficient approach-2)*/
Node*FindYfirstnode_(Node *&head1,Node *&head2){
    Node *temp1,*temp2;
    temp1=head1;
    temp2=head2;
    while(temp1!=temp2){
        temp1 = (temp1 == nullptr) ? head2 : temp1->next;
        temp2 = (temp2 == nullptr) ? head1 : temp2->next;
    }
    return temp1;
}
/* 
 Find Intersection of two linked list
Node*FindYfirstnode_(Node *&head1,Node *&head2){
     Node *temp1,*temp2;
    temp1=head1;
    temp2=head2;
    while(temp1!=temp2){
        if(temp1==nullptr){
         temp1=head2;
        }
        else{
        temp1=temp1->next;
        }
        if(temp2==nullptr){
        temp2=head1;
        }
        else{
            temp2=temp2->next;
        }
     }
    return temp1;
}  */
/* efficient way to add 2numbers represented by linkedlist -approach1*/
Node* addTwoNumbers(Node *&l1, Node *&l2) {
    Node* dummyHead = new Node(0,nullptr);
    Node* curr = dummyHead;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int x = (l1 != nullptr) ? l1->data: 0;
        int y = (l2 != nullptr) ? l2->data: 0;
        int sum = x + y + carry;
        carry = sum / 10;
        curr->next = new Node(sum % 10,nullptr);
        curr = curr->next;
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }
    Node* result = dummyHead->next;
    delete dummyHead; 
    return result;
}
Node* rversekthgropsize(Node* &head,Node* &tail,int size){
    Node *temp=head;

}
int main() {
    vector<int> vals = {1, 2, 2, 1};
    head = createlinkedlist(vals);
    
    cout << "Original List: ";
    Node* p = head;
    while(p) { cout << p->data << " "; p = p->next; }
    cout << endl;

    if(Palindrome1(head, tail)) cout << "Check 1: Is Palindrome" << endl;
    else cout << "Check 1: Not a Palindrome" << endl;

    vector<int> unsorted = {2, 0, 1, 2, 0};
    Node* h2 = nullptr; Node* t2 = nullptr;
    for(auto it : unsorted) insertlastnode(it, h2, t2);
    
    h2 = sortll0s1s2s(h2, t2);
    cout << "Sorted 012: ";
    p = h2;
    while(p) { cout << p->data << " "; p = p->next; }
    cout << endl;

    h2 = removeNthFromEnd(h2, 2);
    cout << "After removing 2nd from end: ";
    p = h2;
    while(p) { cout << p->data << " "; p = p->next; }
    cout << endl;

    return 0;
}
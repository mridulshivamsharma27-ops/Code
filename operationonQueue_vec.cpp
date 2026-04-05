#include<iostream>
#include<vector> 

using namespace std;

struct queue{
    int start=-1;
    int end=-1;
    vector<int> nums;
/*--------------------------------------------------------------Operations---------------------------------------------------------------------*/
void push(int k){
    nums.push_back(k);
    if(start<0){
        start=0;
    }
    else{
        end=nums.size()-1;
    }
}
int size(){
    if(start==-1 || start>end) return 0;
    return end-start+1;
}
void display(){
    if(start==-1|| start>end){
        cout<<"Queue is empty!\n";
    }
    cout<<"Elements: ";
    for(int i=start;i<=end;i++){
        cout<<nums[i]<<",";
    }
    cout<<endl;
}
int peek(){
    if(start==-1||start>end) {
        cout<<"Queue is empty!\n";
        return -1;
    }
    else{
        return nums[start];
    }
}
void pop() {
        if (start == -1 || start > end) {
            cout << "Queue Underflow! Nothing to pop.\n";
            return;
        }
        start++;
        if (start > end) {
            start = -1;
            end = -1;
            nums.clear(); 
        }
    }
};
/* Betetr code
struct queue {
    vector<int> nums;

    void push(int k) {
        nums.push_back(k);
    }

    void pop() {
        if (nums.empty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        // Physically removes the first element and shifts others left
        nums.erase(nums.begin());
    }

    int peek() {
        if (nums.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return nums[0]; // Front is always at 0
    }

    int size() {
        return nums.size();
    }

    void display() {
        if (nums.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Elements: ";
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << (i == nums.size() - 1 ? "" : ",");
        }
        cout << endl;
    }
}; */
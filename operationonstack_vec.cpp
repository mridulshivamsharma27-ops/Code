#include<iostream>
#include<vector>

using namespace std;
struct stackmy{
int top=-1;
vector<int> array;
/*--------------------------------------------------------------Operations---------------------------------------------------------------------*/
    void push(int k){
        array.push_back(k);
        top++;
        return;
    }
    void pop(){
        if(top>=0){
        top--;
        array.pop_back();
        return;
        }
        else{
            return;
        }
    }
    void display(){
        cout<<"Elements: ";
        for(auto it:array){
            cout<<it<<",";
        }
        cout<<endl;
        return;
    }
    int Top(){
        return top;
    }
    int size(){
        return array.size();
    }
    int peek(){
        if(top>=0){
            return array[top];
        }
        else{
            cout<<"Stack is empty!\n";
        }
        return -1;
    }
};

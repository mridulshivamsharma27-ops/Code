#include<stdio.h>
#include<stdlib.h>
#define Size 10
struct MyQueue{
    int arr[Size];
    int Start;
    int End;
};
void initialize(struct MyQueue *s){
    s->Start=-1;
    s->End=-1;
}
void pushQueue(struct MyQueue *s,int x){
    if(s->End==Size-1){
        printf("Queue is full.\n");
    }
    else{
        if (s->Start==-1)
        {
            s->Start=0;
        }
        
        s->End++;
        s->arr[s->End]=x;
        printf("Enter %d element is pushed.\n",x);
    }
    return;
}
void pop(struct MyQueue *s){
    if(s->Start==-1||s->Start>s->End){
        printf("Queue is Empty.\n");
    }
    else{
        
        printf("%d at %d is popped.\n",s->arr[s->Start],s->Start);
        s->Start++;
        if(s->Start>s->End){
            s->Start=-1;
            s->End=-1;
        }
    }
    return ;
}
void Display(struct MyQueue *s){
    if(s->Start==-1||s->Start>s->End){
        printf("Queue is empty.\n");
    }
    else{
        printf("Displaying Queue elements: \n");
        for (int i = s->Start; i <= s->End; i++)
        {
            printf("%d-> ",s->arr[i]);
        }
        printf("END\n");
    }
    return;
}
int main() {
    struct MyQueue myQ; 
    initialize(&myQ);
    pushQueue(&myQ, 10);
    pushQueue(&myQ, 20);
    Display(&myQ);
    pop(&myQ);
    Display(&myQ);  
    return 0;
}
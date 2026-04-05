// 
struct stack{
    int info;
    struct node * next;
};
void getnode(){
    struct node
}

struct  stack push(struct stack *ptr,int item){
    struct stack *p=getnode();
    p->next=ptr;
    p->info=item;
    return p;
}


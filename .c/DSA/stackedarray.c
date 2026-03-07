#include<stdio.h>
#include<stdlib.h>
#define Size 5
struct stack{
int arr[Size];
int top;
};
int main(){
struct stack *s;
s->top=-1;
int choice,item;
while(1){
    printf("----Stack Operations------");
    printf("\n1->Push\n");
    printf("2->Pop\n");
    printf("3->Display\n");
    printf("4->Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:if(s->top==Size-1){
            printf("Stack is full.\n");
    }
    else{
        printf("Enter your Number: ");
        scanf("%d",&item);
        s->top++;
        s->arr[s->top]=item;
        printf("Element %d is added.\n",item);
    }
    break;
    case 2:
        if(s->top==-1){
            printf("Stack is empty.\n");
        }
        else{
            printf("%d at %d is removed.\n",s->arr[s->top],s->top);
            s->top--;
        }
        break;
    case 3:
        if(s->top==-1){
            printf("No element in stack.\n");
        }
        else{
                int i;
            printf("Elements of Stack:\n");
            for(i=s->top;i>=0;i--){
                printf("%d ->",s->arr[i]);
            }
            printf("\n");
        }
        break;
    case 4:
        printf("The Loop is concluded.\n");
        exit(0);
    default:
        printf("Entered choice is invalid.\n");
        while (getchar() != '\n');
        break;
    }
}
return 0;}

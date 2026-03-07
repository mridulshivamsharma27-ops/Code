#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;};
struct node *head=NULL;


struct node* createnode(int data){
    struct node*newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;}
void insertBeginning(int data){
    struct node*newnode=createnode(data);
    if(head==NULL){
        head=newnode;
        newnode->next=head;
        return;
    }
    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newnode->next=head;
    temp->next=newnode;
    head=newnode;
}
void insertEnd(int data) {
 struct node *newnode = createnode(data);
    if (head == NULL) {
    head = newnode;
    newnode->next = head;
return;}
   struct node *temp = head;
  while (temp->next != head) {
     temp = temp->next;}
     temp->next = newnode;
    newnode->next = head;}
void insertAtx(int data, int x) {
    int pos=x;
if (x== 1) {
    insertBeginning(data);
    return;
}
struct node *newnode = createnode(data);
struct node *temp = head;
int i;
for (i = 1; i < pos - 1 && temp->next != head; i++) {
temp = temp->next;
}
newnode->next = temp->next;
temp->next = newnode;
}
void deleteAtx(int x) {
    int pos =x;
if (head == NULL) {
printf("List is empty\n");
return;
}
if (x == 1) {
deleteBeginning();
return;
}
struct node *temp = head;
struct node *prev = NULL;
int i;
for (i = 1; i < pos && temp->next != head; i++) {
prev = temp;
temp = temp->next;
}
if (temp == head) {
printf("Invalid position\n");
return;
}
prev->next = temp->next;
free(temp);
}
void deleteEnd() {
if (head == NULL) {
printf("List is empty\n");
return;
}
if (head->next == head) {
free(head);
head = NULL;
return;
}
struct node *temp = head;
struct node *prev = NULL;
while (temp->next != head) {
prev = temp;
temp = temp->next;
}
prev->next = head;
free(temp);
}
void deleteBeginning() {
if (head == NULL) {
printf("List is empty\n");
return;
}
if (head->next == head) {
free(head);
head = NULL;
return;
}
struct node *temp = head;
struct node *last = head;
while (last->next != head) {
last = last->next;
}
head = head->next;
last->next = head;
free(temp);
}
void display() {
if (head == NULL) {
printf("List is empty\n");
return;
}
struct node *temp = head;
printf("CLL: ");

do {
printf("%d , ", temp->data);
temp = temp->next;
} while (temp != head);

printf("(head)\n");
}
int main() {
int choice, data, pos;
while (1) {
printf("1-> Insert at Beginning\n");
printf("2-> Insert at End\n");
printf("3-> Insert at Position\n");
printf("4-> Delete from Beginning\n");
printf("5-> Delete from End\n");
printf("6-> Delete from Position\n");
printf("7-> Display\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
printf("Enter data: ");
scanf("%d", &data);
insertBeginning(data);
break;
case 2:
printf("Enter data: ");
scanf("%d", &data);
insertEnd(data);
break;
case 3:
    printf("Enter data and position: ");
scanf("%d%d", &data, &pos);
insertAtx(data, pos);
break;
case 4:
deleteBeginning();
break;
case 5:
deleteEnd();
break;
case 6:
printf("Enter position: ");
scanf("%d", &pos);
deleteAtx(pos);
break;
case 7:
display();
break;
default:
printf("Invalid choice\n");
}
}
return 0;
}

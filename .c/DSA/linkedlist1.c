#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
struct Node* next;
};
struct Node* head = NULL;
 
void createlinkedlist() {
    struct Node *newnode, *temp;
    int choice = 1;
while (choice) {
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;}
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if(head == NULL) {
    head = temp = newnode;
    }else {
        temp->next = newnode;
        temp = newnode;}
printf("Do you want to continue (0->No / 1->Yes): ");
scanf("%d", &choice);
}
}
 
void insertBeginning(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = head;
head = newNode;
return;
}
 
void insertEnd(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
if (head == NULL) {
    head = newNode;
    return;}
struct Node* temp = head;
while (temp->next != NULL) {
    temp = temp->next;}
temp->next = newNode;}
 
void insertAtPosition(int value, int pos) {
    int i;
if (pos == 1) {
    insertBeginning(value);
    return;}
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
struct Node* temp = head;
for (i=1; i<pos-1&&temp!= NULL;i++) {
    temp = temp->next;
}
if (temp == NULL) {
    printf("Invalid Position!\n");
    return;}
newNode->next = temp->next;
temp->next = newNode;
}
 
void deleteBeginning() {
if (head == NULL) {
    printf("List is empty!\n");
    return;}
struct Node* temp = head;
head = head->next;
free(temp);
}
 
void deleteEnd() {
if (head == NULL) {
    printf("List is empty!\n");
    return;}
if (head->next == NULL) {
    free(head);
    head = NULL;
    return;}
struct Node* temp = head;
while (temp->next->next != NULL) {
    temp = temp->next;
}
free(temp->next);
temp->next = NULL;
}
 
void deleteAtPosition(int pos) {
    int i;
if (head == NULL) {
    printf("List is empty!\n");
    return;}
if(pos == 1) {
    deleteBeginning();
    return;}
struct Node* temp = head;
for ( i = 1; i < pos - 1 && temp->next != NULL; i++) {
    temp = temp->next;}
if (temp->next == NULL) {
    printf("Invalid Position!\n");
    return;
}
struct Node* nodeToDelete = temp->next;
temp->next = nodeToDelete->next;
free(nodeToDelete);
}
 
void display() {
struct Node* temp = head;
if (temp == NULL) {
    printf("List is empty!\n");
    return;}
printf("Linked List: ");
while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
}
printf("NULL\n");
}
int main() {
int choice, value, pos;
while (1) {
 printf("\n--- MENU ---\n");
 printf("0->Create Linked list\n");
 printf("1->Insert at Beginning\n");
 printf("2->Insert at End\n");
 printf("3->Insert at Position\n");
 printf("4->Delete at Beginning\n");
 printf("5->Delete at End\n");
 printf("6->Delete at Position\n");
 printf("7->Display\n");
 printf("Enter choice: ");
 scanf("%d", &choice);
switch (choice) {
case 0:
 createlinkedlist();
    break;
case 1:
    printf("Enter value: ");
    scanf("%d", &value);
    insertBeginning(value);
    break;
case 2:
    printf("Enter value: ");
    scanf("%d", &value);
    insertEnd(value);
    break;
case 3:
    printf("Enter value and position: ");
    scanf("%d %d", &value, &pos);
    insertAtPosition(value, pos);
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
    deleteAtPosition(pos);
    break;
case 7:
    display();
    break;
default:
        printf("\nInvalid Choice\n");
        break;
        }
        }
return 0;
}
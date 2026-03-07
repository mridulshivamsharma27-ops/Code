#include <stdio.h>
#include <stdlib.h>

// Define struct globally
struct node {
    int data;
    struct node *next;
};

void createlinkedlist() {
    struct node *head = NULL, *newnode, *temp;
    int choice = 1;  // initialize choice

    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (1 for Yes / 0 for No)?: ");
        scanf("%d", &choice);
    }

    // Print linked list
    temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    createlinkedlist();
    return 0;
}
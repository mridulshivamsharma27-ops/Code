#include <stdio.h>

void traverse(int a[], int n);
int insert(int a[], int n);
int delete(int a[], int n);

int main() {
    int a[50], n, i, choice;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do {
        printf("\n1.Traverse\n2.Insert\n3.Delete\n4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse(a, n);
                break;

            case 2:
                n = insert(a, n);
                break;

            case 3:
                n = delete(a, n);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    } while (1);

    return 0;
}

/* Traverse function */
void traverse(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/* Insert function */
int insert(int a[], int n) {
    int pos, item, i;

    scanf("%d%d", &pos, &item);

    if (pos < 0 || pos > n) {
        printf("Invalid Position\n");
        return n;
    }

    for (i = n; i > pos; i--)
        a[i] = a[i - 1];

    a[pos] = item;
    return n + 1;
}

/* Delete function */
int delete(int a[], int n) {
    int pos, i;

    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid Position\n");
        return n;
    }

    for (i = pos; i < n - 1; i++)
        a[i] = a[i + 1];

    return n - 1;
}

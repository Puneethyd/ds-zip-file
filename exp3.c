/*Coding challenge 3:
Design a C function to find the correct position for a given element "item" in the combined sorted doubly linked list when two sorted doubly linked list.*/


#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
int findPosition(struct Node *head1, struct Node *head2, int item) {
    struct Node *p1 = head1;
    struct Node *p2 = head2;
    int count = 0;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data <= p2->data) {
            if (p1->data >= item)
                break;
            count++;
            p1 = p1->next;
        } else {
            if (p2->data >= item)
                break;
            count++;
            p2 = p2->next;
        }
    }
    while (p1 != NULL && p1->data < item) {
        count++;
        p1 = p1->next;
    }
    while (p2 != NULL && p2->data < item) {
        count++;
        p2 = p2->next;
    }
    return count + 1;
}
int main() {
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    int item, position;
    insertEnd(&head1, 10);
    insertEnd(&head1, 20);
    insertEnd(&head1, 30);
    insertEnd(&head2, 15);
    insertEnd(&head2, 25);
    insertEnd(&head2, 35);
    item = 22;
    position = findPosition(head1, head2, item);
    printf("Position of %d in combined sorted list: %d\n", item, position);
    return 0;
}



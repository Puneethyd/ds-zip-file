/*Coding challenge 4:

Design a c function to split a circular singly linked list into two equal halves when the list contains even number of elements*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
void insertEnd(struct Node **head, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

void splitList(struct Node *head, struct Node **head1, struct Node **head2) {
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    *head1 = head;
  *head2 = slow->next;
    slow->next = *head1;
    struct Node *temp = *head2;
    while (temp->next != head)
        temp = temp->next;
    temp->next = *head2;
}
void display(struct Node *head) {
    if (head == NULL)
        return;
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    struct Node *head = NULL;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);
    insertEnd(&head, 60);
    splitList(head, &head1, &head2);
    display(head1);
    display(head2);
    return 0;
}


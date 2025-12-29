/*Coding challenge 2:
Write a C program to remove nth element from the end of a singly linked list.*/


#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
void insertEnd(struct Node **head, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
void removeNthFromEnd(struct Node **head, int n) {
    struct Node *fast = *head;
    struct Node *slow = *head;
    struct Node *temp;
    for (int i = 0; i < n; i++) {
        if (fast == NULL)
            return; // n > length
        fast = fast->next;
    }
    if (fast == NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    temp = slow->next;
    slow->next = temp->next;
    free(temp);
}
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node *head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    printf("Original List:\n");
    display(head);
    removeNthFromEnd(&head, 2);
    printf("After removing 2nd node from end:\n");
    display(head);
    return 0;
}

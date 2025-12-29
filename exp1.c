//Write a c program to find the middle element of the given stack.


#include <stdio.h>
#define MAX 100
struct Stack {
    int arr[MAX];
    int top;
};
void initStack(struct Stack *s) {
    s->top = -1;
}
void push(struct Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}
int findMiddle(struct Stack s) {
    int middleIndex = s.top / 2;
    while (s.top > middleIndex) {
        s.top--;
    }
    return s.arr[s.top];
}
int main() {
    struct Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    int middle = findMiddle(s);
    printf("Middle element of the stack is: %d\n", middle);
    return 0;
}




#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Stack 
{
    int arr[MAX];
    int top;
};
void initStack(struct Stack* stack) 
{
    stack->top = -1;
}
int isFull(struct Stack* stack) 
{
    return stack->top == MAX - 1;
}
int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}
void push(struct Stack* stack, int data) 
{
    if (isFull(stack)) 
	{
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}
int pop(struct Stack* stack) 
{
    if (isEmpty(stack)) 
	{
        printf("Stack underflow\n");
        return -1; 
    }
    return stack->arr[stack->top--];
}
void copyStack(struct Stack* source, struct Stack* dest) 
{
    struct Stack temp;
    int data;
    initStack(&temp);
    while (!isEmpty(source)) 
	{
        data = pop(source);
        push(&temp, data);
    }
    while (!isEmpty(&temp)) 
	{
        data = pop(&temp);
        push(dest, data);
        push(source, data); 
    }
}
void displayStack(struct Stack* stack) 
{
    if (isEmpty(stack)) 
	{
        printf("Stack is empty\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) 
        printf("%d\n", stack->arr[i]);
}
void inputStack(struct Stack* stack) 
{
    int n, data;
    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
	{
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        push(stack, data);
    }
}
int main() 
{
    struct Stack source, dest;
    initStack(&source);
    initStack(&dest);
    inputStack(&source);
    printf("\nSource stack contents:\n");
    displayStack(&source);
    copyStack(&source, &dest);
    printf("\nDestination stack contents (after copy):\n");
    displayStack(&dest);
    printf("\nSource stack contents after copying:\n");
    displayStack(&source);
    return 0;
}

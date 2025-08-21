#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct stack
{
    Node* top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = NULL;
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Stack Overflow (no memory)\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack)
{
    Node *temp;
    int value;
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    temp = stack->top;
    value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}
void display(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }

    Node* temp = stack->top;
    printf("Stack elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped: %d\n", pop(&stack));
    display(&stack);

    return 0;
}

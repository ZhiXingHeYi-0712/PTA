#include <stdio.h>
#include <stdlib.h>

typedef int StackElementType;
typedef struct StackElement *StackNode;

struct Stack
{
    StackNode StackTop;
    StackNode StackBottom;
};

struct StackElement
{
    StackElementType data;
    StackNode next;     // to top
    StackNode previous; // to bottom
};

typedef struct Stack *Stack;

int fib(int, int, int);
void push(Stack, StackElementType);
StackElementType pop(Stack);
Stack createEmptyStack();

void push(Stack stack, StackElementType e)
{
    StackNode node = malloc(sizeof(struct StackElement));
    node->data = e;

    if (stack->StackBottom == NULL) // empty
    {
        stack->StackBottom = node;
        stack->StackTop = node;
        node->next = NULL;
        node->previous = NULL;
    }
    else
    {
        node->previous = stack->StackTop;
        node->next = NULL;
        stack->StackTop->next = node;
        stack->StackTop = node;
    }
}

StackElementType pop(Stack stack)
{
    if (stack->StackBottom == stack->StackTop)
    {
        StackElementType result = stack->StackTop->data;
        free(stack->StackTop);
        stack->StackBottom = NULL;
        stack->StackTop = NULL;
        return result;
    }
    else
    {
        StackNode newTop = stack->StackTop->previous;
        newTop->next = NULL;
        StackElementType result = stack->StackTop->data;
        free(stack->StackTop);
        stack->StackTop = newTop;
        return result;
    }
}

Stack createEmptyStack()
{
    Stack emptyStack = malloc(sizeof(struct Stack));
    emptyStack->StackBottom = NULL;
    emptyStack->StackTop = NULL;
    return emptyStack;
}

int main()
{
    int n;
    scanf("%d", &n);
    Stack stack = createEmptyStack();
    for (int i = 1; i <= n; i++)
    {
        if (i <= 2)
        {
            push(stack, fib(i, 0, 0));
        }
        else
        {
            int last1 = pop(stack);
            int last2 = pop(stack);
            int ans = fib(i, last1, last2);
            push(stack, last2);
            push(stack, last1);
            push(stack, ans);
        }
    }

    int outputCount = 0;
    StackNode iterator = stack->StackBottom;
    for (int i = 0; i < n; i++)
    {
        printf("%-10d", iterator->data);
        outputCount++;
        iterator = iterator->next;
        if (outputCount == 4)
        {
            printf("\n");
            outputCount = 0;
        }
    }

    return 0;
}

int fib(int n, int last1, int last2)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return last1 + last2;
    }
}

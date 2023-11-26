#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node stack;
stack *head = NULL;

void push(int value)
{
    stack *ptr = head;
    stack *new = (stack *)malloc(sizeof(stack));
    if (head == NULL)
    {
        head = new;
        new->data = value;
        new->next = NULL;
    }
    else
    {
        new->data = value;
        new->next = NULL;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
}

void pop()
{
    stack *ptr = head;
    if (head == NULL)
    {
        printf("Underflow\n");
        return;
    }
    else if (ptr->next == NULL)
    {
        printf("No item in the stack\n");
        head = NULL;
        return;
    }
    else
    {
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = NULL;
    }
}

void print_stack()
{
    stack *ptr = head;
    printf("Stack: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    push(6);
    push(7);
    push(8);
    push(9);
    pop();
    print_stack();
}
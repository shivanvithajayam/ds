#include <stdio.h>
# define max 5
char stack[max];
int top=-1;
void push(char item)
{
    if(top==max-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top]=item;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("Popped element: %c\n", stack[top--]);
    }
}
void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for(int i=top;i>=0;i--)
        {
            printf("%c ",stack[i]);
        }
        printf("\n");
    }
}
void main()
{
    int choice;
    char item;
    while(1)
    {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf(" %c",&item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}


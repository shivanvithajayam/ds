#include<stdio.h>
#include<ctype.h>
#define size 10
char stack[size];
int top=-1;
void push(char item)
{
    stack[++top]=item;
}
char pop()
{
    return(stack[top--]);
}
int pr(char symbol)
{
    if(symbol=='^')
    {
        return(3);
    }
    else if(symbol=='*'||symbol=='/')
    {
        return(2);
    }
    else if(symbol=='+'||symbol=='-')
    {
        return(1);
    }
    else{
        return 0;
    }   
}
int main()
{
    char infix[10],postfix[10];
    int i=0,k=0;
    printf("enter infix exp");
    scanf("%s",infix);
    for(int i=0;infix[i]!='\0';i++)
    {
        if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else
        {
            if(isalnum(infix[i]))
            {
                postfix[k++]=infix[i];
            }
            else
            {
                if(infix[i]==')')
                {
                    while(stack[top]!='(')
                    {
                        postfix[k++]=pop();
                    }
                    pop();
                }
                else{
                    while(top!=-1&&pr(stack[top])>=pr(infix[i]))
                    {
                        postfix[k++]=pop();
                    }
                    push(infix[i]);
                }
            }
        }
    }
    while(top!=-1)
    {
        postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("post fix is %s",postfix);
}

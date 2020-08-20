#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

// stdlib is imported for exit() functionality
// ctype is imported for comparisons like, isdigit()
// string is imported for concatenation of strings
// Basic Operations first.
// Assume maximum length to be 100

char st[100];
int t = -1;

int isempty()
{
    if(t==-1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if(t==99)
        return 1;
    else
        return 0;
}

void push(char element)
{
    if(isfull())
        printf("Stack Overflow\n");
    else
        t++;
        st[t]=element;
}
char pop()
{
    if(isempty())
        printf("Stack Underflow\n");
    else
        t--;
        return st[t+1];
}

// Extra functions
int isop(char s)
{
    if(s=='^'|| s=='/'||s=='*'|| s=='+'||s=='-')
        return 1;
    else
        return 0;
}

int pre(char s)
{
    if(s=='^')
        return(3);
    else if(s=='/' || s=='*')
        return(2);
    else if(s=='+' || s=='-')
        return(1);
    else
        return(0);
}

void change(char i[], char p[])
{
    int a=0;
    int b=0;;
    char el;
    char c;
    push('(');
    strcat(i,")");
    el=i[a];
    while(el!='\0')
    {
        if(el=='(')
            push(el);
        else if(isdigit(el) || isalpha(el))
        {
            p[b]=el;
            b++;
        }
        else if(isop(el)==1)
        {
            c=pop();
            while(isop(c)==1 && pre(c)>=pre(el))
            {
                p[b]=c;
                b++;
                c = pop();
            }
            push(c);
            push(el);
        }
        else if(el==')')
        {
            c = pop();
            while(c!='(')
            {
                p[b]=c;
                b++;
                c=pop();
            }
        }
        else
        {
            printf("\nInvalid Infix Expression.\n");
            getchar();
            exit(1);
        }
        a++;
        el = i[a];
    }
    if(t>0)
    {
        printf("\nInvalid Infix Expression.\n");
        getchar();
        exit(1);
    }
    p[b]='\0';
}
int main()
{
    char infix[100],postfix[100];
    printf("\nEnter Infix: ");
    gets(infix);

    change(infix,postfix);
    printf("Postfix Expression: ");
    puts(postfix);
    // Normal scanf and printf didn't work
    // Hence gets and puts keywords had to be used
    return 0;
}

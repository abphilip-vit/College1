#include<stdio.h>
float ar[10];
int f = -1;
int r = -1;
int isempty()
{
    if(f==r)
        return 1;
    else
        return 0;
}
int isfull()
{
    if(r==9)
        return 1;
    else
        return 0;
}

void enqueue()
{
    if(isfull())
        printf("Queue Overflow\n");
    else
    {
        printf("Enter the element: ");
        scanf("%f",&ar[r]);
        r=r+1;
        printf("\n");
    }
}
void dequeue()
{
    if(isempty())
        printf("Queue Underflow\n");
    else
    {
        printf("%f",ar[f]);
        f=f+1;
        printf("\n");
    }
}
void display()
{
    int i;
    for(i=f;i<r;i++)
        printf("%f \n",ar[i]);
}

void main()
{
    int c,ch=1,a=0;
    printf("1. isEmpty\n2. isFull\n3. Enqueue\n4. Dequeue\n5. Display\nDefault: exit");
    while(ch==1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
                a=isempty();
                if(a==1)
                printf("Queue Underflow\n");
                else
                printf("Queue is not empty\n");
                break;
            case 2:
                a=isfull();
                if(a==1)
                printf("Queue Overflow\n");
                else
                printf("Queue is not full\n");
                break;
            case 3:
                enqueue();
                break;
            case 4:
                dequeue();
                break;
            case 5:
                display();
                break;
            default:
                ch = 0;
        }
    }
}



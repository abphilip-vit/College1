#include<stdio.h>
#include<string.h>

void heapify(int a[], int n, int i)
{
    int s = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && a[left]<a[s])
        s=left;
    if(right<n && a[right]<a[s])
        s=right;
    if(s!=i)
    {
        int z = a[i];
        a[i] = a[s];
        a[s] = z;
        heapify(a,n,s);
    }
}

void sort(int a[], int n)
{
    int i;
    for(i = n/2-1; i>=0; i--)
        heapify(a,n,i);
    printf("Heap: ");
    for(i=0;i<n;i++)
        printf("\n%d",a[i]);
    for(i=n-1;i>=0;i--)
    {
        int z = a[0];
        a[0] = a[i];
        a[i] = z;
        heapify(a,i,0);
        printf("\nInserting...");
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
    }
}

void main()
{
    int i,x;
    printf("Enter the number of employees: ");
    scanf("%d",&x);
    int a[100];
    for(i=0;i<x;i++)
    {
        printf("Enter the age of %d: ", (i+1));
        scanf("%d",&a[i]);
    }
    sort(a,x);
    printf("\nAfter sorting: ");
    for(i=0;i<x;i++)
        printf("\n%d",a[i]);
}



#include<iostream>
using namespace std;

void insert(int a[5][5], int n, int j)
{
    int i;
    i=n%5;
    if(j<=4)
    {
        if(a[i][j]==-1)
        {
            a[i][j]=n;
            return;
        }
        else
        {
            insert(a,n,j+1);
        }
    }
}

void pr(int a[5][5], int n)
{
    int x,y;
    cout<<"\n";
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
            cout<<a[x][y]<<' ';
        cout<<"\n";
    }
}

int main()
{
    int i,n,f;
    int a[5][5] = {{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1}};
    int al[] = {11, 324, 132, 144, 212, 442, 165, 754, 132, 546, 234, 88, 768, 576, 432, 333, 591, 712, 113, 312};
    n=5;
    f=20; // Total Number of values
    for(i=0;i<f;i++)
    {
        insert(a,al[i],0);
    }
    pr(a,n);
}

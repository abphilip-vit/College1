#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node* left;
struct Node* right;
};

struct Node* create()
{
    int a;
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data, and -0 for no new Node: ");
    scanf("%d",&a);
    if(a==-0)
        return 0;
    n->data=a;
    n->left = n->right = NULL;
    printf("Enter left child of %d: ",a);
    n->left = create();
    printf("Enter right child of %d: ",a);
    n->right = create();
    return n;
}

void preorder(struct Node* temp)
{
    if(temp!=NULL)
    {
        printf("%d",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct Node* temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d",temp->data);
    }
}

void inorder(struct Node* temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d",temp->data);
        inorder(temp->right);
    }
}

void main()
{
    struct Node* root = create();

    printf("\n\nPreorder: ");
    preorder(root);

    printf("\n\nPostorder: ");
    postorder(root);

    printf("\n\nInorder: ");
    inorder(root);
    printf("\n");
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct emp{
    int id;
    char name[30];
    int age;
    struct emp *next;
};

struct emp *insert(struct emp *front, int id, char name[],int age){
    struct emp *p;
    p = (struct emp*)malloc(sizeof(struct emp));
    if(p==NULL){
        printf("Can't allocate");
        exit(2);
    }
    p->id = id;
    strcpy(p->name,name);
    p->age = age;
    p->next = front;
    front = p;
    return(front);
}

void printn(struct emp *p){
    printf("\n Employee Details: ");
    printf("\n ID:      %d",p->id);
    printf("\n Name:    %s",p->name);
    printf("\n Age:     %d",p->age);
}

struct emp *deleteNode(struct emp *front, int id){
    struct emp *ptr;
    struct emp *bptr;
    if(front->id==id){
        ptr = front;
        printf("\nNode Deleted: ");
        printn(front);
        front = front->next;
        free(ptr);
        return(front);
    }
    for(ptr=front->next,bptr=front; ptr!=NULL;ptr=ptr->next,bptr=bptr->next){
        if(ptr->id==id){
            printf("\nNode Deleted: ");
            printn(ptr);
            bptr->next = ptr->next;
            free(ptr);
            return(front);
        }
    }
    printf("\nEmployee Number %d not found \n",id);
    return(front);
}


void search(struct emp *front, int key){
    struct emp *ptr;
    for(ptr=front;ptr!=NULL;ptr=ptr->next){
        if(ptr->id==key){
            printf("\nKey Found: ");
            printn(ptr);
            return;
        }
    }
    printf("\nEmployee number %d not found ",key);
}

void display(struct emp *front){
    struct emp *ptr;
    for(ptr=front;ptr!=NULL;ptr=ptr->next)
        printn(ptr);
}

void main(){
    struct emp *ll;
    char name[30];
    int age, id, choice;

    ll = NULL;
    printf("Single Linked List\n\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Search\n");
    printf("Else: Exit\n");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("ID: ");
                scanf("%d",&id);
                printf("Name: ");
                fflush(stdin);
                gets(name);
                printf("Age: ");
                scanf("%d",&age);
                ll = insert(ll,id,name,age);
                break;
            case 2:
                printf("Enter the ID to be deleted: ");
                scanf("%d",&id);
                ll = deleteNode(ll,id);
                break;
            case 3:
                if(ll==NULL){
                    printf("Empty");
                    break;
                }
                display(ll);
                break;
            case 4:
                printf("Enter the ID: ");
                scanf("%d",&id);
                search(ll,id);
                break;
            default:
                printf("Program Closed");
                choice=5;
        }
    }while(choice!=5);
}

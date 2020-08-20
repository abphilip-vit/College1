#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct emp {
    int id;
    int age;
    char name[30];
    struct emp *next;
};

// Make an single function to handle printing everything in the node
void printn(struct emp *e) {
    printf("\nEmployee Details: ");
    printf("\nID:      %d",e->id);
    printf("\nName:    %s",e->name);
    printf("\nAge:     %d",e->age);
}

struct emp *ins(struct emp *front, int id, char name[], int age) {
    struct emp *e;
    e = (struct emp*)malloc(sizeof(struct emp));
    if(e==NULL) {
        printf("\nCan't add new Employees\n");
        exit(2);
    }
    strcpy(e->name,name);
    e->id = id;
    e->age = age;
    e->next = front;
    front = e;
    return(front);
}

struct emp *del(struct emp *front, int id) {
    struct emp *p; // pointers being introduced
    struct emp *bp;
    if(front->id==id) {
        p = front;
        printn(front);
        printf("\nEmployee Found and Record Deleted\n");
        front = front->next;
        free(p);
        return(front);
    }
    for(p=front->next,bp=front; p!=NULL;p=p->next,bp=bp->next) {
        if(p->id==id) {
            printn(p);
            printf("\nEmployee Found and Record Deleted\n");
            bp->next = p->next;
            free(p);
            return(front);
        }
    }
    printf("\nEmployee ID %d not found \n",id);
    return(front);
}

void display(struct emp *front) {
    struct emp *p;
    printf("\nCurrently...");
    for(p=front;p!=NULL;p=p->next)
        printn(p);
}

void main() {
    struct emp *ll;
    char name[30];
    int age, id, choice;

    ll = NULL;
    printf("Single Linked List\n\n");
    printf("1. Add new employee\n");
    printf("2. Search and Delete\n");
    printf("3. Display All\n");
    printf("Else: Exit");
    do {
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter ID: ");
                scanf("%d",&id);
                printf("Enter Name: ");
                fflush(stdin);
                gets(name);
                printf("Enter Age: ");
                scanf("%d",&age);
                ll = ins(ll,id,name,age);
                break;
            case 2:
                printf("Enter the ID to be searched and deleted: ");
                scanf("%d",&id);
                if(ll==NULL) {
                    printf("No Employees Registered");
                    break;
                }
                ll = del(ll,id);
                // After deleting a node, the list should be displayed
                // Hence removing "break" statement

            case 3:
                if(ll==NULL) {
                    printf("No Employees Registered");
                    break;
                }
                display(ll);
                break;

            default:
                printf("\nProgram Closed\n\n");
                choice=0;
        }
    } while(choice!=0);
}

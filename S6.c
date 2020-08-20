#include<stdio.h>
struct polynode
{
      int coef;
      int exp;
      struct polynode *next;
};
typedef struct polynode *polyptr;

polyptr createPoly()
{
      polyptr p, tmp, start = NULL;
      int ch=1;
      while(ch)
      {
            p = (polyptr)malloc(sizeof(struct polynode));
            printf("Enter the coefficient: ");
            scanf("%d",&p->coef);
            printf("Enter the exponent: ");
            scanf("%d",&p->exp);
            p->next = NULL;
            if(start==NULL) start=p;
            else
            {
                  tmp=start;
                  while(tmp->next!=NULL)
                        tmp=tmp->next;
                  tmp->next=p;
            }
            printf("More nodes to be added (1/0): ");
            scanf("%d",&ch);
      }
      return start;
}

void display(polyptr *poly)
{
      polyptr list;
      list=*poly;
      while(list!=NULL)
      {
            if(list->next!=NULL)
                  printf("%d X^ %d + " ,list->coef,list->exp);
            else
                  printf("%d X^ %d " ,list->coef,list->exp);
            list=list->next;
       }
}

polyptr addTwoPolynomial(polyptr *F,polyptr *S)
{
      polyptr A,B,p,result,C=NULL;
      A=*F;B=*S; result=C;
      while(A!=NULL && B!=NULL)
      {
            switch(compare(A->exp,B->exp))
            {
                  case 1:
                        p=(polyptr)malloc(sizeof(struct polynode));
                        p->coef=A->coef;
                        p->exp=A->exp;
                        p->next=NULL;
                        A=A->next;
                        if (result==NULL) result=p;
                        else
                              attachTerm(p->coef,p->exp,&result);
                        break;
                  case 0:
                        p=(polyptr)malloc(sizeof(struct polynode));
                        p->coef=A->coef+B->coef;
                        p->exp=A->exp;
                        p->next=NULL;
                        A=A->next;
                        B=B->next;
                        if (result==NULL) result=p;
                        else
                              attachTerm(p->coef,p->exp,&result);
                        break;

                  case -1:
                        p=(polyptr)malloc(sizeof(struct polynode));
                        p->coef=B->coef;
                        p->exp=B->exp;
                        p->next=NULL;
                        B=B->next;
                        if (result==NULL) result=p;
                        else
                              attachTerm(p->coef,p->exp,&result);
                        break;
            }
      }
      while(A!=NULL)
      {
            attachTerm(A->coef,A->exp,&result);
            A=A->next;
      }
      while(B!=NULL)
      {
            attachTerm(B->coef,B->exp,&result);
            B=B->next;
      }
      return result;
}

int compare(int x, int y)
{
      if(x==y) return 0;
      if(x<y) return -1;
      if(x>y) return 1;
}
attachTerm(int c,int e,polyptr *p)
{
      polyptr ptr,tmp;
      ptr=*p;
      tmp=(polyptr)malloc(sizeof(struct polynode));
      while(ptr->next!=NULL)
      {
            ptr=ptr->next;
      }
      ptr->next=tmp;
      tmp->coef=c;
      tmp->exp=e;
      tmp->next=NULL;
}

main()
{
      polyptr Apoly,Bpoly;
      clrscr();
      printf("Enter the first polynomial : \n");
      Apoly=createPoly();
      display(&Apoly);
      printf("\n");
      Bpoly=createPoly();
      display(&Bpoly);
      printf("\nResult is : ");
      C=addTwoPolynomial(&Apoly,&Bpoly);
      display(&C);
      getch();
}

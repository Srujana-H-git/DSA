#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node{
    struct Node *previous;
    int rollno;
    char name[25];
    struct Node *next;
};
struct Node *getnode()
{
    return malloc(sizeof(struct Node));
}

void readdata(struct Node *p)
{
    printf("enter rollno: \n");
    scanf("%d",&p->rollno);
    printf("enter name \n");
    gets(p->name);
}
void displaydata( struct Node *p)
{
    printf("rollno:%d \t name:%s",p->rollno,p->name);
}
struct Node *createlistRightDLL(int N)
{
    struct Node *nw,*prev,*first;
    int i;
    first= NULL;
    for(i=0;i<N;i++)
    {
        prev=nw;
        nw=getnode();
        Readdata(nw);
        if(first==NULL)
           {
                first=nw;
           }
        else
            prev->next=nw;
        nw->previous=prev;
     }
     nw->next= NULL;
     return(first);
}
struct Node *createlistleft(int N)
{
    struct Node *nw,*prev;
    int i;
    nw= NULL;
    for(i=0;i<N;i++)
    {
        prev=nw;
        nw=getnode();
        Readdata(nw);
        nw->next=prev;
        if(prev!=NULL)
            prev->previous=nw;
    }
    nw->previous=NULL;
    return(nw);
}
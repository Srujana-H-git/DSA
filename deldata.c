#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{int rollno;
char name[20];
struct Node *next;
};


struct Node *getnode()
{
    return malloc(sizeof(struct Node));

}
void Readdata(struct Node *nw)
{
    printf("Enter the Data \n");
    scanf("%d%s",&nw->rollno,nw->name);
}
void displaydata(struct Node *nw)
{
    printf("\n rollno:%d \t name:%s \n ",nw->rollno,nw->name);
}
struct Node *deletedata(struct Node *first, int rollno)
{
    struct Node *prev,*cur;
    for(cur=NULL;cur->rollno!=rollno;cur=cur->next);
        for(prev=NULL;prev->next!=cur;prev=prev->next);
            prev->next=cur->next;
            free(cur);
    return(first);
}

//*****************************CREATE LIST RIGHT*******************************

struct Node *createlistRight(int N)
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
            first=nw;
        else
            prev->next=nw;
     }
     nw->next= NULL;
     return(first);
}
void displayall(struct Node *first)
{
    struct Node *curr;
    if(curr==NULL)
        printf("\n list is empty");
    else
        for(curr=first;curr!=NULL;curr=curr->next)
        displaydata(curr);
}
int main()
{
    int ch,ch2,ch1,ch3;
    int pos;
    char nm[20];
    int N;
    int rollno;
    struct Node *first=NULL;
    printf("Enter number of nodes");
    scanf("%d",&N);
    printf("\n creating list at right \n ");
    first=createlistRight(N);
    printf("\n before deleting \n");
    displayall(first);
    first=deletedata(first,rollno);
    printf("\n before deleting \n");
    displayall(first);  
    return(0);                   
}
#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node *next;
};
struct Node *getnode()
{
    return malloc(sizeof(struct Node));

}
void Readdata(struct Node *nw)
{
    printf("Enter the Data \n");
    scanf("%d",&nw->data);
}
void displaydata(struct Node *nw)
{
    printf("\n Data:%d \n ",nw->data);
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
struct Node *reversedSLL(struct Node *first)
{
    struct Node *p1,*p2,*p3;
    if(first==NULL)
        printf("\n List is empty");
    else if(first->next==NULL)
        printf("\n Only one element is present ,List already reversed");
    else
        p1=first;
        p2=p1->next;
        p3=p2->next;
        while(p2!=NULL)
        {
            p2->next=p1;
            p1=p2;
            p2=p3;
            if(p3!=NULL)
                p3=p3->next;

        }
        first->next=NULL;
        first=p1;
    return(first);
}

int main()
{
    struct Node *first;
    int N;
    printf("\n Enter the list to be reversed \n");
    printf("\n Enter number of nodes");
    scanf("%d",&N);
    first=createlistRight(N);
    printf("\n Reversed list is : ");
    first=reversedSLL(first);
    displayall(first);
    return(0);

}

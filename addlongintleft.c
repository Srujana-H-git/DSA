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
    printf("%d",nw->data);
}
void displayall(struct Node *first)
{
    struct Node *curr;
    for(curr=first;curr!=NULL;curr=curr->next)
        displaydata(curr);
}

struct Node *createlistleft(int N)
{
    struct Node *nw,*prev;
    int i;
    nw=NULL;
    for(i=0;i<N;i++)
    {
        prev=nw;
        nw=getnode();
        Readdata(nw);
        nw->next=prev;

    }
    return(nw);
}


struct Node *reversedSLL(struct Node *first)
{
    struct Node *p1,*p2,*p3;
    if(first==NULL)
        printf("\n List is empty");
    else if(first->next==NULL)
        printf("\n Only one element is present ,List already reversed");
    else
    {
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
    }
        first->next=NULL;
        first=p1;
    return(first);
}

struct Node *addlongint(struct Node *first1, struct Node *first2)
{
    struct Node *p1,*p2,*nw,*prev;
    int sm,carry;
    sm=carry=0;
  //  first1=reversedSLL(first1);
   // first2=reversedSLL(first2);
    for(p1=first1,p2=first2,nw=NULL;p1!=NULL||p2!=NULL||carry==1;)
    {
        prev=nw;
        nw=getnode();

        if (p1!=NULL && p2!=NULL)
            {
                sm=p1->data+p2->data+carry;
                p1=p1->next;
                p2=p2->next;
            }
        else if(p1!=NULL)
            {
                sm=p1->data+carry;
                p1=p1->next;
            }
        else if(p2!=NULL)
            {
                sm=p2->data+carry;
                p2=p2->next;
            }
        else
            {
                sm=carry;
            }
        nw->data=sm%10;
        carry=sm/10;
        nw->next=prev;
    }
        first1=reversedSLL(first1);
      //  displayall(first1);
        first2=reversedSLL(first2);
       // displayall(first2);
        return(nw);
       // displayall(nw);


}

int main()
{
    struct Node*first1,*first2,*first3;
    first1=first2=first3=NULL;
    int n1,n2;
    printf("\n Enter the list 1");
    printf("\n Enter number of nodes");
    scanf("%d",&n1);
    first1=createlistleft(n1);
    //displayall(first1);
    printf("\n Enter the list 2");
    printf("\n Enter number of nodes");
    scanf("%d",&n2);
    first2=createlistleft(n2);
 //    displayall(first2);
    printf("\n Sum of two long integers is:\n ");
    first3=addlongint(first1,first2);
    displayall(first3);
    return 0;   
}
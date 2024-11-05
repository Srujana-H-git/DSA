#include<stdio.h>
#include<stdlib.h>

struct  Node
{
    int coeff;
    int power;
    struct Node *next;
};
struct Node *getnode()
{
    return malloc(sizeof(struct Node));

}
void readData(struct Node *nw)
{
    printf("Enter the Data \n");
    scanf("%d%d",&nw->coeff,&nw->power);
}
void Displaydata(struct Node *nw)
{
    printf("\n coeff:%d \t power:%d",nw->coeff,nw->power);
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
        readData(nw);
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
        Displaydata(curr);
}

struct Node *sumtwoPoly(struct Node*P1,struct Node *P2)
{
    struct Node *first,*nw,*prev;
    first=nw=prev=NULL;
    while(P1!=NULL || P2!=NULL)
    {   
        prev=nw;
        nw=getnode();
        if(P1!=NULL && P2!=NULL && P1->power == P2->power)
            {
                nw->coeff=P1->coeff+P2->coeff;
                nw->power=P1->power;
                P1=P1->next;
                P2=P2->next;

            }
        else 
            if ((P1!=NULL&&P2!=NULL && P1->power>P2->power)||(P1!=NULL&&P2==NULL))
                {
                    nw->coeff=P1->coeff;
                    nw->power=P1->power;
                    P1=P1->next;
                }
            else
                {
                    nw->coeff=P2->coeff;
                    nw->power=P2->power;
                    P2=P2->next;    
                }
        if(first==NULL)
                first=nw;
        else
                prev->next=nw;
        

    }
nw->next=NULL;
return (first);

}
int main()
{
    struct Node *first1 ,*first2 ,*first3;
    int N1,N2;
    first1=first2=first3=NULL;
    printf("Enter first polynimial \n");
    printf("Enter number of nodes \n");
    scanf("%d",&N1);
    first1=createlistRight(N1);
    printf("Enter second polynomial \n");
    printf("Enter number of nodes \n");
    scanf("%d",&N2);
    first2=createlistRight(N2);
    printf("\n Sum of two polynomials is: \n");
    first3=sumtwoPoly(first1,first2);
    displayall(first3);
    return(0);
}
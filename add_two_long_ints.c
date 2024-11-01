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
     for(curr=first;curr!=NULL;curr=curr->next)
        displaydata(curr);
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
struct Node *addlongint(struct Node *first1, struct Node *first2)
{
    struct Node *p1,*p2,*nw,*prev;
    int sum,carry;
    sum=carry=0;
    first1=reversedSLL(first1);
    first2=reversedSLL(first2);
    for(p1=first1,p2=first2,nw=NULL;p1!=NULL||p2!=NULL||carry==1;)
    {
        prev=nw;
        nw=getnode();

        if (p1!=NULL&&p2!=NULL)
            {
                sum=p1->data+p2->data+carry;
                p1=p1->next;
                p2=p2->next;
            }
        else if(p1!=NULL)
            {
                sum=p1->data+carry;
                p1=p1->next;
            }
        else if(p2!=NULL)
            {
                sum=p2->data+carry;
                p2=p2->next;
            }
        else
            {
                sum=carry;
            }
        nw->data=sum%10;
        carry=sum/10;
        nw->next=prev;
    }
        first1=reversedSLL(first1);
        first2=reversedSLL(first2);
        return(nw);


}
long int *reverse(long int n1)
{
    int rev=0,rem,original;
    original=n1;
    while(n1!=0)
    {
        rem=n1%10;
        rev=rev*10+rem;
        n1/=10;
    }
    
}
struct Node*createright(long int n)
{
    struct Node *first,*nw,*prev;
    n=reverse(n);
    first=nw=NULL;
    while(n!=0)
    {
        prev=nw;
        nw=getnode();
        nw->data=n%10;
        if(first==NULL)
            first=nw;
        else
            prev->next=nw;
    }
    nw->next=NULL;
    return(first);
}
int main()
{
    struct Node *first1,*first2,*first3;
    long int n1,n2;
    printf("\n Enter the first integer");
    scanf("%ld",&n1);
    first1=createright(n1);
    printf("\n Enter the second integer");
    scanf("%ld",&n2);
    first1=createright(n2);
    first3=addlongint(first1,first2);
    printf("\n Sum of two long integers:");
    displayall(first3);
    return(0);

}

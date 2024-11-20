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
//*********************************CREATE LIST LEFT********************************/

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

    }
    return(nw);
}

// ********************************INSERT FRONT***************************************
struct Node *Insertfront(struct Node *first)
{
    struct Node *nw;

    { 
        nw=getnode();
        Readdata(nw);
        
         if(first==NULL)
            nw->next=NULL;
        else
            nw->next=first;
    }
    return(nw);
}

// ************************************INSERT REAR*****************************************

struct Node *Insertrear(struct Node *first)
{
    struct Node *last,*nw;
        nw=getnode();
        Readdata(nw);
        nw->next=NULL;
        if(first==NULL)
            return(nw);
        else
           { for(last=first;last->next!=NULL;last=last->next);
            last->next=nw;
           }
             return(first);
}


//****************************************INSERT AT ANY POSITION*****************************
struct Node *InsertatanyPosition(struct Node *first, int pos)
{   int i;
    struct Node *prev,*curr,*nw;
    nw=getnode();
    Readdata(nw);

    for(prev=NULL,curr=first,i=1;i<pos&&curr!=NULL;prev=curr,curr=curr->next,i++)
    if(prev==NULL)
        first=nw;
    else
        prev->next=nw;
    
    nw->next=curr;
    return(first);
}

//********************************************DELETE FRONT**************************************/
struct Node *deletefront(struct Node *first)
{
    struct Node *curr;
    if(first==NULL)
        printf("\n list is empty");
    else 
        {
            curr=first;
            first=first->next;
            printf("Deleted node is:");
            displaydata(curr);
            free(curr);

        }
}

//********************************************DELETE REAR********************************************/
struct Node *deleterear(struct Node *first)
{
    struct Node *curr,*prev;
    if(first==NULL)
        {
            printf("\n list is empty");
            return(first);
        }
    else
        {
            for(prev=NULL,curr=first;curr->next=NULL;prev=curr,curr=curr->next);
            if(curr==first)
                first=NULL;
            else
                {
                    prev->next=NULL;
                    printf("\n deleted node is");
                    displaydata(curr);
                    free(curr);
                }
        }
}

//*****************************************DELETE BASED ON NAME**************************************/

struct Node *deleteonName(struct Node *first,char nm[])
{
int count=0;
struct Node *curr,*prev;
prev=NULL;
curr=first;
if(first==NULL)
    printf("\n list is empty");
else
    {
        while(curr!=NULL)
        {
            if(strcmp(nm,curr->name)==0)
            {
                printf("\n deleted node :");
                displaydata(curr);
                count++;
                if(curr==first)
                {
                    first=first->next;
                    free(curr);
                    curr=first;

                }
                else
                {
                    prev->next=curr->next;
                    free(curr);
                    curr=prev->next;

                }
            }
            else
                {
                    prev=curr;
                    curr=curr->next;
                }
        }
    }
    if(count==0)
        printf("\n Record with %s not found",nm);
    else
        printf("\n %d records with %s are deleted ",count,nm);
    return(first);
}
//***********************************SEARCHING NAME BASED ON ROLL NUMBER********************************/
struct Node *searchonRollno(struct Node *first,int rno)
{
    struct Node *curr;
    if(first==NULL)
        printf("List is empty");
    else
        {
            for(curr=first;curr->next!=first&&curr->rollno!=rno;curr=curr->next);
            if(curr==NULL)
                printf("\n Node with roll number %d is not found",rno);
            else
                printf("\n Node with roll number %d is found ",rno);
        }
        return(first);
}
//************************************************SORTING*******************************************/
struct Node *sortSLL(struct Node *first)
{
    struct Node *i,*j;
    int rno;
    char nm[20];
    for(i=first;i->next!=first;i=i->next)
    {
        for(j=first;j->next!=first;j=j->next)
        {
            if(j->rollno > j->next->rollno)
            {
                rno=j->rollno;
                strcpy(nm,j->name);

                j->rollno=j->next->rollno;
                strcpy(j->name,j->next->name);

                j->next->rollno=rno;
                strcpy(j->next->name ,nm);
            }
        }
    }
    return(first);
}
//******************************************DISPLAY ALL*************************************************/
void displayall(struct Node *first)
{
    struct Node *curr;
    if(curr==NULL)
        printf("\n list is empty");
    else
        for(curr=first;curr!=NULL;curr=curr->next)
        displaydata(curr);
}

//===============================================================================================================================================
int main()
{
    int ch,ch2,ch1,ch3;
    int pos;
    char nm[20];
    int N;
    struct Node *first=NULL;
    do
    {
    printf(" \n ENTER THE OPERATION TO PERFORM \n ");
    printf("   1] CREATE LIST \t 2]INSERTION \t 3] DELETION \t 4]SEARCHING \t 5]SORTING \t 6]DISPLAY ALL \t 7]EXIT \n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1: 
            
                printf("1] CREATE LIST RIGHT \t 2] CREATE LIST LEFT \n ");
                scanf("%d",&ch1);
                printf("Enter number of nodes");
                scanf("%d",&N);
                switch(ch1)
                {
                    case 1:
                      
                        printf("\n creating list at right \n ");
                        first=createlistRight(N);
                        break;
                    
                      
                    case 2:
                
                    printf("creating list at left \n ");
                    first=createlistleft(N);
                    break; 
                }      
                break;
   
    case 2: 
            
                printf("1]INSERT FRONT \t 2]INSERT REAR \t 3]INSERT AT ANY POSITION ");
                scanf("%d",&ch2);
                switch (ch2)
                {
                case 1:
                        printf("\n  Inserting front");
                        first= Insertfront(first);
                        break;
                
                case 2:
                    printf("\n Inserting rear");
                    first=Insertrear(first);
                    break;

                case 3:
                    printf("enter the position of insertion");
                    scanf("%d",&pos);
                    first=InsertatanyPosition(first, pos);
                    break;
                }
                break;

    case 3:
                
                printf("1] DELETE FRONT \t 2] DELETE REAR \t 3]DELETE BASED ON NAME \n");
                scanf("%d",&ch2);
                switch (ch2)
                {
                case 1:
                         printf("\n Deleting front");
                        first= deletefront(first);
                        break;
                
                case 2: 
                        printf("\n Deleting rear");
                        first=deleterear(first);
                        break;

                case 3:
                       
                        printf("\n enter the name to delete");
                        gets(nm);
                        first=deleteonName(first, nm);
                        break;

                case 4:
                        int rollno;
                        printf("enter a rollno to delete");
                        scanf("%d",&rollno);
                        first=deletedata(first,rollno);
                        displayall(first);
                        break;
                        
                }
                break;
    case 4:
                printf("\n SEARCHING NAME BASED ON ROLL NUMBER \n ");
                int rno;
                printf("enter the roll number to search for");
                scanf("%d",rno);
                first=searchonRollno(first,rno);
                break;

    case 5:
                printf("SORTING");
                sortSLL(first);
                break;

    case 6:  
                printf("\n Display all");
                displayall(first);
                break;
    case 7: 
                break;

    }
      
}while (ch!=7);
}
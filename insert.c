#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int roll;
    //char name[50];
   
    struct node* next;
}node;

node* create_node()
{ return malloc(sizeof(node));
}

void readInfo(node* p)
{ printf("Enter roll number: ");
scanf("%d",&p->roll);
 //printf("Enter name: ");
//scanf("%s",p->name);
}

void display(node* p)
{ printf("Roll Number: %d\n",p->roll);
//printf("Name: %s\n",p->name);
}

void displayAll(node* p)
{
    node* f=p;
    do
    {
     display(p);
    p=p->next;
    } while (p!=f);

}

node* createR()
{
    node* nw,*f,*l;
    int n,i;
    f=nw=l=NULL;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
 {
        
        nw=create_node();
        readInfo(nw);
        if(f==NULL)
        {
        f=nw;
        f->next=f;
        l=nw;
        }
        else{
        l->next=nw;
        l=nw;
        l->next=f;
        }
    }
   
    return f;
    }

node* insertrear(node* f, int rol)
{
node* curr=f;
node*nw;
node*prev;
node*temp;
int found=0;
if(f==NULL)
{
    printf("List is empty");
    return NULL;

}

for (prev=f;prev->next!=f;prev=prev->next);
    temp=prev;
do{
    if(curr->roll==rol)
    {
        found=1;
        break;
        }
        prev=temp=curr;
        curr=curr->next;    
} while(curr!=f)  ;

 if(found==0)
 {
    printf("roll no %d not found\n",rol);
    return f;
}

nw=create_node();
readInfo(nw);

nw->next=prev->next;
prev->next=nw;

if(temp==prev)
return nw;
else
return f;
}

node* deleteatAnyPosCLL(node* f,int pos)
{
node* curr=f;
node*nw;
node*prev;
node*last;
int i;

  if(f==NULL)
{
    printf("List is empty");
    return NULL;

}  
else{

    for (last=f;last->next!=f;last=last->next);
    for(curr=f,prev=NULL,i=1;curr->next!=f && i<pos;i++,prev=curr,curr=curr->next);
    printf("deleting node is:");
    display(curr);
    if(curr==curr->next)
    return NULL;

    if(pos==1 && curr!=curr->next)
    {
        f=f->next;
        last->next=f;
        free (curr);
        return f;
    }
    if( curr==last)
    { 
        prev->next=f;
        free(curr);
        return f;
}
else
{
    prev->next=curr->next;
    free(curr);
    return f;
}
}
}

int main()
{
    node *f=createR();
    int roll,pos;
    printf("Enter the position:");
    scanf("%d", &pos);
    f=deleteatAnyPosCLL(f, pos);
    displayAll(f);
    return 0;
}
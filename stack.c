#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 5


struct stack{
  int s[STACKSIZE];
  int top;
};
typedef struct stack stack;

int full(stack stk)
{
  return stk.top == STACKSIZE-1;
}

void push(stack *ps, int data)
{
  ps->top = ps->top+1;
  ps->s(ps->top) = data;
}

int empty(stack stk)
{
  return stk.top==-1;
}

int pop(stack *ps)
{
  int data;
  data=ps->s[ps->top--];
  return data;
}

void displaystack(stack stk)
{
  int i;
  printf("stack elements : \n ");
  for(i=stk.top ; i>=0; i--)
    printf("\t %d", stk.s[i]);
}

int main()
{
  stack stk;
  stk.top=-1;
  int choice,data,i;
  do{
    printf("\n 1)push \t 2)pop \t 3)Stack top \t 4)display \t 5)exit")
    scanf("%d",&choice);

  switch(choice)
{
  case 1 : if(full(stk))
              printf("stack overflow");
            else
              {
                printf("enter the data");
                scanf("%d",&data);
                push(&stk,data);
              }
              break;


  case 2 : if(empty(stk))
              printf("stack underflow");
            else
              {
                data=pop(&stk);
                printf("pop data :%d",data);
              }
              break;


  case 3 : if(empty(stk))
              printf("stack underflow");
            else
              {
                printf("top element : %d",stk.s[stk.top]);  
              }
              break;


    case 4 : if(empty(stk))
              printf("empty");
            else
              {
                displaystack(stk);
              }
              break;
    case 5: exit;
}
  }while(choice!=5);
return 0;
}
  
  


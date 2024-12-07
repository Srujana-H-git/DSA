struct Node
{
  int data;
  struct node *next;
};
typedef struct Node *node;
Node getnode()
{ return malloc(sizeof(struct node));
}

#include<stdio.h>
#include<stdlib.h>
int main(){

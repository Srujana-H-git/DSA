#include<stdio.h>
#include<stdlib.h>
void display(int );
int main()
{
    display(1);

}
void display(int i)
{
    printf("\n %d",i);
    if(i<=4)
    display(i+1);
}

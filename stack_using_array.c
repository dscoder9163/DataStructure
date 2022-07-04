#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
int isempty()
{
    if(top==-1)
        return 1;
    return 0;

}
int isfull()
{
    if(top==MAX-1)
        return 1;
    return 0;
}
void push(int data)
{
    if(isfull()){
        printf("Stack is Overflow!!\n");
        return;
    }
    stack[++top]=data;
    printf("%d ",top);
}
int pop()
{
    if(isempty())
    {
        printf("Stack is Underflow!!\n");
        return -1;
    }
    return stack[top--];
}
int peak()
{
    if(isempty())
    {
        printf("Stack Underflow!!\n");
        return -1;
    }     
    return stack[top];

}
void display()
{
    if(isempty())
    {
        printf("Stack is Empty!!\n");
        return;
    }
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d  ",stack[i]);
    }
    
}
int main()
{
    printf("\nHii welcome to my program\n\n");
    int choice,data;
    while(1)
    {
        printf("\nEnter press 0 for exit this program\n");
        printf("Enter prass 1 for push\n");
        printf("Enter prass 2 for pop\n");
        printf("Enter prass 3 for peak\n");
        printf("Enter prass 4 for display\n");
        lable:
        printf("Enter your choice what work you perform::");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                exit(0);
                break;
            case 1:
                printf("Enter the value::");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                printf("Poped data is::%d\n",pop());
                break;
            case 3:
                printf("Peak data is::%d\n",peak());
                break;
            case 4:
                printf("Display Stack data::\n\n");
                display();
                break;
            default:
                printf("wring choice!!\nPlease Enter the valid input\n");
                goto lable;

            
        }
    }
    return 0;
}
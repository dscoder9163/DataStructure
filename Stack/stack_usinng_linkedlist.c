#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top=NULL;
int size=0;
int max=5;
int isempty()
{
    if(top==NULL)
        return 1;
    return 0;
}

void push()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node*));
    if(size>=max||temp==NULL){
        printf("Stack Overflow");
        if(temp)
            free(temp);
        return;
    }
    printf("Enter the Data::");
    scanf("%d",&temp->data);
    temp->link=top;
    top=temp;
    size++;
}
int pop()
{
    struct node *temp=top;
    if(isempty())
    {
        printf("Staclk is Undeflow");
        return -1;
    }
    int x=top->data;
    top=top->link;
    free(temp);
    size--;
    return x;
    
}
int peek()
{
    if(isempty()){
        printf("Stack is Underflow!\nPeek Nnt posssible\n");
        return -1;
    }
    return top->data;    
}
void display()
{
    if(isempty())
    {
        printf("Stack is Empty!\nPrintf not possible!!\n");
        return;
    }
    struct node *temp=top;
    printf("Top-->");
    while(temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->link;
    }
    printf("NULL\n\n");
    
}
void delete_stack()
{
    struct node *temp;
    while(top!=NULL)
    {
        temp=top;
        top=top->link;
        free(temp);  
    }
}
int main()
{
   // struct node *top;
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
                delete_stack();
                exit(0);
                break;
            case 1:
                push();
                break;
            case 2:
                printf("Poped data is::%d\n",pop());
                break;
            case 3:
                printf("Peak data is::%d\n",peek());
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

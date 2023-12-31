#include<stdio.h>
#include<stdlib.h>


#define SIZE 13

void enQueue();
void deQueue();
void display();

char myCQ[SIZE]; 

int front = -1;
int rear = -1;

char element;

int main()
{
    int choice;
   
    while(1){
        printf("\n****** CIRCULAR Q MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:enQueue();
            break;
            case 2: deQueue();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default: printf("\nPlease select the correct choice!!!\n");
        }
    }
}
void enQueue()
{
    printf("\nEnter the value to be inserted:  ");
    scanf(" %c",&element);
    
    
    
   
    if((front == 0 && rear == SIZE - 1) || (front == rear+1))
    printf("\nSorry - Circular Queue is Full, therefore Insertion not possible!\n");
    
    else
    {

        if(rear == SIZE-1 && front != 0) 
        rear = -1;
        
        myCQ[++rear] = element;
        printf("\nInserted %c Successfully!\n", myCQ[rear]);
        
        if(front == -1)
        front = 0;
    }
    
    printf("\n **In enQueue exit** front %d rear %d", front, rear); 
}

void deQueue()
{
   
    
   
    if(front == -1 && rear == -1)
    printf("\nCircular Queue is Empty. Therefore deletion is not possible!\n");

    else
    {
        
        element = myCQ[front++];
        
        printf("\nDeleted element is : %c\n",element);
        
        if(front-1 == rear)
        front = rear = -1;
       
        
        if(front == SIZE )
            front = 0;
    }
    
    printf("\n **In deQueue exit** front %d rear %d", front, rear);
}

void display()
{
    if(front == -1)
    printf("\nCircular Queue is Empty!\n");
    else
    {
        int i;
        printf("\nCircular Queue Elements are : \n");
        if(front <= rear)
        {
            
            for (i=front; i <= rear; i++)
            printf("%c\t",myCQ[i]);
        }
       
        else
        {
           
            for (i = 0;i <= rear; i++) 
            printf("%c\t",myCQ[i]);
            
            for (i = front;i <= SIZE - 1; i++) 
            printf("%c\t", myCQ[i]);
            
        }
    }
}
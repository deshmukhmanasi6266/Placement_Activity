#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *front,*rear,*temp,*front1;
void enQueue(int val)
{
	if(rear==NULL)
	{
		rear=(struct node *)malloc(sizeof(struct node));
		rear->next=NULL;
		rear->data=val;
		front=rear;
	}
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		rear->next=temp;
		temp->data=val;
		temp->next=NULL;

		rear=temp;
	}
}
void deQueue()
{
	front1=front;
	if(front1==NULL)
	{
		printf("Queue Is Empty\n");
		return;
	}
	else
		if(front1->next!=NULL)
		{
			front1=front1->next;
			printf("Deleted Value : %d\n",front->data);
			free(front);
			front=front1;
		}
		else
		{
			printf("Deleted Value:%d",front->data);
			free(front);
			front=NULL;
			rear=NULL;
		}
}
int peek()
{
	if((front !=NULL)&&(rear!=NULL))
		printf("front of queue = %d", front->data);
	else
		return 0;
}
	


int main()
{
	int ch,n;
	do
	{
		printf("\n1.enQueue\n2.deQueue\n3.peek\n4.exit\n");
        	printf("enter your choice:");
        	scanf("%d",&ch);

		switch(ch)
		{
			case 1:printf("\nenter value:");
			       scanf("%d",&n);
			       enQueue(n);
			       break;
			case 2:deQueue();
			       break;
			case 3:peek();
			       break;
			case 4:exit(0);
			       break;
			default :printf("enter proper choice");
		}
	}while(ch!=5);
	return 0;
}

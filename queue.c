#include<stdio.h>
int queue[100],rear=-1,front=-1,size;
void enque(int val)
{
	if (rear==size-1)
	{
		printf("Queue is full\n");
		return;
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=val;
	}
	else
	{
		rear++;
		queue[rear]=val;
	}
}
int deque()
{
	int val;
	if(rear==-1 && front==-1)
	{
		printf("Queue is empty\n");
	}
	else if(front==rear)
	{
		val=queue[front];
		front=-1;
		rear=-1;
	}
	else
	{
		val=queue[front];
		front++;
	}
	return val;
}
void display()
{
	int i;
	if(rear==-1 && front==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
		printf("\n");
	}
}
int main()
{
	int ch,val;
	scanf("%d",&size);
	while(1)
	{
		printf("1.Enque 2.deque 3.dispaly 4.exit:");
		scanf("%d",&ch);
		if (ch==1)
		{
			//Enque operation
			scanf("%d",&val);
			enque(val);
		}
		else if(ch==2)
		{
			//deque operation
			val=deque();
			if(val==-1)
			{
				printf("Queue is Empty\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==3)
		{
			display();
		}
		else
		{
			break;
		}
	}
}

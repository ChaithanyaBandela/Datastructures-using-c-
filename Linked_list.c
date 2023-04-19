#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head=NULL,*tail=NULL,*temp,*NN,*res;

void display()
{
	if(head==NULL && tail==NULL)
	{
		printf("No Nodes\n");
	}
	else
	{
		temp=head;
		while(temp)
		{
			printf("%d %d %d\n ",temp,temp->data,temp->next);
			temp=temp->next;
		}
		printf("\n");
	}
}
void insert(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
	}
	else
	{
		tail->next=NN;
		tail=NN;
	}
}
NODE *delet()
{
	if(head==NULL && tail==NULL)
	{
		return NULL;
	}
	else if(head==tail)
	{
		res=head;
		head=NULL;
		tail=NULL;
		return res;
	}
	else
	{
		temp=head;
		while(temp->next->next)
		{
			temp=temp->next;
		}
		res=tail;
		temp->next=NULL;
		tail=temp;
		return res;
	}
}
int main()
{
	int ch,val;
	while(1)
	{
		printf("1.Insert\n 2.Delete\n 3.Display\n4.exit:");
		scanf("%d",&ch);
		if(ch==1)
		{
			//insert
			scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert(NN);
			
		}
		else if(ch==2)
		{
			res=delet();
		   	if(res==NULL)
		   	{
		   		printf("No nodes\n");
			}
			else
			{
			printf("%d\n",res->data);
			free(res);
			}
		}
		else if(ch==3)
		{
			//display
			display();
			
		}
		else
		{
			break;
		}
	}
}

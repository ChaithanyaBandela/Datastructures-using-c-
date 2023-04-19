#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node *prev;
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head=NULL,*tail=NULL,*temp,*res,*NN;
NODE * newnode(int val)
{
	NN=(NODE *)malloc(sizeof (NODE));
	NN->data=val;
	NN->prev=NULL;
	NN->next=NULL;
	return NN;
}
void insert_at_head(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
	}
	else
	{
		NN->next=head;
		head->prev=NN;
		head=NN;
	}
}
void display_from_head()
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
			printf("%d %d %d %d\n",temp,temp->prev,temp->data,temp->next);
			temp=temp->next;
		}
	}
}
void display_from_tail()
{
	if(head==NULL && tail==NULL)
	{
		printf("No Nodes\n");
	}
	else
	{
		temp=tail;
		while(temp)
		{
			printf("%d %d %d %d\n",temp,temp->prev,temp->data,temp->next);
			temp=temp->prev;
		}
	}
}
void insert_at_end(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
	}
	else
	{
		tail->next=NN;
		NN->prev=tail;
		tail=NN;
	}
}
void insert_by_pos(NODE *NN,int pos)
{
	int i;
	temp=head;
		for(i=1;i<pos-1;i++)
		{
			if(temp==NULL)
			{
				printf("Insertion is not possible\n");
				return ;
			}
			temp=temp->next;
		}
		NN->next=temp->next;
		NN->prev=temp;
		temp->next=NN;
		NN->next->prev=NN;
}
NODE * delete_at_head()
{
	if(head==NULL)
	{
		return NULL;
	}
	else if( )
	{
		
	}
	else
	{
		res=head;
		head=head->next;
		head->prev=NULL;
		res->next=NULL;
		return res;
	}
}
NODE *delete_at_end()
{
	if(head==NULL)
	{
		return NULL;
	}
	else if()
	{
		
	}
	else
	{
		res=tail;
		tail=tail->prev;
		tail->next=NULL;
		res->prev=NULL;
		return res;
	}
}
int main()
{
	int ch,val,pos;
	while(1)
	{
		printf("1.Insert at head\n2.Insert at end\n3.Insert by position\n4.Display from head to tail\n5.Display from tail to head\n6.Delete at head\n7.Delete at end\n8.Exit:\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			//insert at head
			scanf("%d",&val);
			NN=newnode(val);
			insert_at_head(NN);
		}
		else if(ch==2)
		{
			//insert at end
			scanf("%d",&val);
			NN=newnode(val);
			insert_at_end(NN);
		}
		else if(ch==3)
		{
			//insert by position
			scanf("%d",&val);
			scanf("%d",&pos);
			NN=newnode(val);
			insert_by_pos(NN,pos);
		}
		else if(ch==4)
		{
			//display form head to tail
			display_from_head();
		}
		else if(ch==5)
		{
			//display from tail to head
			display_from_tail();
		}
		else if(ch==6)
		{
			//delete at head
			res=delete_at_head();
			if(res==NULL)
			{
				printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}
		}
		else if(ch==7)
		{
			//delete at end
			res=delete_at_end();
			if(res==NULL)
			{
				printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}
		}
		else
		{
			break;
		}
	}
}

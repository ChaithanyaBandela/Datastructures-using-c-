//Polynomial representation using linked list
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int co,pow;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head=NULL,*temp,*tail=NULL,*NN;
NODE *head2=NULL,*tail2=NULL;
NODE *newnode(int co,int pow)
{
	NN=(NODE *)malloc(sizeof(NODE));
	NN->co=co;
	NN->pow=pow;
	NN->next=NULL;
	return NN;
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
void insert1(NODE *NN)
{
	if(head2==NULL && tail2==NULL)
	{
		head2=NN;
		tail2=NN;
	}
	else
	{
		tail2->next=NN;
		tail2=NN;
	}
}
void display(NODE *head)
{
	temp=head;
	if(temp==NULL)
	{
		printf("No Nodes\n");
	}
	else
	{
		while(temp)
		{
			printf("%dx%d\t",temp->co,temp->pow);
			temp=temp->next;
		}
	}
}
int main()
{
	int co,pow;
	char ch='a';
	while(ch!='N')
	{
		scanf("%d%d",&co,&pow);
		NN=newnode(co,pow);
		insert(NN);
		printf("Do you want enter Y/N:");
		scanf(" %c",&ch);
	}
	display(head);
	ch='a';
	while(ch!='N')
	{
		scanf("%d%d",&co,&pow);
		NN=newnode(co,pow);
		insert1(NN);
		printf("Do you want enter Y/N:");
		scanf(" %c",&ch);
	}
	display(head2);
}

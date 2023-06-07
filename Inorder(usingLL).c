#include<stdio.h>
#include<stdlib.h>
struct NodeLL{
	int data;
	struct NodeLL *next;
};
typedef struct NodeLL NODELL;
NODELL *head=NULL,*temp,*NNLL;
struct NodeT{
	struct NodeT *left;
	int data;
	struct NodeT *right;
};
typedef struct NodeT NODETREE;
NODETREE *root=NULL,*NNT,*queue[100];

NODELL *newnodeLL(int val)
{
	NNLL=(NODELL *)malloc(sizeof(NODELL));
	NNLL->data=val;
	NNLL->next=NULL;
	return NNLL;
}
void createLL(int val)
{
	NNLL=newnodeLL(val);
	if(head==NULL)
	{
		head=NNLL;
	}
	else
	{
		temp=head;
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=NNLL;
	}
}
void displayLL()
{
	temp=head;
	while(temp)
	{
		printf("%d %d %d\n",temp,temp->data,temp->next);
		temp=temp->next;
	}
}
NODETREE *newnodeTree(int val)
{
	NNT=(NODETREE *)malloc(sizeof(NODETREE));
	NNT->data=val;
	NNT->right=NULL;
	NNT->left=NULL;
	return NNT;
}
NODETREE *constructTree(NODELL *head)
{
	int f=0,r=0;
	temp=head;
	NNT=newnodeTree(temp->data);
	queue[r]=NNT;
	while(1)
	{
		if(temp->next)
		{
			NNT=newnodeTree(temp->next->data);
			queue[++r]=NNT;
			queue[f]->left=NNT;
			temp=temp->next;
		}
		else
		{
			return queue[0];
		}
		if(temp->next)
		{
		    NNT=newnodeTree(temp->next->data);
			queue[++r]=NNT;
			queue[f]->right=NNT;
			temp=temp->next;
			
		}
		else
		{
			return queue[0];
		}
		f++;
	}
}
void inorder(NODETREE *root)
{
	if(!root)
	{
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
int main()
{
	int n,val,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		createLL(val);
	}
	//displayLL();
	root=constructTree(head);
	inorder(root);
}

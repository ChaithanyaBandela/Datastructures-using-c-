#include<stdio.h>
void insertionsort(int *a,int n)
{
	int temp,i,j;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j<n;j--)
			{
				if(a[j]<temp)
				{
					a[j+1]=temp;
					break;
				}
				else if(j==-1)
				{
					a[0]=temp;
				}
				else
				{
					a[j+1]=a[j];
				    a[j]=temp;
				}
			}
	}
}
int main()
{
	int i,n,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertionsort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

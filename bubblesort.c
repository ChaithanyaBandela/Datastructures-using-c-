#include<stdio.h>
void bubblesort(int *a,int n)
{
	int i,j,temp,swap;
	for(i=1;i<=n;i++)
	{
		swap=0;
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swap++;
			}
		}
		if(swap==0)
		{
			break;
		}
	}
}
int main()
{
	int a[100],i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubblesort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

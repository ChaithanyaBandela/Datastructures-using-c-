#include<stdio.h>
void selectionsort(int *a,int n)
{
	int i,j,max,maxind,temp;
	for(i=0;i<n-1;i++)
	{
		max=a[0];
		maxind=0;
		for(j=0;j<n-i;j++)
		{
			if(a[j]>max)
			{
				max=a[j];
				maxind=j;
			}
		}
		temp=a[maxind];
		a[maxind]=a[j-1];
		a[j-1]=temp;
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
	selectionsort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

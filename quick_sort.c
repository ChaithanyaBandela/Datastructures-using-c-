//quicksort
#include<stdio.h>
int partition(int *a,int L,int H)
{
	int i,j,p,temp;
	i=L,j=L,p=H;
	for(i=L,j=L;i<p;i++)
	{
		if(a[i]<a[p])
		{
			temp=a[i];
			a[j]=a[i];
			a[j]=temp;
			j++;
		}
	}
	temp=a[j];
	a[j]=a[p];
	a[p]=temp;
	return j;
}
void quick_sort(int *a,int L,int H)
{
	if(L<H)
	{
		int par;
		par=partition(a,L,H);
		quick_sort(a,L,par-1);
		quick_sort(a,par+1,H);
	}
}
int main()
{
	int a[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

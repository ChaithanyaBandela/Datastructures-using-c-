#include<stdio.h>
void merge2(int *a,int L,int H,int M)
{
	int i,j,k=0,res[H-L+1];
	i=L;
	j=M+1;
     while(i<=M && j<=H)
	{
			if(a[i]>a[j])
			{
				res[k]=a[j];
				k++;
				j++;
			}
			else
			{
				res[k]=a[i];
				k++;
				i++;
			}
		}
			while(i<=M)
			{
			res[k]=a[i];
			i++;
			k++;
		}
		while(j<=H)
		{
			res[k]=a[j];
			j++;
			k++;
		}
	for(k=0,i=L;i<=H;i++,k++)
	{
		a[i]=res[k];
	}
}
void merge_sort(int *a,int n)
{
	int i,L,H,M,p;
	for(p=2;p<=n;p=p*2)
	{
		for(i=0;i+p<=n;i=i+p)
		{
			L=i;
			H=p+i-1;
			M=(L+H)/2;
			merge2(a,L,H,M);
		}
	}
	if(p/2<n && n%2==0)
	{
		M=p/2-1;
		L=0;
		H=n-1;
		merge2(a,L,H,M);
	}
	else
	{
		M=n-2;
		L=p/2;
		H=n-1;
		merge2(a,L,H,M);
		merge2(a,0,n-1,p/2-1);
	}
}
int main()
{
	int i,a[100],n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	merge_sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	
}

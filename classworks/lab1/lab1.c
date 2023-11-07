#include<stdio.h>

void oddPosition(int *a,int n)
{
	int i;
	printf("Odd Positioned Elements are ");
	for(i=0;i<n;i+=2)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void evenNumbers(int *a,int n)
{
	int i;
	printf("Even Numbers from the Set of Integers :");
	for(i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			printf("%d ",a[i]);
		}
	}
}

void maximumNumber(int *a,int n)
{
	int i,max=a[0];
	printf("\nMaximum Number from the Set of Integers :");
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	printf("%d ",max);
}

void sumAndavg(int *a,int n)
{

	int i,sum=0;
	float avg=0;
	for(i=0;i<n;i++)
	{
		sum+=a[i];
	}	
		avg=(float)sum/n;
		printf("\nSum of %d numbers is %d .",n,sum);
		printf("\nAverage of %d numbers is %f .",n,avg);
}

int main()
{
	int i, n,a[50];
	printf("Enter the Number of Elements :");
	scanf("%d",&n);
	printf("Enter the Elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Entered elements : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	
	printf("\n");
	
	oddPosition(a,n);
	evenNumbers(a,n);
	maximumNumber(a,n);
	sumAndavg(a,n);
}

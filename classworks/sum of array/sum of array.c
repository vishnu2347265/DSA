#include<stdio.h>
void main()
{
	int n, i,a[50],sum=0;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("\nEnter the elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEntered Elements are ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
		sum=sum+a[i];
	}
	printf("\nSum of the array elements is %d",sum);
}

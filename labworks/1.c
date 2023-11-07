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
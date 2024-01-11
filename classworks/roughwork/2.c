#include<stdio.h>
int main()
{
    int num[5]={1,2,3,4,5};
    printf("elements are");
    for(int i=0;i<5;i++)
    {
        printf("%d\t%d\n",i,num[i]);
    }
}
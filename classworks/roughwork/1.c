#include<stdio.h>
int main()
{
    int num[5][2]={{1,2},{2,3},{3,4},{3,5},{4,6}};
    printf("elements are");
    for(int i=0;i<5;i++){
    for(int j=0;j<2;j++)
    {
        printf("%d",num[i][j]);
    }
    printf("\n");
    }
    
}
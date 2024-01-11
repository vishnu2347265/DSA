#include<stdio.h>
int main()
{
    char charArray[3][4]={
        {'a','b','c','d'},
        {'a','b','c','d'},
        {'a','b','c','d'},
        };
    for (int i = 0; i < 3; i++){
    for (int j = 0; j < 4; j++)
    {
        printf("%c",charArray[i][j]);
    }
    printf("\n");
    }
    
}

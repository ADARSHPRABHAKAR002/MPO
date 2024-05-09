#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL));
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%d ",rand()%10);
        }
        printf("\n");
    } 
   
    return 0;

}
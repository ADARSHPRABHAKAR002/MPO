#include<stdio.h>
#include<stdlib.h>

int main()
{
    int row,col;
    printf("Enter the number of rows and columns of a matrix: ");
    scanf("%d%d",&row,&col);
    
    int *arr=(int *)malloc(sizeof(int)*row*col);

     for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&arr[i*col+j]);
           
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d",arr[i*col+j]);
           
        }
    }

    free(arr);

}
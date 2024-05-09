#include<stdio.h>
int search(int *a,int,int,int);

int main()
{
    int row,col,key;
    printf("Enter the number of rows and columns of a matrix: ");
    scanf("%d%d",&row,&col);
    int arr[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("Enter the key element to search: ");
    scanf("%d",&key);
   
    if(search((int *)arr,row,col,key)==0)
    {
        printf("The key %d element is found in the matrix",key);
    }
    if(search((int *)arr,row,col,key)==-1)
    {
        printf("The key %d element not found in the matrix",key);
    }
    return 0;
}

int search(int *arr,int row,int col,int key)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(key== *(arr + (row *i) + j))
            {
                return 0;
            }
        }
    }
    return -1;
}
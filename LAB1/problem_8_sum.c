#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    clock_t start,end;
    double Total_time;
    int n,small=INT_MAX,large=0,sum=0;
    start=clock();
     for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            n=generateRandomNumber(101, 201);
            printf("%d ",n);
            if(n>large)
            {
                large=n;
            }
            if(n<small)
            {
                small=n;    
            }
            sum=sum+n;

        }
        printf("\n");
    }
    end=clock();
    Total_time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Smallest number in the Matrix is :%d\n",small);
    printf("Largest number in the Matrix is :%d\n",large);
    printf("Sum of all elements in the Matrix is :%d\n",sum);
    printf("Total Time Taken: %f",Total_time);
    return 0;
}


#include<stdio.h>
#include<time.h>
void printhelloword(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("hello");
    }
}
int main()
{
    clock_t start,end;
    double Total_time;

    start=clock();
    printhelloword(10);
    end=clock();
    Total_time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Execution time for 10 iterations: %f",Total_time);


    start=clock();
    printhelloword(1000);
    end=clock();
    Total_time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Execution time for 1000 iterations: %f",Total_time);

}


clock_t start,end;
start=clock();
//function

end=clock();
total_time=((double)(end-start))/CLOCKS_PER_SEC;
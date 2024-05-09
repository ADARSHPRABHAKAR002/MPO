#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    // RAND_MAX -> highest number 32767 (marco).
    int random_number = rand();
    printf("random number generated : %d",random_number);
    return 0;
}

/*#include<time.h>
int main()
{
    srand(time(NULL));
    int random=rand();
    printf("%d",random);
}*/
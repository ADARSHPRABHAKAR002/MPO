#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    time_t time_s;
    time(&time_s);
    char * time_string= ctime(&time_s);
    printf("current time: %s",time_string);
    return 0;
}

/*time_t timee;
time(timee);
char *str=ctime(&timee);*/
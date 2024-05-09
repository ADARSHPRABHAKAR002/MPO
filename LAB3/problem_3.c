/*** 3. thread_id of each thread ***/
#include <stdio.h>
#include <omp.h>
int main() {
// start of OpenMP parallel region
#pragma omp parallel
{
printf("My thread id is %d\n", omp_get_thread_num());
}
// OpenMP parallel region ends here
printf("\nI'm the master thread!\n");
return 0;
}

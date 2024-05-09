/*1. Hello from each thread */
#include <stdio.h>
#include <omp.h>
int main() {
// start of OpenMP parallel region
 #pragma omp parallel
 {
 printf("Hello from thread %d\n",
omp_get_thread_num());
 }
// OpenMP parallel region ends here
 printf("\nI'm the master thread!\n");
 return 0;
}

/***2. determine the total threads in the parallel region
***/
#include <stdio.h>
#include <omp.h>
int main() {
// start of OpenMP parallel region
 #pragma omp parallel
 {
 printf("Total threads executing the the parallel region = %d\n", omp_get_num_threads());
 }
// OpenMP parallel region ends here
 printf("\nI'm the master thread!\n");
 return 0;
}

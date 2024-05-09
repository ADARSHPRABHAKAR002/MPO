/*
7. Create a parallel block. Compute the sum of numbers from zero to thread_id, and output 
the sum to the screen. Run your code and observe the result.
*/
#include <stdio.h>
#include <omp.h>
int main() {
 #pragma omp parallel
 {
 // Get the thread ID
 int tid = omp_get_thread_num();
 int sum = 0;
 // Compute the sum of numbers from zero to thread_id
 for (int i = 0; i <= tid; i++) {
 sum += i;
 }
 // Output the sum to the screen
 #pragma omp critical
 {
 printf("Thread %d: Sum from 0 to %d is %d\n", tid, tid, sum);
 }
 }
 return 0;
}

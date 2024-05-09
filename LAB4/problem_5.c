/*
Implement a program to generate the Fibonacci series in parallel using OpenMP. Use shared 
variables for the result array and private variables for each thread's local variables.
*/
#include <stdio.h>
#include <omp.h>
#define N 10 // Number of Fibonacci numbers to generate
int main() {
 int fib[N];
 fib[0] = 0;
 fib[1] = 1;
 // Parallel region to generate the Fibonacci series
 #pragma omp parallel
 {
 int a = 0, b = 1;
 int temp;
 // Only one thread needs to compute the Fibonacci series
 #pragma omp single
 {
 for (int i = 2; i < N; i++) {
 temp = a + b;
 a = b;
 b = temp;
 fib[i] = temp;
 }
 }
 }
 // Print the Fibonacci series
 printf("Fibonacci series:\n");
 for (int i = 0; i < N; i++) {
 printf("%d ", fib[i]);
 }
 printf("\n");
 return 0;
}

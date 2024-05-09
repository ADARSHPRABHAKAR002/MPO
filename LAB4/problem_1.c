/*
Illustrate loop parallelism with the for loop by writing a program to calculate the sum of an 
array in parallel using OpenMP. (Use a shared variable for the result and private variables 
for loop indices).
*/
#include <stdio.h>
#include <omp.h>
#define ARRAY_SIZE 10
int main() {
 int array[ARRAY_SIZE];
 int sum = 0,i;
 // Initialize the array with values
 for (int i = 0; i < ARRAY_SIZE; i++) {
 array[i] = i + 1;
 }
 // Parallel region to calculate the sum of the array
 #pragma omp parallel for private(i) reduction(+:sum)
 for (int i = 0; i < ARRAY_SIZE; i++) {
 sum += array[i];
 }
 printf("The sum of the array elements is: %d\n", sum);
 return 0;
}

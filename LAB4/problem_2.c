/*
Implement a program to calculate the square of each element in an array in parallel using 
OpenMP. Use shared variables for the input array and private variables for the parallel
for loop indices.
*/
#include <stdio.h>
#include <omp.h>
#define ARRAY_SIZE 10
int main() {
 int array[ARRAY_SIZE];
 int squares[ARRAY_SIZE];
 int i;
 // Initialize the array with values
 for (int i = 0; i < ARRAY_SIZE; i++) {
 array[i] = i + 1;
 }
 // Parallel region to calculate the square of each element in the array
 #pragma omp parallel for private(i)
 for (int i = 0; i < ARRAY_SIZE; i++) {
 squares[i] = array[i] * array[i];
 }
 // Print the squares
 printf("Square of each element in the array:\n");
 for (int i = 0; i < ARRAY_SIZE; i++) {
 printf("%d ", squares[i]);
 }
 printf("\n");
 return 0;
}

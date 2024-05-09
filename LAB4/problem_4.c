/*
Write a program to find the minimum element in an array in parallel using OpenMP. Use 
shared variables for the array and the minimum value, and private variables for loop indices.
*/
#include <stdio.h>
#include <omp.h>
#define ARRAY_SIZE 1000
int main() {
 int array[ARRAY_SIZE], i;
 int min_value = __INT_MAX__; // Initialize min_value to maximum possible value
 // Initialize the array with values
 for (int i = 0; i < ARRAY_SIZE; i++) {
 array[i] = i + 1;
 }
 // Parallel region to find the minimum element in the array
 #pragma omp parallel for private(i) shared(min_value)
 for (int i = 0; i < ARRAY_SIZE; i++) {
 if (array[i] < min_value) {
 #pragma omp critical
 {
 if (array[i] < min_value) {
 min_value = array[i];
 }
 }
 }
 }
 printf("Minimum element in the array: %d\n", min_value);
 return 0;
}

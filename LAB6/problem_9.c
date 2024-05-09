/*
Write a multithreaded program to compute the sum of two n*n square order matrices.
Let the intilization of the matrix be done with in the parallel region, just by only one thread
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_SIZE 10
int matrix1[MAX_SIZE][MAX_SIZE];
int matrix2[MAX_SIZE][MAX_SIZE];
int result[MAX_SIZE][MAX_SIZE];
int n; // Size of the matrices
void *compute_sum(void *args) {
 int start_row = *((int *)args);
 for (int i = start_row; i < start_row + n; i++) {
 for (int j = 0; j < n; j++) {
 result[i][j] = matrix1[i][j] + matrix2[i][j];
 }
 }
 pthread_exit(NULL);
}
int main() {
 printf("Enter the size of the square matrices: ");
 scanf("%d", &n);
 // Initialize matrix1 and matrix2 with random values
 srand(time(NULL)); // Seed for random number generation
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 matrix1[i][j] = rand() % 10; // Generating random numbers between 0 and 9
 matrix2[i][j] = rand() % 10;
 }
 }
 // Create threads to compute the sum of matrices
 pthread_t threads[MAX_SIZE];
 int thread_args[MAX_SIZE];
 for (int i = 0; i < n; i++) {
 thread_args[i] = i;
 pthread_create(&threads[i], NULL, compute_sum, &thread_args[i]);
 }
 // Join threads
 for (int i = 0; i < n; i++) {
 pthread_join(threads[i], NULL);
 }
 // Displaying the matrices
 printf("Matrix 1:\n");
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 printf("%d ", matrix1[i][j]);
 }
 printf("\n");
 }
 printf("Matrix 2:\n");
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 printf("%d ", matrix2[i][j]);
 }
 printf("\n");
 }
 // Displaying the sum matrix
 printf("Sum Matrix:\n");
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 printf("%d ", result[i][j]);
 }
 printf("\n");
 }
 return 0;
}
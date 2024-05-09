/*
Write a mulithreaded program to multiply every element in a matrix with a constant number.
The numbers in even rows should be multiplied by even numbered threads, and the number 
in odd rows should be multiplied by odd numbered threads. Print the thread number after 
each multiplication.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_SIZE 100
int matrix[MAX_SIZE][MAX_SIZE];
int result[MAX_SIZE][MAX_SIZE];
int n, constant;
void *multiply_matrix(void *arg) {
 int tid = *((int *)arg);
 // Determine if the current thread is even or odd
 int is_even_thread = tid % 2 == 0;
 // Iterate through rows assigned to this thread
 for (int i = is_even_thread ? 0 : 1; i < n; i += 2) {
 // Multiply elements in the row by the constant
 for (int j = 0; j < n; j++) {
 result[i][j] = matrix[i][j] * constant;
 printf("Thread %d: Multiplying matrix[%d][%d] = %d by constant %d\n", tid, i, j, matrix[i]
[j], constant);
 }
 }
 return NULL;
}
int main() {
 // Input the size of the square matrix and the constant number from the user
 printf("Enter the size of the square matrix: ");
 scanf("%d", &n);
 printf("Enter the constant number to multiply with: ");
 scanf("%d", &constant);
 // Input matrix elements
 printf("Enter the elements of the square matrix:\n");
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 scanf("%d", &matrix[i][j]);
 }
 }
 // Create threads equal to the number of rows
 pthread_t threads[n];
 int thread_ids[n];
 for (int i = 0; i < n; i++) {
 thread_ids[i] = i;
 pthread_create(&threads[i], NULL, multiply_matrix, (void *)&thread_ids[i]);
 }
 // Wait for all threads to finish
 for (int i = 0; i < n; i++) {
 pthread_join(threads[i], NULL);
 }
 // Print the resulting matrix after multiplication
 printf("Resulting matrix after multiplication:\n");
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 printf("%d ", result[i][j]);
 }
 printf("\n");
 }
 return 0;
}
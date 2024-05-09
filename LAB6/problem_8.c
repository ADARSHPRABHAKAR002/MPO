/*
Write a multithreaded program to compute the sum of all the elements in a matrix. Let each 
thread should determine the partial sum of a column. Let the number of threads working 
together be equal to the number of columns.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_ROWS 100
#define MAX_COLS 100
int matrix[MAX_ROWS][MAX_COLS];
int row_count, col_count;
int total_sum = 0;
void *compute_column_sum(void *arg) {
 int col_index = *((int *)arg);
 int local_sum = 0;
 // Compute the sum of the column assigned to this thread
 for (int i = 0; i < row_count; i++) {
 local_sum += matrix[i][col_index];
 }
 // Add the local sum to the total sum
 __sync_fetch_and_add(&total_sum, local_sum);
 return NULL;
}
int main() {
 // Input the size of the matrix from the user
 printf("Enter the number of rows in the matrix: ");
 scanf("%d", &row_count);
 printf("Enter the number of columns in the matrix: ");
 scanf("%d", &col_count);
 // Input matrix elements
 printf("Enter the elements of the matrix:\n");
 for (int i = 0; i < row_count; i++) {
 for (int j = 0; j < col_count; j++) {
 scanf("%d", &matrix[i][j]);
 }
 }
 // Create threads equal to the number of columns
 pthread_t threads[col_count];
 int thread_ids[col_count];
 for (int i = 0; i < col_count; i++) {
 thread_ids[i] = i;
 pthread_create(&threads[i], NULL, compute_column_sum, (void *)&thread_ids[i]);
 }
 // Wait for all threads to finish
 for (int i = 0; i < col_count; i++) {
 pthread_join(threads[i], NULL);
 }
 // Print the total sum
 printf("Total sum of all elements in the matrix: %d\n", total_sum);
 return 0;
}

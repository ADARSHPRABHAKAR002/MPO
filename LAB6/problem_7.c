/*
Write a multithreaded program that will find the repetition of a number within a n*n order 
square matrix. (Let the intilization of the matrix be done within the parallel region by just 
one thread.Let the number to be searched be input by the user before entering the parallel 
region).
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_SIZE 100
int matrix[MAX_SIZE][MAX_SIZE];
int n;
int target;
int repetition_count = 0;
void *search_repetition(void *arg) {
 int tid = *((int *)arg);
 // Each thread searches its portion of the matrix for repetitions of the target number
 for (int i = tid; i < n; i += n) {
 for (int j = 0; j < n; j++) {
 if (matrix[i][j] == target) {
 repetition_count++;
 }
 }
 }
 return NULL;
}
int main() {
 // Input the size of the square matrix and the target number from the user
 printf("Enter the size of the square matrix: ");
 scanf("%d", &n);
 printf("Enter the number to search for: ");
 scanf("%d", &target);
 // Input matrix elements
 printf("Enter the elements of the square matrix:\n");
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 scanf("%d", &matrix[i][j]);
 }
 }
 // Number of threads to use is equal to the user input for now
 int pthread_num_threads = n;
 // Create threads
 pthread_t threads[pthread_num_threads];
 int thread_ids[pthread_num_threads];
 for (int i = 0; i < pthread_num_threads; i++) {
 thread_ids[i] = i;
 pthread_create(&threads[i], NULL, search_repetition, (void *)&thread_ids[i]);
 }
 // Wait for all threads to finish
 for (int i = 0; i < pthread_num_threads; i++) {
 pthread_join(threads[i], NULL);
 }
 // Print the repetition count
 printf("The repetition count of the number %d in the matrix is: %d\n", target, repetition_count);
 return 0;
}

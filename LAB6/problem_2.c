/*
Write a multithreaded program to add two arrays.
Create “4” threads and print the thread number with each computation that is done.
*/
#include <stdio.h>
#include <pthread.h>
#define ARRAY_SIZE 10
#define NUM_THREADS 4
int array1[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int array2[ARRAY_SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int result[ARRAY_SIZE];
void *add_arrays(void *thread_id) {
 int tid = *((int *)thread_id);
 int start = tid * (ARRAY_SIZE / NUM_THREADS);
 int end = start + (ARRAY_SIZE / NUM_THREADS);
 
 for (int i = start; i < end; i++) {
 result[i] = array1[i] + array2[i];
 printf("Thread %d: Result at index %d = %d\n", tid, i, result[i]);
 }
 
 return NULL;
}
int main() {
 pthread_t threads[NUM_THREADS];
 int thread_ids[NUM_THREADS];
 
 for (int i = 0; i < NUM_THREADS; i++) {
 thread_ids[i] = i;
 pthread_create(&threads[i], NULL, add_arrays, (void *)&thread_ids[i]);
 }
 
 for (int i = 0; i < NUM_THREADS; i++) {
 pthread_join(threads[i], NULL);
 }
 
 return 0;
}
/*
Write a multithreaded program to multiply every element in an array by a constant number.
Create “4” threads and print the thread number too with the results.
*/
#include <stdio.h>
#include <pthread.h>
#define ARRAY_SIZE 10
#define NUM_THREADS 4
#define CONSTANT 2
int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
void *multiply(void *thread_id) {
 int tid = *((int *)thread_id);
 int start = tid * (ARRAY_SIZE / NUM_THREADS);
 int end = start + (ARRAY_SIZE / NUM_THREADS);
 
 for (int i = start; i < end; i++) {
 array[i] *= CONSTANT;
 printf("Thread %d: Result at index %d = %d\n", tid, i, array[i]);
 }
 
 return NULL;
}
int main() {
 pthread_t threads[NUM_THREADS];
 int thread_ids[NUM_THREADS];
 
 for (int i = 0; i < NUM_THREADS; i++) {
 thread_ids[i] = i;
 pthread_create(&threads[i], NULL, multiply, (void *)&thread_ids[i]);
 }
 
 for (int i = 0; i < NUM_THREADS; i++) {
 pthread_join(threads[i], NULL);
 }
 
 return 0;
}

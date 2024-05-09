/*
Write a multithreaded program to multiply every element in the array by a constant. The 
even numbered threads should multiply the elements in the even indices of the array and the 
odd numbered threads should multiply the elements present in the odd indices of the array. 
(Assume 0 to be the starting even index).
*/
#include <stdio.h>
#include <pthread.h>
#define ARRAY_SIZE 10
#define CONSTANT 2
#define NUM_THREADS 2
int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
void *multiply_array(void *thread_id) {
 int tid = *((int *)thread_id);
 int start, end;
 if (tid % 2 == 0) { // Even numbered thread
 start = 0;
 end = ARRAY_SIZE;
 } else { // Odd numbered thread
 start = 1;
 end = ARRAY_SIZE;
 }
 
 for (int i = start; i < end; i += 2) {
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
 pthread_create(&threads[i], NULL, multiply_array, (void *)&thread_ids[i]);
 }
 
 for (int i = 0; i < NUM_THREADS; i++) {
 pthread_join(threads[i], NULL);
 }
 
 return 0;
}

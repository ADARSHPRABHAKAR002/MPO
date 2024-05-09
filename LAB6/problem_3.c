/*
Create two functions, one to add two arrays and one to multiply two arrays. Write a program 
that will call these two functions in two separate threads. Also display their thread ids
*/
#include <stdio.h>
#include <pthread.h>
#define ARRAY_SIZE 5
int array1[ARRAY_SIZE] = {1, 2, 3, 4, 5};
int array2[ARRAY_SIZE] = {6, 7, 8, 9, 10};
int result_add[ARRAY_SIZE];
int result_multiply[ARRAY_SIZE];
void *add_arrays(void *thread_id) {
 int tid = *((int *)thread_id);
 
 for (int i = 0; i < ARRAY_SIZE; i++) {
 result_add[i] = array1[i] + array2[i];
 printf("Thread %d (Addition): Result at index %d = %d\n", tid, i, result_add[i]);
 }
 
 return NULL;
}
void *multiply_arrays(void *thread_id) {
 int tid = *((int *)thread_id);
 
 for (int i = 0; i < ARRAY_SIZE; i++) {
 result_multiply[i] = array1[i] * array2[i];
 printf("Thread %d (Multiplication): Result at index %d = %d\n", tid, i, result_multiply[i]);
 }
 
 return NULL;
}
int main() {
 pthread_t thread_add, thread_multiply;
 int thread_id_add = 1;
 int thread_id_multiply = 2;
 
 // Create thread for array addition
 pthread_create(&thread_add, NULL, add_arrays, (void *)&thread_id_add);
 
 // Create thread for array multiplication
 pthread_create(&thread_multiply, NULL, multiply_arrays, (void *)&thread_id_multiply);
 
 // Wait for both threads to finish
 pthread_join(thread_add, NULL);
 pthread_join(thread_multiply, NULL);
 
 return 0;
}

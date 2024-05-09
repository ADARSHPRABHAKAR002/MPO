/*
Write a multithreaded program that will compare two arrays, and print all the common 
elements and their count.
*/
#include <stdio.h>
#include <pthread.h>
#define ARRAY_SIZE 10
int array1[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int array2[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//int array2[ARRAY_SIZE] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
int common_elements[ARRAY_SIZE];
int count = 0;
void *compare_arrays(void *arg) {
 int tid = *((int *)arg);
 
 for (int i = 0; i < ARRAY_SIZE; i++) {
 if (array1[i] == array2[i]) {
 common_elements[count++] = array1[i];
 }
 }
 
 return NULL;
}
int main() {
 pthread_t thread;
 int thread_id = 1;
 
 pthread_create(&thread, NULL, compare_arrays, (void *)&thread_id);
 pthread_join(thread, NULL);
 
 if (count == 0) {
 printf("No common elements found.\n");
 } else {
 printf("Common elements and their count:\n");
 for (int i = 0; i < count; i++) {
 printf("%d ", common_elements[i]);
 }
 printf("\nCount: %d\n", count);
 }
 
 return 0;
}

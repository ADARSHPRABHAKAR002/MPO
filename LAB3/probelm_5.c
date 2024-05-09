/*
5. Write C code for the following using omp library:
Modify the "omp4.c file" to print the thread id of the executing thread, with each disply 
message.
*/
#include <stdio.h>
#include <omp.h>
int main() {
 int count = 0; // Variable to count the number of times the message is displayed
 #pragma omp parallel
 {
 // Get the thread ID
 int tid = omp_get_thread_num();
 // Display welcome message along with thread ID
 #pragma omp critical
 {
 printf("Thread %d: Welcome to parallel programming with OpenMP!\n", tid);
 count++;
 }
 }
 //printf("The welcome message was displayed %d times.\n", count);
 return 0;
}

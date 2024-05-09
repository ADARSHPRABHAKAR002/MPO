/*
4. Write C code for the following using omp library:
1. Display a welcome message in a parallel bock and observe how many times it gets 
displayed.
*/
#include <stdio.h>
#include <omp.h>
int main() {
 int count = 0; // Variable to count the number of times the message is displayed
 #pragma omp parallel
 {
 // Display welcome message
 #pragma omp critical
 {
 printf("Welcome to parallel programming with OpenMP!\n");
 count++;
 }
 }
 printf("The welcome message was displayed %d times.\n", count);
 return 0;
}

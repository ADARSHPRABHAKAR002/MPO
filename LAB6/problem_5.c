/*
Write a multithreaded program that will take two numbers as input from the user, num1 and 
num2. The program should list out all the numbers between 0 and num2 which are divisble by
num1. (parallelise the for loop)
*/
#include <stdio.h>
#include <omp.h>
int main() {
 int num1, num2;
 // Input num1 and num2 from the user
 printf("Enter num1: ");
 scanf("%d", &num1);
 printf("Enter num2: ");
 scanf("%d", &num2);
 // Parallel region to list out numbers divisible by num1
 #pragma omp parallel
 {
 #pragma omp for
 for (int i = 0; i <= num2; i++) {
 if (i % num1 == 0) {
 printf("%d ", i);
 }
 }
 }
 printf("\n");
 return 0;
}
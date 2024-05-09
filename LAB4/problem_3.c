/*
Create a parallel program to calculate the factorial of a number using OpenMP. Use a shared 
variable for the result, and private variables for loop indices.
*/
#include <stdio.h>
#include <omp.h>
int main() {
 int number = 10,i; // Number for which factorial will be calculated
 unsigned long long factorial = 1; // Result variable, initialized to 1
 // Parallel region to calculate the factorial
 #pragma omp parallel for private(i) reduction(*:factorial)
 for (int i = 1; i <= number; i++) {
 factorial *= i;
 }
 printf("Factorial of %d is %llu\n", number, factorial);
 return 0;
}

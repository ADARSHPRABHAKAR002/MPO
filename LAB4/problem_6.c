/*
Write a program to transpose a matrix in parallel using OpenMP. Use shared variables for 
the input and output matrices and private variables for loop indices.
*/
#include <stdio.h>
#include <omp.h>
#define ROWS 3
#define COLS 3
int main() {
 int matrix[ROWS][COLS] = {
 {1, 2, 3},
 {4, 5, 6},
 {7, 8, 9}
 };
 int transposed[COLS][ROWS];
 // Parallel region to transpose the matrix
 #pragma omp parallel for collapse(2)
 for (int i = 0; i < COLS; i++) {
 for (int j = 0; j < ROWS; j++) {
 transposed[i][j] = matrix[j][i];
 }
 }
 // Print the original matrix
 printf("Original Matrix:\n");
 for (int i = 0; i < ROWS; i++) {
 for (int j = 0; j < COLS; j++) {
 printf("%d ", matrix[i][j]);
 }
 printf("\n");
 }
 // Print the transposed matrix
 printf("\nTransposed Matrix:\n");
 for (int i = 0; i < COLS; i++) {
 for (int j = 0; j < ROWS; j++) {
 printf("%d ", transposed[i][j]);
 }
 printf("\n");
 }
 return 0;
}

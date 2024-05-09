/*
4. Implement a C function to find the transpose of a given matrix. The program should take a 
matrix as input, computeits transpose, and display the result.
*/
#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10
// Function to compute the transpose of a matrix
void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
 int transpose[MAX_COLS][MAX_ROWS];
 // Computing transpose
 for (int i = 0; i < cols; i++) {
 for (int j = 0; j < rows; j++) {
 transpose[i][j] = matrix[j][i];
 }
 }
 // Displaying the transpose
 printf("Transpose of the matrix:\n");
 for (int i = 0; i < cols; i++) {
 for (int j = 0; j < rows; j++) {
 printf("%d ", transpose[i][j]);
 }
 printf("\n");
 }
}
int main() {
 int matrix[MAX_ROWS][MAX_COLS];
 int rows, cols;
 // Input matrix dimensions
 printf("Enter the number of rows and columns of the matrix: ");
 scanf("%d %d", &rows, &cols);
 // Input matrix elements
 printf("Enter the elements of the %dx%d matrix:\n", rows, cols);
 for (int i = 0; i < rows; i++) {
 for (int j = 0; j < cols; j++) {
 scanf("%d", &matrix[i][j]);
 }
 }
 // Compute and display the transpose of the matrix
 transposeMatrix(matrix, rows, cols);
 return 0;
}

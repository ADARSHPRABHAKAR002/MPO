/*  5. Implement a C program to multiply two integer matrices. The program should take two 
matrices as input from the user and display the result. If the two matrices are not compatible 
for multiplication, output an adequate message to the user.
*/
#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10
// Function to multiply two matrices
void multiplyMatrices(int mat1[MAX_ROWS][MAX_COLS], int rows1, int cols1, int 
mat2[MAX_ROWS][MAX_COLS], int rows2, int cols2) {
 if (cols1 != rows2) {
 printf("Matrices are not compatible for multiplication.\n");
 return;
 }
 int result[MAX_ROWS][MAX_COLS];
 // Initialize result matrix with zeros
 for (int i = 0; i < rows1; i++) {
 for (int j = 0; j < cols2; j++) {
 result[i][j] = 0;
 }
 }
 // Perform matrix multiplication
 for (int i = 0; i < rows1; i++) {
 for (int j = 0; j < cols2; j++) {
 for (int k = 0; k < cols1; k++) {
 result[i][j] += mat1[i][k] * mat2[k][j];
 }
 }
 }
 // Display the result matrix
 printf("Result of matrix multiplication:\n");
 for (int i = 0; i < rows1; i++) {
 for (int j = 0; j < cols2; j++) {
 printf("%d ", result[i][j]);
 }
 printf("\n");
 }
}
int main() {
 int mat1[MAX_ROWS][MAX_COLS], mat2[MAX_ROWS][MAX_COLS];
 int rows1, cols1, rows2, cols2;
 // Input matrix dimensions for the first matrix
 printf("Enter the number of rows and columns of the first matrix: ");
 scanf("%d %d", &rows1, &cols1);
 // Input matrix elements for the first matrix
 printf("Enter the elements of the %dx%d first matrix:\n", rows1, cols1);
 for (int i = 0; i < rows1; i++) {
 for (int j = 0; j < cols1; j++) {
 scanf("%d", &mat1[i][j]);
 }
 }
 // Input matrix dimensions for the second matrix
 printf("Enter the number of rows and columns of the second matrix: ");
 scanf("%d %d", &rows2, &cols2);
 // Input matrix elements for the second matrix
 printf("Enter the elements of the %dx%d second matrix:\n", rows2, cols2);
 for (int i = 0; i < rows2; i++) {
 for (int j = 0; j < cols2; j++) {
 scanf("%d", &mat2[i][j]);
 }
 }
 // Multiply matrices and display result
 multiplyMatrices(mat1, rows1, cols1, mat2, rows2, cols2);
 return 0;
}
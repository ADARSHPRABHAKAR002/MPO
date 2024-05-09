/*
6. Develop a C program to subtract one matrix from another. Make sure they are compatible 
by comparing their rows and columns; give an error message otherwise. The program should 
populate both the matrices with random numbers between 20 and 50, display the matrices 
first and later display the result matrix. How much time does your computation take? 
Convert the code to a function and determine how much time the code takes when your 
function is invoked by your main.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROWS 10
#define MAX_COLS 10
// Function to generate a random number between min and max
int getRandomNumber(int min, int max) {
 return rand() % (max - min + 1) + min;
}
int main() {
 int mat1[MAX_ROWS][MAX_COLS], mat2[MAX_ROWS][MAX_COLS], 
result[MAX_ROWS][MAX_COLS];
 int rows, cols;
 // Seed the random number generator
 srand(time(NULL));
 // Input matrix dimensions
 printf("Enter the number of rows and columns of the matrices: ");
 scanf("%d %d", &rows, &cols);
 // Populate matrices with random numbers between 20 and 50
 for (int i = 0; i < rows; i++) {
 for (int j = 0; j < cols; j++) {
 mat1[i][j] = getRandomNumber(20, 50);
 mat2[i][j] = getRandomNumber(20, 50);
 }
 }
 // Subtract matrices and store the result
 printf("Matrix 1:\n");
 for (int i = 0; i < rows; i++) {
 for (int j = 0; j < cols; j++) {
 printf("%d ", mat1[i][j]);
 }
 printf("\n");
 }
 printf("\nMatrix 2:\n");
 for (int i = 0; i < rows; i++) {
 for (int j = 0; j < cols; j++) {
 printf("%d ", mat2[i][j]);
 }
 printf("\n");
 }
 printf("\nResult:\n");
 for (int i = 0; i < rows; i++) {
 for (int j = 0; j < cols; j++) {
 result[i][j] = mat1[i][j] - mat2[i][j];
 printf("%d ", result[i][j]);
 }
 printf("\n");
 }
 return 0;
}

#include <stdio.h>
#define SIZE 5 

int add_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) { //iterates thru each index regarding the row 
        for (int j = 0; j < SIZE; j++) {  //iterates thru each index regarding the column
            result[i][j] = m1[i][j] + m2[i][j]; // adds matrices together 
        }
    }
    return 0; // indicates sucessesful adding 
}

int multiply_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) { //iterates thru each index regarding the row 
        for (int j = 0; j < SIZE; j++) { //iterates thru each index regarding the column
            result[i][j] = 0; // sets result = 0 
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j]; // multiplies for final result 
            }
        }
    }
    return 0; // indicates sucessful multiplying 
}

int transpose_matrices(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) { //iterates thru each index regarding the row 
        for (int j = 0; j < SIZE; j++) { //iterates thru each index regarding the column
            result[j][i] = matrix[i][j]; // swaps the rows and columns 
        }
    }
    return 0; // sucess creating trnaspose 
}

void print_matrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) { //iterates thru each index regarding the row 
        for (int j = 0; j < SIZE; j++) { //iterates thru each index regarding the column
            printf("%4d ", matrix[i][j]); // prints each element
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int m1[SIZE][SIZE] = { 
        {1, 2, 3,4, 5 },
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    }; // matrix given in rubric 
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    }; // matrix given in rubric 
    int result[SIZE][SIZE]; 
 printf("Matrix 1:\n");
    print_matrix(m1); // prints m1

    printf("Matrix 2:\n");
    print_matrix(m2); // prints m2

    printf("Sum of matrices:\n");
    if (add_matrices(m1, m2, result) == 0) { // calls the add matrices function 
        print_matrix(result); // prints result of sum 
    } else {
        printf("Error in matrix addition\n"); // error handling 
    }

    printf("Product of matrices:\n");
    if (multiply_matrices(m1, m2, result) == 0) {  // calls multiplifcation function 
        print_matrix(result); // prints result of product 
    } else {
        printf("Error in matrix multiplication\n"); // error handling 
    }

    printf("Transpose of Matrix 1:\n");
    if (transpose_matrices(m1, result) == 0) { // calls transpose function 
        print_matrix(result); // prints result of m1 
    } else {
        printf("Error in matrix transposition\n"); // error handling 
    }
 
        printf("Transpose of Matrix 2:\n");
    if (transpose_matrices(m2, result) == 0) { // calls transpose function 
        print_matrix(result); // prints result of m2 
    } else {
        printf("Error in matrix transposition\n"); // error handling 
    }

    return 0; // returns everything 
}
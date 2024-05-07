#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <time.h>
#include <signal.h>

#define SYS_create_spec 458
#define SYS_commit_spec 459
#define SYS_fail_spec 460
#define SYS_move_to_waitqueue 461
#define MATRIX_SIZE 20

void generate_random_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    int value=1;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = value++;  // Random values between 0 and 19
        }
    }
}

void multiply_matrices(int a[MATRIX_SIZE][MATRIX_SIZE], int b[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void print_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    printf("\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d\t", matrix[i][j]);  // Print each matrix element followed by a tab
        }
        printf("\n");  // New line after each row
    }
}

int main() {

    int matrix[MATRIX_SIZE][MATRIX_SIZE], result[MATRIX_SIZE][MATRIX_SIZE];

    generate_random_matrix(matrix);

    multiply_matrices(matrix, matrix, result);
   
    return 0;
}

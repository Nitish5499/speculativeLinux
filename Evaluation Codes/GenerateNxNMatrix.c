#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 30
#define MODULO 1000000007

typedef long long hash_t;

// Function to compute hash of the matrix
hash_t computeMatrixHash(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    hash_t hash = 0;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            hash = (hash * 31 + matrix[i][j]) % MODULO;
        }
    }
    return hash;
}

int main() {
    FILE *file = fopen("matrix.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator

    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    hash_t hash = 0;
    int value=1;
    // Generate and write a 1000x1000 matrix to the file
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            int num = value++; // Random numbers between 0 and 999
            fprintf(file, "%d ", num);
            hash = (hash * 31 + num) % MODULO; // Update hash for each element
        }
        fprintf(file, "\n"); // New line at the end of each row
    }

    // Write the hash value at the end of the file
    fprintf(file, "%lld\n", hash); // Write hash value as a new line

    fclose(file);
    printf("Matrix and hash generated and written to matrix.txt\n");

    return 0;
}

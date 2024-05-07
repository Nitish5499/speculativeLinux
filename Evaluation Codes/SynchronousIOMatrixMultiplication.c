#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 30

typedef struct {
    int data[MATRIX_SIZE][MATRIX_SIZE];
} Matrix;

void readMatrixFromFile(FILE *file, Matrix *m, long long *hash);
void multiplyMatrices(Matrix *a, Matrix *b, Matrix *result);
void printMatrix(Matrix *m);

int main() {
    
    long long hash;
    Matrix matrix, resultMatrix;
    FILE *file = fopen("matrix.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // Read matrix from the file
    readMatrixFromFile(file, &matrix, &hash);
    fclose(file);

    // Measure time taken to square the matrix
    multiplyMatrices(&matrix, &matrix, &resultMatrix);

    // Print the resulting matrix
    printMatrix(&resultMatrix);

    

    

    return 0;
}

void readMatrixFromFile(FILE *file, Matrix *matrix, long long *hash) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (fscanf(file, "%d", &matrix->data[i][j]) != 1) {
                fprintf(stderr, "Error reading matrix from file\n");
                exit(1);
            }
        }
    }

    // Read the hash value from the last line
    if (fscanf(file, "%lld", hash) != 1) {
        fprintf(stderr, "Error reading hash from file\n");
        exit(1);
    }
}


void multiplyMatrices(Matrix *a, Matrix *b, Matrix *result) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
}

void printMatrix(Matrix *m) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%5d ", m->data[i][j]);
        }
        printf("\n");
    }
}

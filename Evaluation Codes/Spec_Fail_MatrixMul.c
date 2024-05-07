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
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = rand() % 20;  // Random values between 0 and 19
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


    int child;
    srand(time(NULL));  // Seed the random number generator

    pid_t parent = getpid();

    pid_t child_pid = syscall(SYS_create_spec);

    //printf("Process %d Child process id %d\n", getpid(), child_pid);

    //sleep(3);
    if (getpid() != parent){
    
            syscall(SYS_move_to_waitqueue);

    }


    multiply_matrices(matrix, matrix, result);
    //printf("Process %d Child process id %d\n", getpid(), child_pid);

    child = child_pid;
    
    if (getpid() == parent)
    {
            printf("\nPrinted from Parent Process%d to fail spec with child %d \n",getpid(), child);                
            int wstatus = 0;

            pid_t val = syscall(SYS_fail_spec, child);
            printf("Process %d fail returned: %d\n", getpid(), val);
           // print_matrix(result);
                
    }
    else 
    {
            printf("Getpid %d was not equal to parent %d", getpid(),parent);
            print_matrix(result);
            printf("\nKilling child process from Child Process %d\n",getpid());
           
    }

    printf("\n before exit %d", getpid());
    printf("\n");
    

    return 0;
}

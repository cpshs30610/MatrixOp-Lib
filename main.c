#include <stdio.h>
#include "matrix_op.h"
// main program for testing matrix operation library
static void print_matrix(Matrix A) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%8.2f ", A[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    Matrix A  = {{1,2,3},{4,5,6},{7,8,10}};
    Matrix B  = {{1,0,0},{0,1,0},{0,0,1}};
    Matrix  R;

    printf("A + B:\n");
    mat_add(A, B, R);
    print_matrix(R);

    printf("\nA - B:\n");
    mat_sub(A, B, R);
    print_matrix ( R);

    printf("\nA element-wise * B:\n");
    mat_elem_mul(A, B, R);
    print_matrix(R);   
  
    printf("\nA * B:\n");
    mat_mul(A, B, R);
    print_matrix(R);   

    printf("\nTranspose(A):\n");
    mat_transpose(A, R);
    print_matrix(R);

    printf("\ndet(A) = %.2f\n", mat_det(A));

    printf("\nInverse(A):\n");
    if (mat_inverse(A, R)) {
        print_matrix(R);
    } else {
        printf("A is not invertible.\n");
    }

    return 0;
}

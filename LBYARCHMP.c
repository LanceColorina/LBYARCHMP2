#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// C version of DAXPY kernel
double DAXPY_C(double a, double x, double y) {
    return (a * x) + y;
}

// Assembly version of DAXPY kernel (x86-64)
extern double DAXPY(double a, double x, double y);

int main() {
    int n, choice;
    double a;

    // Prompt the user to choose the implementation first
    printf("Choose the DAXPY function to use:\n");
    printf("1. C implementation\n");
    printf("2. x86-64 Assembly implementation\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    // Prompt the user for vector size and scalar
    printf("Enter the vector size (n): ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid size. Exiting.\n");
        return 1;
    }

    printf("Enter the scalar value (a): ");
    scanf("%lf", &a);

    // Allocate memory for vectors
    double *x = (double *)malloc(n * sizeof(double));
    double *y = (double *)malloc(n * sizeof(double));
    double *z = (double *)malloc(n * sizeof(double));
    if (!x || !y || !z) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    // Populate arrays
    for (int i = 0; i < n; i++) {
        x[i] = (double)(i + 1);         // x contains floats from 1 to n
        y[i] = x[i] + 10.00;           // y contains floats from 11 to (n + 10)
    }

    // Time the kernel execution
    time_t start, end;
    start = time(NULL);
    if (choice == 1) {
        // Use C implementation
        for (int i = 0; i < n; i++) {
            z[i] = DAXPY_C(a, x[i], y[i]);
        }
    } else {
        // Use Assembly implementation
        for (int i = 0; i < n; i++) {
            z[i] = DAXPY(a, x[i], y[i]);
        }
    }
    end = time(NULL);

    // Print execution time
    printf("Time taken to populate vector z is %.2f seconds\n", difftime(end, start));

    // Print the first 10 elements of z
    printf("Z array is: ");
    for (int j = 0; j < 10 && j < n; j++) {
        printf("%.2f ", z[j]);
    }
    printf("\n");

    // Free allocated memory
    free(x);
    free(y);
    free(z);

    return 0;
}

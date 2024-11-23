#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern double DAXPY(double a, double x, double y);

int main() {
    int n;
	double a;  
    printf("Enter a Size: ");
    scanf("%d", &n);  
	printf("Enter a Scalar: ");
    scanf("%lf", &a);
    
    if (n <= 0) {
        printf("Invalid size. Exiting.\n");
        return 1; 
    }

    double *x = (double *)malloc(n * sizeof(double));
    double *y = (double *)malloc(n * sizeof(double));
    double *z = (double *)malloc(n * sizeof(double)); 
	int i;
	int j;
	
    // Populate arrays
    for (i = 0; i < n; i++) {
        x[i] = (double)(i + 1);         // x contains floats from 1 to n
        y[i] = x[i] + 10.00;           // y contains floats from 10*n to 10*(n+1)
    }
    
	i = 0;
	time_t start, end;
    start = time(NULL);
	for(i=0; i < n;i++){
		z[i] = DAXPY(a,x[i],y[i]);
	}
	end = time(NULL);
	printf("Time taken to populate vector z is %.2f seconds",difftime(end, start));
    // Print the first array
    printf("\n");
	
	printf("Z array is: ");
    for (j = 0; j < 10; j++) {
        printf("%.2f ", z[j]);
    }
    return 0;
}



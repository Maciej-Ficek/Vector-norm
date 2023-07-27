#include <stdio.h>
#include <stdlib.h>
#include "program2.h"

double* generate_vector(int m, int r){
    double* x = malloc(m * sizeof(double));
    if (x == NULL){
        printf("Memory badly allocated.\n");
        return NULL;
    }
    if (r == 1){
        for (int i = 0; i < m; i++){
          x[i] = (double)rand() / RAND_MAX;
        }
    }
    return x;
}

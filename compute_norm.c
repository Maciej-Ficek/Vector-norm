#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "program2.h"
#include <omp.h>
#include <mpi.h>

void compute_norm(double* x, MPI_Comm communicator){
    int rank, size;
    MPI_Comm_size(communicator, &size);
    MPI_Comm_rank(communicator, &rank);
    double start_time = MPI_Wtime();
    double norm = 0;

    if (rank == 0){
    double* element = x;
    double sum = 0;
    for (;;){
        sum += *element * *element;
        element++;
        if (element == &x[N/size - 1]){
            break;
        }
    }
    norm += sum;
}
    if (rank != 0){
    double* element = &x[(rank*N)/size];
    double sum = 0;
    for (;;){
        sum += *element * *element;
        element++;
        if (element == &x[((rank+1)*N)/size - 1]){
            break;
        }
    }
    norm += sum;
}
    double total_norm;
    // we need to assure all threads finished before reducing
    MPI_Barrier(communicator);
    // sum all partial results
    MPI_Reduce(&norm, &total_norm, 1, MPI_DOUBLE, MPI_SUM, 0, communicator);
    if (rank == 0){
        total_norm = sqrt(total_norm);
        printf("Norm: %f\n", total_norm);
        double end_time = MPI_Wtime();
        printf("Working time: %f\n", end_time - start_time);
    }
}

#ifndef PROGRAM2_H
#define PROGRAM2_H

#include <mpi.h>

#define N 1024

double* generate_vector(int, int);

void compute_norm(double*, MPI_Comm);

#endif
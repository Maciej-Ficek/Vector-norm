#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "program2.h"

int main(int argc, char** argv){
    MPI_Init(&argc, &argv);
    srand(time(NULL));
    MPI_Comm communicator = MPI_COMM_WORLD;
    double* x = generate_vector(N, 1);
    compute_norm(x, communicator);
    MPI_Finalize();
    free(x);
    return 0;
}

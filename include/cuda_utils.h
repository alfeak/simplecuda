#include <cuda_runtime.h>
#include <stdio.h>

#define CUDA_CHECK(call)
{
    const cudaError_t err = call;
    if (err != cudaSuccess)
    {   
        printf("Error: %s %d \n", __FILE__, __LINE__);
        printf(stderr, "CUDA Error: %s\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
}

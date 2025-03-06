#include <stdio.h>

__global__ void hello_world() {
    printf("hello world from gpu. \n");
}
int main() {
    hello_world<<<1, 5>>>();
    cudaDeviceSynchronize();
    
    return 0;
}
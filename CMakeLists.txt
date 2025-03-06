cmake_minimum_required(VERSION 3.10)
project(simple_cuda LANGUAGES  CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# cuda setup for jetson
find_package(CUDA REQUIRED)
message("-- CUDA version: ${CUDA_VERSION}")
message("-- CUDA INC PATH: ${CUDA_INCLUDE_DIRS}")
message("-- CUDA LIB PATH: ${CUDA_LIBRARIES}")
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS}; -O3)
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS}; -gencode arch=compute_87,code=sm_87)
set(CMAKE_CUDA_ARCHITECTURES 87)

include_directories(${CUDA_INCLUDE_DIRS})

include_directories(include)
file(GLOB SOURCES "src/*.cpp" "src/*.cu" )

add_executable(simple_cuda ${SOURCES})

target_link_libraries(simple_cuda ${CUDA_LIBRARIES})
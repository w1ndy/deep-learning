cmake_minimum_required (VERSION 3.1)
project (DeepLearning)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 11)

include_directories (include)

set (NEURON_LIB_SOURCES
    src/neuron/neuron.cpp)
add_library (neuron STATIC ${NEURON_LIB_SOURCES})

set (NEURON_EXAMPLE_SOURCES
    examples/example-neuron.cpp)
add_executable (example_neuron ${NEURON_EXAMPLE_SOURCES})
target_link_libraries (example_neuron neuron)

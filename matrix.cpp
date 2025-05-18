#include "matrix.hpp"

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:

Matrix::Matrix(size_t N) : matrix(N, std::vector<int>(N,0)) {
    // initialize an empty NxN matrix
   
    
}

// e.g. for a member function:

void Matrix::print_matrix() const {
    // print out the matrix
    for(const auto& row : matrix){
        for(const auto& element : row){
            std::cout << element << " ";
        }
        std::cout << '\n';
    }
    

}
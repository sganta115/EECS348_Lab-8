#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>
#include <cstdint>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int> > matrix;

public:
    Matrix(std::size_t N); //empty matrix constructor
    Matrix(std::vector<std::vector<int>> nums); //matrix with values constructor

    Matrix operator+(const Matrix &rhs) const; //addition operator
    Matrix operator*(const Matrix &rhs) const; //multiplication operator
    void set_value(std::size_t i, std::size_t j, int n); 
    int get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const;
    

};


std::pair<Matrix,Matrix> create_matrices(std::string file_name);

#endif // __MATRIX_HPP__
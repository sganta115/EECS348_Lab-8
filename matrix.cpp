#include "matrix.hpp"
#include <fstream>




Matrix::Matrix(size_t N) : matrix(N, std::vector<int>(N,0)) {
    // initializes member variable matrix with N vectors consisting of N 0's
   
    
}
Matrix::Matrix(std::vector<std::vector<int>> nums) : matrix(nums){ //initializes member variable matrix with given "nums" matrix
    
}

//addition overloading operator
Matrix Matrix::operator+(const Matrix &rhs) const{
    Matrix result(matrix.size());
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        }
}
    return result;
}

//multiplication overloading operator
Matrix Matrix::operator*(const Matrix &rhs) const{
    size_t N = matrix.size();
    Matrix result(matrix.size());
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            for(size_t k = 0; k < N; k++){
                result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
            }
        }
}
    return result;

}

//sets matrix element to given parameter
void Matrix::set_value(std::size_t i, std::size_t j, int n){
   matrix[i][j] = n;

}

//returns matrix element at given indices
int Matrix::get_value(std::size_t i, std::size_t j) const {

    return matrix[i][j];
}

//gets size of matrix
int Matrix::get_size() const{
    return matrix.size();

}


//sums the major diagonal elemnts (top left to bottom right)
int Matrix::sum_diagonal_major() const{ //main diagonal
    int sum =0;
    int size = matrix.size();

    for(int i = 0; i < size; i++){ //iterates through the matrix and gets the diagonal element
        sum += matrix[i][i];

    }
    return sum;
    

}

//sums the minor diagonal elemnts (top right to bottom left)

int Matrix::sum_diagonal_minor() const{
    int sum =0;
    int size = matrix.size();

    for(int i = 0; i < size; i++){//iteratoes through the matrix and gets the diagonal element
        sum += matrix[i][size-1-i];

    }
    return sum;
    


}

//swaps rows within a given matrix
void Matrix::swap_rows(std::size_t r1, std::size_t r2){
    if (r1 >= matrix.size() || r2 >= matrix.size()){ //makes sure parameters are within bounds
        throw std::out_of_range("Not within bounds");
    }

    std::vector<int> temp = matrix[r1]; //creates a temp variable that stores a vector
    matrix[r1] = matrix[r2]; //swaps the rows
    matrix[r2] = temp;



}

//swaps columns in a matrix
void Matrix::swap_cols(std::size_t c1, std::size_t c2){
    if (c1 >= matrix.size() || c2 >= matrix.size()){ //makes sure parameters are valid
        throw std::out_of_range("Not within bounds");

    }

    for(auto& row : matrix){ //iterates through each row in the matrix by reference
        int temp = row[c1]; //swaps the individual elements in each row
        row[c1] = row[c2];
        row[c2] = temp;


    }

    




}








void Matrix::print_matrix() const {
    // print out the matrix
    for(const auto& row : matrix){//iterates through each row in the matrix my reference
        for(const auto& element : row){//iterates through each element in each row
            std::cout << element << " "; //prints out the element
        }
        std::cout << '\n';//adds a new line after each row
    }
    

}

std::pair<Matrix,Matrix> create_matrices(std::string file_name){
    //read from file and get 2 matrices
    std::ifstream file(file_name);
    std::size_t N;
    file >> N;

    std::vector<std::vector<int>> matrixData1(N, std::vector<int>(N));
    std::vector<std::vector<int>> matrixData2(N, std::vector<int>(N));

    for (std::size_t i = 0; i < N; i++){
        for(std::size_t j = 0; j < N; j++){

            file >> matrixData1[i][j];
        }
    }

    for (std::size_t i = 0; i < N; i++){
        for(std::size_t j = 0; j < N; j++){

            file >> matrixData2[i][j];
        }
    }

    Matrix matrix1(matrixData1);
    Matrix matrix2(matrixData2);

    return {matrix1,matrix2};



}
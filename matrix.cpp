#include <vector> 
#include "matrix.h"
#include <iostream>
#include <limits.h>
#include <iomanip>

Matrix::Matrix(int rows, int cols): _rows(rows) ,_cols(cols) {
    if(rows > INT_MAX || cols > INT_MAX){std::cerr << "Error\n";}
    mat.resize(rows, std::vector<double>(cols, 0.0));

}

int Matrix::set_index(int row, int col, double value){
    if(row < 0 || row > _rows || col < 0 || col > _cols){std::cout << "Error" << std::endl; return 0;}
    mat[row][col] = value;
    return 1;
}

double Matrix::get_index(int row, int col) const{
    return mat[row][col];
}


bool Matrix::is_square(){
    if(_rows != _cols){return false;}
    return true;

}

int Matrix::get_row() const{
    return _rows;
}


int Matrix::get_col() const{
    return _cols;
}

int Matrix::size() const{
    return mat.size();
}

void Matrix::display() const{
    std::cout << "\n";
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                std::cout << std::setw(8) << mat[i][j]; // Adjust the width as needed
            }
            std::cout << std::endl;
        }
}


void add(const Matrix &mat1, const Matrix &mat2){
    if(mat1.get_row() != mat2.get_row() || mat1.get_col() != mat2.get_col()){std::cerr << "Error" << std::endl;}
    Matrix add_mat(mat1.get_row(), mat1.get_col());

    for(int i = 0; i < mat1.get_row(); i++){
        for(int j = 0; j < mat1.get_col(); j++){
            double value = mat1.get_index(i,j) + mat2.get_index(i,j);
            add_mat.set_index(i,j,value);
        }
    }

    add_mat.display();

}
 


void subtract(const Matrix &mat1, const Matrix &mat2){
    if(mat1.get_row() != mat2.get_row() || mat1.get_col() != mat2.get_col()){std::cerr << "Error" << std::endl;}
    Matrix sub_mat(mat1.get_row(), mat1.get_col());

    for(int i = 0; i < mat1.get_row(); i++){
        for(int j = 0; j < mat1.get_col(); j++){
            double value = mat1.get_index(i,j) - mat2.get_index(i,j);
            sub_mat.set_index(i,j,value);
        }
    }

    sub_mat.display();
}
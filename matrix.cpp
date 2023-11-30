#include <vector> 
#include "matrix.h"
#include <iostream>
#include <limits.h>
#include <iomanip>
#include <string>
#include <memory>
#include "back.h"
#include <cmath>

Matrix::Matrix(int rows, int cols): _rows(rows) ,_cols(cols) {
    if(rows > INT_MAX || cols > INT_MAX){std::cerr << "Error\n";}
    mat.resize(rows, std::vector<double>(cols, 0.0));

}

Matrix::Matrix(){
    mat.resize(0, std::vector<double>(0, 0.0));
}

int Matrix::set_index(int row, int col, double value){
    if(row < 0 || row > _rows || col < 0 || col > _cols){std::cout << "Error" << std::endl; return 0;}
    mat[row][col] = value;
    return 1;
}

int Matrix::add_index(int row, int col, double value){
    if(row < 0 || row > _rows || col < 0 || col > _cols){std::cout << "Error" << std::endl; return 0;}
    mat[row][col] += value;
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

void matrix_save(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map, const Matrix &mat){
    bool flag = false;
    std::string mat_name;
    do{
    std::cout << "\nEnter a Matrix name (This will include all characters entered including white spaces)\n";
    std::cin.ignore();
    std::getline(std::cin, mat_name);
    flag = map_check(mat_name, map);
  }
  while(flag);
  //Asks the same of the user for a unique matrix name
    //Adds matrix to our map
  (*map)[mat_name] = mat;  

}


void add(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map){
    Matrix mat1, mat2;
    bool found_flag1 = false;
    bool found_flag2 = false;
    do{
        mat1 = select(map, found_flag1);
        mat2 = select(map, found_flag2);
    }
    while(!found_flag1 || !found_flag2);
    //Will not allow function to carry on until 2 valid matrices are found
    
    if(mat1.get_row() != mat2.get_row() || mat1.get_col() != mat2.get_col()){std::cerr << "Error Matrices are not same size" << std::endl; return;}
    Matrix add_mat(mat1.get_row(), mat1.get_col());
    //Checks is matrices are the same size and initalises a new matrix object

    for(int i = 0; i < mat1.get_row(); i++){
        for(int j = 0; j < mat1.get_col(); j++){
            double value = mat1.get_index(i,j) + mat2.get_index(i,j);
            add_mat.set_index(i,j,value);
        }
    }
    //Adds each index together and set it in another matrix

    add_mat.display();

    bool save_flag = false;
    do{
        std::string choice;
        std::cout << "\nWould you like to save this matrix (Y/N)";
        std::cin >> choice;
        if(choice == "N"){save_flag = true;}
        if(choice == "Y"){matrix_save(map, add_mat); save_flag = true;}
    }
    while(!save_flag);
    //Asks the user if they want to save the matrix as a new matrix to use for further calculations


}
 


void subtract(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map){
    Matrix mat1, mat2;
    bool found_flag1 = false;
    bool found_flag2 = false;
    do{
        mat1 = select(map, found_flag1);
        mat2 = select(map, found_flag2);
    }
    while(!found_flag1 || !found_flag2);

    if(mat1.get_row() != mat2.get_row() || mat1.get_col() != mat2.get_col()){std::cerr << "Error Matrices are not the same size" << std::endl; return;}
    Matrix sub_mat(mat1.get_row(), mat1.get_col());

    for(int i = 0; i < mat1.get_row(); i++){
        for(int j = 0; j < mat1.get_col(); j++){
            double value = mat1.get_index(i,j) - mat2.get_index(i,j);
            sub_mat.set_index(i,j,value);
        }
    }

    sub_mat.display();
    bool save_flag = false;
    do{
        std::string choice;
        std::cout << "\nWould you like to save this matrix (Y/N)";
        std::cin >> choice;
        if(choice == "N"){save_flag = true;}
        if(choice == "Y"){matrix_save(map, sub_mat); save_flag = true;}
    }
    while(!save_flag);
}

//Takes a string from the user and returns an empty object if not found else return matrix 
Matrix select(const std::shared_ptr<std::unordered_map<std::string, Matrix>> &map, bool &found_flag){ 
    std::string selection;
    std::cout << "Enter the name of your matrix" << std::endl;
    std::getline(std::cin >> std::ws, selection);
    auto got = map->find(selection);
    if(got == map->end()){found_flag = false; return Matrix();}
    found_flag = true;  
    return (*map)[selection];

}

void Matrix::swapRows(int row1, int row2) {
    if (row1 != row2 && row1 >= 0 && row2 >= 0 && row1 < _rows && row2 < _rows) {std::swap(mat[row1], mat[row2]); return;} 
    err("Invalid row indices for swapping.");

}


//Calculates determinant based on gaussian elimination
void determinant(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map) {
    bool found_flag = false;
    bool square_flag = false;
    Matrix mat;

    do{
        mat = select(map, found_flag);
        square_flag = mat.is_square();

    } 
    while (!found_flag || !square_flag);

    int n = mat.size();
    int counter = 0;

    for (int col = 0; col < n; col++) {
        int pivotRow = col;

        // Find the row with the maximum value in the current column
        for (int row = col + 1; row < n; row++) {if (std::abs(mat.get_index(row, col)) > std::abs(mat.get_index(pivotRow, col))) {pivotRow = row;}}

        // Check if the pivot element is close to zero
        if (std::abs(mat.get_index(pivotRow, col)) < 1e-10) {std::cout << "Matrix is very close to being singular/ is singular" << std::endl;}

        // Swap the rows if needed
        if (pivotRow != col) {mat.swapRows(col, pivotRow);counter++;}

        // Elimination
        for (int current_row = col + 1; current_row < n; current_row++) {
            if (std::abs(mat.get_index(current_row, col)) < 1e-10) {continue;}
            double factor = mat.get_index(current_row, col) / mat.get_index(col, col);
            for (int j = col; j < n; j++) {
                double temp = mat.get_index(current_row, j);
                temp -= factor * mat.get_index(col, j);
                mat.set_index(current_row, j, temp);
            }
        }
    }

    mat.display();
    double det = 1.0;
    for (int i = 0; i < n; i++) {
        det *= mat.get_index(i, i);
    }

    det = det * pow(-1,counter);

    std::cout << "\nThe Determinant of this matrix is: " << det << std::endl;
}





    


    
      







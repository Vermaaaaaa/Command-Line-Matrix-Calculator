#include <vector> 
#include "matrix.h"
#include <iostream>
#include <limits.h>

Matrix::Matrix(int rows, int cols, int choice) : _rows(rows) ,_cols(cols) {
    if(rows > INT_MAX || cols > INT_MAX || choice > 3 || choice < 0){std::cerr << "Error\n";}

    switch(choice){
        case 0:{mat.resize(rows, std::vector<int>(cols, 0)); break;} // Empty Matrix
        case 1:{mat.resize(rows, std::vector<int>(cols, 1)); break;} // Unit Matrix
        case 2:{
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (i == j) {
                        mat[i][j] = 1; // Diagonal elements
                    } 
                    else {
                        mat[i][j] = 0; // Off-diagonal elements
                    }   
                }
            }
            break;

        } // Diagonal Matrix 

        case 3:{
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    set_index(i,j,1);
                }
            }


            break;
        } // Write in your own matrix

    }

}

void Matrix::set_index(int row, int col, int value){
    mat[row][col] = value;
}



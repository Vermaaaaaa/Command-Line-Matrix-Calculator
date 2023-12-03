
#include "matrix.h"
#include <iostream>
#include <cassert>






Matrix add2(const Matrix &mat1, const Matrix &mat2){
    Matrix mat;

    
    if(mat1.get_row() != mat2.get_row() || mat1.get_col() != mat2.get_col()){
        std::cerr << "Error Matrices are not same size" << std::endl; 
        return mat;
        }
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
    return add_mat;


}
 


Matrix subtract2(const Matrix &mat1, const Matrix &mat2){
    if(mat1.get_row() != mat2.get_row() || mat1.get_col() != mat2.get_col()){std::cerr << "Error Matrices are not the same size" << std::endl; return Matrix();}
    Matrix sub_mat(mat1.get_row(), mat1.get_col());

    for(int i = 0; i < mat1.get_row(); i++){
        for(int j = 0; j < mat1.get_col(); j++){
            double value = mat1.get_index(i,j) - mat2.get_index(i,j);
            sub_mat.set_index(i,j,value);
        }
    }

    sub_mat.display();
    return sub_mat;
}



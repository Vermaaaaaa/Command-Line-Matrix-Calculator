
#include "matrix.h"
#include <iostream>
#include <cassert>






Matrix add2(const Matrix &mat1, const Matrix &mat2){
    Matrix mat;

    
    if(mat1.get_row() != mat2.get_row() || mat1.get_col() != mat2.get_col()){ //ensures matricies are of the same size 
        std::cerr << "Error Matrices are not same size" << std::endl; //output error to console if not equal
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
    if(mat1.get_row() != mat2.get_row() || mat1.get_col() != mat2.get_col()){std::cerr << "Error Matrices are not the same size" << std::endl; return Matrix();} //ensures the maxtricies are of the same size
    Matrix sub_mat(mat1.get_row(), mat1.get_col()); //Checks is matrices are the same size and initalises a new matrix object

    for(int i = 0; i < mat1.get_row(); i++){
        for(int j = 0; j < mat1.get_col(); j++){
            double value = mat1.get_index(i,j) - mat2.get_index(i,j); //subtracts each index for the matrices one at a time
            sub_mat.set_index(i,j,value); //saves the index subtraction into the relevent loacation in the output matrix 
        }
    }

    sub_mat.display(); //displays the output matrix after subtraction
    return sub_mat;
}



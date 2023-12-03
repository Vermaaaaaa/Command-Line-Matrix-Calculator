#include <cassert>
#include "matrix.h"
#include <iostream>

Matrix add2(const Matrix &mat1, const Matrix &mat2){ 
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

    return add_mat;


    
    
}




int main(){
    Matrix mat1(2,2), mat2(2,2), mat3(2,2);



    

    mat1.set_index(0,0,2);
    mat1.set_index(0,1,4);
    mat1.set_index(1,0,6);
    mat1.set_index(1,1,8);

    
    mat2.set_index(0,0,3);
    mat2.set_index(0,1,4);
    mat2.set_index(1,0,6);
    mat2.set_index(1,1,5);

    mat3 = add2(mat1,mat2);

    assert(mat3.get_index(0, 0) == 5);
    assert(mat3.get_index(0, 1) == 8);
    assert(mat3.get_index(1, 0) == 12);
    assert(mat3.get_index(1, 1) == 13);

    // If any of these assertions fail, the program will terminate with an error.

    // Additional checks, you might want to verify the size of the matrices.
    assert(mat3.get_row() == 2);
    assert(mat3.get_col() == 2);

    return 0;



   

    

    


}
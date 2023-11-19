#include "matrix.h"
#include <iostream>

int main(){
    Matrix mat1(2,2);
    Matrix mat2(2,2);

    mat1.set_index(0,0,10);
    mat1.set_index(0,1,5);
    mat1.set_index(1,0,1);
    mat1.set_index(1,1,3);

    mat2.set_index(0,0,10);
    mat2.set_index(0,1,15);
    mat2.set_index(1,0,5.6);
    mat2.set_index(1,1,5.7);


    mat1.display();
    mat2.display();

    add(mat1, mat2);
    subtract(mat1, mat2);


    

    




}
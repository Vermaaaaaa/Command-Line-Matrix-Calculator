#include <cassert>
#include "matrix.h"
#include <iostream> 
#include "arithmetic.h"






int main(){
    Matrix mat1(2,2);

    mat1.set_index(0,0,2);
    mat1.set_index(0,1,4);
    mat1.set_index(1,0,6);

    assert(mat1.is_square() == true);

    std::cout << "test passed" << std::endl;


    return 0;



}

#include <cassert>
#include "matrix.h"
#include <iostream> 
#include "arithmetic.h"






int main(){

    Matrix mat1(2,2), mat2(2,2);

    mat1.display();

    mat1.set_index(0,0,2);
    mat1.set_index(0,1,4);
    mat1.set_index(1,0,6);
    mat1.set_index(1,1,8);

    mat1.display();

    assert(mat1.get_index(0, 0) == 2);
    assert(mat1.get_index(0, 1) == 4);
    assert(mat1.get_index(1, 0) == 6);
    assert(mat1.get_index(1, 1) == 8);

    mat1.swap_rows(0,1);
    mat1.display();

    assert(mat1.is_square() == true);
    assert(mat1.get_col() ==2);
    assert(mat1.get_row() ==2);
    assert(mat1.size() ==2);

    std::cout << "All tests passed" << std::endl;

    return 0;
}